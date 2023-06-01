#include "App.h"
#include "Frames.h"
#include <wx/wx.h>

WelcomeFrame::WelcomeFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* welcomeFramePanel = new wxPanel(this, wxID_ANY); // panel sluzy jako container
	wxStaticText* welcomeLine = new wxStaticText(welcomeFramePanel, wxID_ANY, "CALORIES", wxPoint(375, 75)); // linia powitalna
	wxButton* mainButton = new wxButton(welcomeFramePanel, wxID_ANY, "Get started", wxPoint(300, 250), wxSize(200, 70)); // button przelaczajacy okno
	mainButton->Bind(wxEVT_BUTTON, &WelcomeFrame::OnSwitchButtonClick, this); // przypisanie eventu do buttona
	this->SetDisplay();
}

void WelcomeFrame::OnSwitchButtonClick(wxCommandEvent& event) {
	SummingFrame* summingFrame = new SummingFrame("Calories"); // button otwiera okienko wprowadzania posilkow
	Close();
}

void WelcomeFrame::SetDisplay() {
	this->SetClientSize(800, 600); 
	this->Center();
	this->Show();
}

