#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>
#include "Meal.h"

class Database {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* connection;

public:
    Database(const std::string& server, const std::string& username, const std::string& password);
    ~Database();
    bool insertMeal (const Meal&, int userId);
};