#define _CRT_SECURE_NO_WARNINGS 

#include "App.h"
#include "Frames.h"
#include "Data.h"
#include "Database.h"
#include "UserId.h"

#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/tglbtn.h>

DataFrame::DataFrame(const wxString& title, bool dataCreated) : wxFrame(nullptr, wxID_ANY, title) { //konstruktor frame'u z danymi
	db = new Database("127.0.0.1", "root", "");
	wxPanel* dataFramePanel = new wxPanel(this, wxID_ANY); // panel

	Data userData = db->getUserData(UserId);
	
	wxStaticText* inputWeightText = new wxStaticText(dataFramePanel, wxID_ANY, "Weight (kg):", wxPoint(10, 50)); //text
	wxStaticText* inputHeightText = new wxStaticText(dataFramePanel, wxID_ANY, "Height (cm):", wxPoint(10, 75));
	wxStaticText* inputAgeText = new wxStaticText(dataFramePanel, wxID_ANY, "Age:", wxPoint(10, 100));
	wxStaticText* chooseSexText = new wxStaticText(dataFramePanel, wxID_ANY, "Sex:", wxPoint(10, 128));
	wxStaticText* chooseTargetText = new wxStaticText(dataFramePanel, wxID_ANY, "Target:", wxPoint(10, 153));
	wxStaticText* chooseActivityText = new wxStaticText(dataFramePanel, wxID_ANY, "Activity:", wxPoint(10, 181));

	weightSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, userData.weight != 0 ? std::to_string(userData.weight) : "", wxPoint(85, 45), wxSize(100, -1)); //spinctrl dla wagi i wzrostu
	weightSpinCtrl->SetRange(30, 150);

	heightSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, userData.height != 0 ? std::to_string(userData.height) : "", wxPoint(85, 70), wxSize(100, -1)); // kontrolka wprowadzenia wzrostu 
	heightSpinCtrl->SetRange(140, 210);

	ageSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, userData.age != 0 ? std::to_string(userData.age) : "", wxPoint(85, 95), wxSize(100, -1));
	ageSpinCtrl->SetRange(10, 99);

	wxArrayString sexChoices;
	sexChoices.Add("male");
	sexChoices.Add("female");
	sexRadioBox = new wxRadioBox(dataFramePanel, wxID_ANY, "", wxPoint(75, 110), wxSize(0, 0), sexChoices); // kontrolka wyboru plci 

	wxArrayString targetChoices;
	targetChoices.Add("lose weight");
	targetChoices.Add("maintain weight"); //radiobox dla celu
	targetChoices.Add("gain weight");
	targetRadioBox = new wxRadioBox(dataFramePanel, wxID_ANY, "", wxPoint(75, 135), wxSize(0, 0), targetChoices);

	wxArrayString activityChoices;
	activityChoices.Add("low");
	activityChoices.Add("average"); //radiobox dla aktywnosci fizyrcznej
	activityChoices.Add("high");
	activityRadioBox = new wxRadioBox(dataFramePanel, wxID_ANY, "", wxPoint(75, 160), wxSize(0, 0), activityChoices);

	wxButton* calculateButton = new wxButton(dataFramePanel, wxID_ANY, "Set data", wxPoint(10, 205), wxSize(75, 30));

	if (dataCreated) {
		wxButton* returnButton = new wxButton(dataFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30)); //button powrotu
		returnButton->Bind(wxEVT_BUTTON, &DataFrame::OnReturnButtonClick, this); //bindy buttonow
	}
	else {
		wxString message = wxString("As it is your first time using our apliaction, please enter your data.");
		wxMessageBox(message);
	}
		
	calculateButton->Bind(wxEVT_BUTTON, &DataFrame::OnCalculateButtonClick, this);

	this->SetDisplay();
}

void DataFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}

void DataFrame::Calculate() { // metoda obliczajaca zapotrzebowanie 
	data = new Data();

	data->weight = weightSpinCtrl->GetValue(); //odczytanie wagi
	data->height = heightSpinCtrl->GetValue(); //wzrost
	data->age = ageSpinCtrl->GetValue(); //wiek
	data->sex = sexRadioBox->GetSelection(); //0 - mezczyzna, 1 - kobieta
	data->target = targetRadioBox->GetSelection(); //0 - utrata masy, 1 - utrzymanie, 2 - przyrost
	data->activity = activityRadioBox->GetSelection(); //0 - niska aktywnosc, 1 - przecietna, 2 - wysoka

	int result = 10 * data->weight + 6.25 * data->height - 5 * data->age;

	switch (data->sex) {
	case 0:
		result += 5;
		break;
	case 1:
		result -= 161;
		break;
	}

	switch (data->activity) {
	case 0:
		result += 400;
		break;
	case 1:
		result += 600;
		break;
	case 2:
		result += 800;
		break;
	}

	switch (data->target) {
	case 0:
		result -= 300;
		break;
	case 2:
		result += 300;
		break;
	}

	data->usertargets.caloriesTarget = result;
	data->usertargets.proteinsTarget = result / 4 * 0.3;
	data->usertargets.fatsTarget = result / 9 * 0.2;
	data->usertargets.carbsTarget = result / 4 * 0.5;
}

void DataFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}

void DataFrame::OnCalculateButtonClick(wxCommandEvent& event) // metoda dodania danych do db
{
	Database* db = new Database("127.0.0.1", "root", "");
	Calculate();
	db->updateUserData(*data, UserId);

	wxString messageBox = wxString("Data has been updated.");
	wxMessageBox(messageBox);

	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}