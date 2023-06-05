#include "App.h"
#include "Frames.h"
#include <wx/wx.h>

SummaryFrame::SummaryFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* summaryFramePanel = new wxPanel(this, wxID_ANY);

	wxButton* returnButton = new wxButton(summaryFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30));

	returnButton->Bind(wxEVT_BUTTON, &SummaryFrame::OnReturnButtonClick, this);

	this->SetDisplay();
}

void SummaryFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}

void SummaryFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}

//wxStaticText* totalKcalText = new wxStaticText(summingFramePanel, wxID_ANY, "kcal: ", wxPoint(25, 25));
//wxStaticText* totalProteinText = new wxStaticText(summingFramePanel, wxID_ANY, "protein: ", wxPoint(125, 25));
//wxStaticText* totalCarbsLine = new wxStaticText(summingFramePanel, wxID_ANY, "carbs: ", wxPoint(225, 25));
//wxStaticText* totalFatLine = new wxStaticText(summingFramePanel, wxID_ANY, "fat: ", wxPoint(325, 25));
//totalCaloriesAmount = new wxStaticText(summingFramePanel, wxID_ANY, values.totalCalories, wxPoint(50, 25));
//totalProteinAmount = new wxStaticText(summingFramePanel, wxID_ANY, values.totalProtein, wxPoint(170, 25));
//totalCarbsAmount = new wxStaticText(summingFramePanel, wxID_ANY, values.totalCarbs, wxPoint(260, 25));
//totalFatAmount = new wxStaticText(summingFramePanel, wxID_ANY, values.totalFat, wxPoint(345, 25));
//wxButton* addingButton = new wxButton(summingFramePanel, wxID_ANY, "Add product", wxPoint(445, 75), wxSize(100, -1));
//Bind(wxEVT_CLOSE_WINDOW, &SummingFrame::OnClose, this);
//addingButton->Bind(wxEVT_BUTTON, &SummingFrame::OnAddingButtonClick, this);
//
//void SummingFrame::GetUpdate(wxStaticText* A, wxString a)
//{
//	A->SetLabel(a);
//}
//
//void SummingFrame::OnAddingButtonClick(wxCommandEvent& event) {
//	if (isAddingFrameOpen == false) {
//		AddingFrame* addingFrame = new AddingFrame("Add meal");
//		addingFrame->summingFrame = this;
//		isAddingFrameOpen = true;
//	}
//	else {
//		wxMessageBox("Insert your meal values first!");
//	}
//}
//
//void SummingFrame::OnClose(wxCloseEvent& event)
//{
//	if (isAddingFrameOpen == true) {
//		event.Veto();
//	}
//	else {
//		event.Skip();
//	}
//}
//wxPanel* panel = new wxPanel(this, wxID_ANY);
//wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));
//wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 55));
//wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT EDITABLE", wxPoint(120, 150));
//wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - EDITABLE", wxPoint(500, 145), wxSize(200, -1));
//wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1));
//wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
//gauge->SetValue(50);
//wxArrayString choices;
//choices.Add("Item A");
//choices.Add("Item B");
//choices.Add("Item C");
//wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
//choice->Select(0);
//wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "choose", wxPoint(550, 375), wxSize(100, -1));
//wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);
//wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);