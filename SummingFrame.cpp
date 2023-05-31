#include "App.h"
#include "Frames.h"
#include <wx/wx.h>

SummingFrame::SummingFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* summingFramePanel = new wxPanel(this, wxID_ANY);
	wxStaticText* line = new wxStaticText(summingFramePanel, wxID_ANY, "Total amount: ", wxPoint(25, 25));
	totalCaloriesAmount = new wxStaticText(summingFramePanel, wxID_ANY, values.totalCalories, wxPoint(100, 25));
	wxButton* addingButton = new wxButton(summingFramePanel, wxID_ANY, "Add meal", wxPoint(25, 75), wxSize(100, -1));
	addingButton->Bind(wxEVT_BUTTON, &SummingFrame::OnAddingButtonClick, this);
	this->SetDisplay();
}

void SummingFrame::GetUpdate(wxString a)
{
	totalCaloriesAmount->SetLabel(a);
}

void SummingFrame::OnAddingButtonClick(wxCommandEvent& event) {
	AddingFrame* addingFrame = new AddingFrame("Add meal");
	addingFrame->summingFrame1 = this;
}

void SummingFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}












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