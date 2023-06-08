#define _CRT_SECURE_NO_WARNINGS 

#include "App.h"
#include "Frames.h"

#include <wx/wx.h>

WelcomeFrame::WelcomeFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* welcomeFramePanel = new wxPanel(this, wxID_ANY); // panel sluzy jako container

	wxStaticText* welcomeLine = new wxStaticText(welcomeFramePanel, wxID_ANY, "CALORIES", wxPoint(375, 45)); // linia powitalna

	wxButton* summaryFrameButton = new wxButton(welcomeFramePanel, wxID_ANY, "summary", wxPoint(300, 250), wxSize(200, 70)); 
	wxButton* addingFrameButton = new wxButton(welcomeFramePanel, wxID_ANY, "add meal", wxPoint(300, 170), wxSize(200, 70)); // buttons
	wxButton* dataFrameButton = new wxButton(welcomeFramePanel, wxID_ANY, "data", wxPoint(300, 90), wxSize(200, 70)); 

	summaryFrameButton->Bind(wxEVT_BUTTON, &WelcomeFrame::OnSummaryFrameButtonClick, this); 
	addingFrameButton->Bind(wxEVT_BUTTON, &WelcomeFrame::OnAddingFrameButtonClick, this); // przypisanie eventow do buttonow
	dataFrameButton->Bind(wxEVT_BUTTON, &WelcomeFrame::OnDataFrameButtonClick, this);

	this->SetDisplay();
}

void WelcomeFrame::OnSummaryFrameButtonClick(wxCommandEvent& event) {
	SummaryFrame* summaryFrame = new SummaryFrame("Calories");             // button otwiera okienko podsumowania
	Close();
}

void WelcomeFrame::OnAddingFrameButtonClick(wxCommandEvent& event) {
	AddingFrame* addingFrame = new AddingFrame("Calories");                // button otwiera okienko wprowadzania posilkow
	Close();
}

void WelcomeFrame::OnDataFrameButtonClick(wxCommandEvent& event) {
	DataFrame* dataFrame = new DataFrame("Calories");                      // button otwiera okienko danych
	Close();
}

void WelcomeFrame::SetDisplay() {
	this->SetClientSize(800, 600); 
	this->Center();
	this->Show();
}

