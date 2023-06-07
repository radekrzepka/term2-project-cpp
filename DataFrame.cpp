#include "App.h"
#include "Frames.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/tglbtn.h>

DataFrame::DataFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) { //konstruktor frame'u z danymi

	wxPanel* dataFramePanel = new wxPanel(this, wxID_ANY); // panel

	wxButton* returnButton = new wxButton(dataFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30)); //button powrotu

	wxStaticText* inputWeightText = new wxStaticText(dataFramePanel, wxID_ANY, "Weight (kg):", wxPoint(10, 50)); //text
	wxStaticText* inputHeightText = new wxStaticText(dataFramePanel, wxID_ANY, "Height (cm):", wxPoint(10, 75));
	wxStaticText* inputAgeText = new wxStaticText(dataFramePanel, wxID_ANY, "Age:", wxPoint(10, 100));
	wxStaticText* chooseSexText = new wxStaticText(dataFramePanel, wxID_ANY, "Sex:", wxPoint(10, 128));
	wxStaticText* chooseTargetText = new wxStaticText(dataFramePanel, wxID_ANY, "Target:", wxPoint(10, 153));
	wxStaticText* chooseActivityText = new wxStaticText(dataFramePanel, wxID_ANY, "Activity:", wxPoint(10, 181));

	weightSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, "75", wxPoint(80, 45), wxSize(100, -1)); //spinctrl dla wagi i wzrostu
	weightSpinCtrl->SetRange(40, 120);

	heightSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, "175", wxPoint(80, 70), wxSize(100, -1));
	heightSpinCtrl->SetRange(150, 210);

	ageSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, "18", wxPoint(80, 95), wxSize(100, -1));
	ageSpinCtrl->SetRange(10, 99);

	wxArrayString sexChoices;
	sexChoices.Add("male");
	sexChoices.Add("female");
	sexRadioBox = new wxRadioBox(dataFramePanel, wxID_ANY, "", wxPoint(75, 110), wxSize(0, 0), sexChoices);

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

	wxButton* calculateButton = new wxButton(dataFramePanel, wxID_ANY, "calculate", wxPoint(10, 205), wxSize(75, 30));

	returnButton->Bind(wxEVT_BUTTON, &DataFrame::OnReturnButtonClick, this); //bindy buttonow
	calculateButton->Bind(wxEVT_BUTTON, &DataFrame::OnCalculateButtonClick, this);

	this->SetDisplay();
}

void DataFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}

double DataFrame::Calculate()
{
	double weight = weightSpinCtrl->GetValue(); //tutaj masz wartosc odczytana wagi
	double height = heightSpinCtrl->GetValue(); //wzrost
	int age = ageSpinCtrl->GetValue(); //wiek
	int sex = sexRadioBox->GetSelection(); //0 - mezczyzna, 1 - kobieta
	int target = targetRadioBox->GetSelection(); //0 - utrata masy, 1 - utrzymanie masy, 2 - przyrost masy
	int activity = activityRadioBox->GetSelection(); //0 - niska aktywnosc, 1 - przecietna, 2 - wysoka

	int result = 10 * weight + 6.25 * height - 5 * age;

	if (sex == 0) {
		result += 5;
	}
	else if (sex == 1) {
		result -= 161;
	}

	if (activity == 0) {
		result += 400;
	}
	else if (activity == 1) {
		result += 600;
	}
	else if (activity == 2) {
		result += 800;
	}

	if (target == 0) {
		result -= 300;
	}
	else if (target == 1) {
		//
	}
	else if (target == 2) {
		result += 300;
	}

	return result;
}

void DataFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}

void DataFrame::OnCalculateButtonClick(wxCommandEvent& event)
{
	wxString calorieIntake = wxString::Format(wxT("%.2f"), Calculate());
	wxMessageBox(calorieIntake);
}


