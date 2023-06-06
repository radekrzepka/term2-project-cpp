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

	wxSpinCtrl* weightSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, "75", wxPoint(80, 45), wxSize(100, -1)); //spinctrl dla wagi i wzrostu
	weightSpinCtrl->SetRange(40, 120);

	wxSpinCtrl* heightSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, "175", wxPoint(80, 70), wxSize(100, -1));
	heightSpinCtrl->SetRange(150, 210);

	wxSpinCtrl* ageSpinCtrl = new wxSpinCtrl(dataFramePanel, wxID_ANY, "18", wxPoint(80, 95), wxSize(100, -1));
	ageSpinCtrl->SetRange(10, 99);

	wxArrayString sexChoices;
	sexChoices.Add("male");
	sexChoices.Add("female");
	wxRadioBox* sexRadioBox = new wxRadioBox(dataFramePanel, wxID_ANY, "", wxPoint(75, 110), wxSize(0, 0), sexChoices);

	wxArrayString targetChoices;
	targetChoices.Add("lose weight");
	targetChoices.Add("maintain weight"); //radiobox dla celu
	targetChoices.Add("gain weight");
	wxRadioBox* targetRadioBox = new wxRadioBox(dataFramePanel, wxID_ANY, "", wxPoint(75, 135), wxSize(0, 0), targetChoices);

	wxArrayString activityChoices;
	activityChoices.Add("low");
	activityChoices.Add("average"); //radiobox dla aktywnosci fizyrcznej
	activityChoices.Add("high");
	wxRadioBox* activityRadioBox = new wxRadioBox(dataFramePanel, wxID_ANY, "", wxPoint(75, 160), wxSize(0, 0), activityChoices);

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

void DataFrame::Calculate()
{
	double weight = weightSpinCtrl->GetValue();
	double height = heightSpinCtrl->GetValue();
	double age = ageSpinCtrl->GetValue();
	int sex = sexRadioBox->GetSelection();
	int target = targetRadioBox->GetSelection();
	int activity = activityRadioBox->GetSelection();
	int result;
}

void DataFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}

void DataFrame::OnCalculateButtonClick(wxCommandEvent& event)
{

}


