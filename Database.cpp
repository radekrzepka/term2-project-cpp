#define _CRT_SECURE_NO_WARNINGS

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

#include "Database.h"
#include "Data.h"
#include "Frames.h"
#include "Meal.h"

#include <iostream>
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/tglbtn.h>

Database::Database(const std::string& server, const std::string& username, const std::string& password) {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        connection = driver->connect(server, username, password);
    }
    catch (sql::SQLException& e) {
        wxString error = wxString("Error when connecting to the database. The application will now terminate.");
        wxMessageBox(error, "Error", wxOK | wxICON_ERROR);
        wxTheApp->Exit();
    }
}

Database::~Database() {
    delete connection;
}

bool Database::insertMeal(const Meal& meal,const int userId) {
    try {
        connection->setSchema("term2-project-cpp");

        sql::PreparedStatement* preparedStatement = connection->prepareStatement("INSERT INTO `meals` (`name`, `day`, `type`, `calories`, `carbohydrates`, `proteins`, `fats`, `user_id`) VALUES (?,?,?,?,?,?,?,?)");

        preparedStatement->setString(1, meal.name.ToStdString());
        wxString formattedDate = meal.date.Format("%Y-%m-%d");

        preparedStatement->setString(2, formattedDate.ToStdString());

        switch (meal.type) {
        case 0:
            preparedStatement->setString(3, "breakfast");
            break;
        case 1:
            preparedStatement->setString(3, "snack I");
            break;
        case 2:
            preparedStatement->setString(3, "lunch");
            break;
        case 3:
            preparedStatement->setString(3, "snack II");
            break;
        case 4:
            preparedStatement->setString(3, "dinner");
            break;
        }

        preparedStatement->setInt(4, meal.kcal);
        preparedStatement->setInt(5, meal.carbs);
        preparedStatement->setInt(6, meal.protein);
        preparedStatement->setInt(7, meal.fat);
        preparedStatement->setInt(8, userId);

        preparedStatement->execute();
        delete preparedStatement;
        return true;
    }
    catch (sql::SQLException& e) {
        wxString error = wxString::Format(e.what()); 
        wxMessageBox(error);
        return false;
    }
}

bool Database::updateUserData(const Data& data,const int userId)
{
    try {
        connection->setSchema("term2-project-cpp");

        sql::PreparedStatement* preparedStatement = connection->prepareStatement("UPDATE `users` SET `sex` = ?,`height` = ?,`weight` = ?,`target` = ?,`age` = ?,`activity` = ?,`calorie_target` = ?, `carbs_target` = ?, `proteins_target` = ?, `fats_target` = ? WHERE `id` = ?"); 

        switch (data.sex) {
        case 0:
            preparedStatement->setString(1, "male");
            break;
        case 1:
            preparedStatement->setString(1, "female");
            break;
        }

        preparedStatement->setInt(2, data.height);
        preparedStatement->setInt(3, data.weight);

        switch (data.target) {
        case 0:
            preparedStatement->setString(4, "lose");
            break;
        case 1:
            preparedStatement->setString(4, "mantain");
            break;
        case 2:
            preparedStatement->setString(4, "gain");
            break;
        }

        preparedStatement->setInt(5, data.age);

        switch (data.activity) {
        case 0:
            preparedStatement->setString(6, "low");
            break;
        case 1:
            preparedStatement->setString(6, "medium");
            break;
        case 2:
            preparedStatement->setString(6, "high");
            break;
        }

        preparedStatement->setInt(7, data.usertargets.caloriesTarget);
        preparedStatement->setInt(8, data.usertargets.carbsTarget);
        preparedStatement->setInt(9, data.usertargets.proteinsTarget);
        preparedStatement->setInt(10, data.usertargets.fatsTarget);
        preparedStatement->setInt(11, userId);

        preparedStatement->execute();
        delete preparedStatement;
        return true;
    }
    catch (sql::SQLException& e) {
        wxString error = wxString::Format(e.what());
        wxMessageBox(error);
        return false;
    }
}

std::vector<Meal> Database::getMealsByDate(const std::string& date, const int userId) {
    std::vector<Meal> meals;

    try {
        connection->setSchema("term2-project-cpp");

        sql::PreparedStatement* preparedStatement = connection->prepareStatement("SELECT * FROM `meals` WHERE `day` = ? AND `user_id` = ?");
        preparedStatement->setString(1, date);
        preparedStatement->setInt(2, userId);

        sql::ResultSet* resultSet = preparedStatement->executeQuery();

        while (resultSet->next()) {
            Meal meal;
            meal.name = wxString(resultSet->getString("name").c_str(), wxConvUTF8);
            meal.date = wxDateTime::Now();
            meal.date.ParseDate(resultSet->getString("day").c_str());
            meal.typeString = resultSet->getString("type");

            meal.kcal = resultSet->getInt("calories");
            meal.carbs = resultSet->getInt("carbohydrates");
            meal.protein = resultSet->getInt("proteins");
            meal.fat = resultSet->getInt("fats");

            meals.push_back(meal);
        }

        delete resultSet;
        delete preparedStatement;
    }
    catch (sql::SQLException& e) {
        wxString error = wxString::Format(e.what());
        wxMessageBox(error);
    }

    return meals;
}

UserTargets Database::getUserTargets(const int userId)
{
    UserTargets userTargets;

    try {
        connection->setSchema("term2-project-cpp");

        sql::PreparedStatement* preparedStatement = connection->prepareStatement("SELECT * FROM `users` WHERE `id` = ?");
        preparedStatement->setInt(1, userId);

        sql::ResultSet* resultSet = preparedStatement->executeQuery();

        while (resultSet->next()) {
            userTargets.caloriesTarget = resultSet->getInt("calorie_target");
            userTargets.carbsTarget = resultSet->getInt("carbs_target");
            userTargets.proteinsTarget = resultSet->getInt("proteins_target");
            userTargets.fatsTarget = resultSet->getInt("fats_target");
        }

        delete resultSet;
        delete preparedStatement;
    }
    catch (sql::SQLException& e) {
        wxString error = wxString::Format(e.what());
        wxMessageBox(error);
    }

    return userTargets;
}

bool Database::checkIfNameInDb(const std::string& name)
{
    bool userInDb = false;

    try {
        connection->setSchema("term2-project-cpp");

        sql::PreparedStatement* preparedStatement = connection->prepareStatement("SELECT * FROM `users` WHERE `name` = ?");
        preparedStatement->setString(1, name);

        sql::ResultSet* resultSet = preparedStatement->executeQuery();

        while (resultSet->next()) {
            userInDb = true;
        }

        delete resultSet;
        delete preparedStatement;
    }
    catch (sql::SQLException& e) {
        wxString error = wxString::Format(e.what());
        wxMessageBox(error);
    }

    return userInDb;
}

bool Database::insertUser(const std::string& name, const std::string& password)
{
    try {
        connection->setSchema("term2-project-cpp");

        sql::PreparedStatement* preparedStatement = connection->prepareStatement("INSERT INTO `users`(`name`, `password`) VALUES (?,?)");

        preparedStatement->setString(1,name);
        preparedStatement->setString(2,password);
        
        preparedStatement->execute();
        delete preparedStatement;
        return true;
    }
    catch (sql::SQLException& e) {
        wxString error = wxString::Format(e.what());
        wxMessageBox(error);
        return false;
    }
}
