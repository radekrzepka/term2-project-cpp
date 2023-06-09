#define _CRT_SECURE_NO_WARNINGS 

#include "App.h"
#include "Frames.h"

#include <wx/wx.h>

SummaryFrame::SummaryFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
	summaryFramePanel = new wxPanel(this, wxID_ANY);

	wxStaticText* summaryText = new wxStaticText(summaryFramePanel, wxID_ANY, "Summary for: ", wxPoint(315, 25)); //main text

	wxStaticText* totalKcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "kcal: ", wxPoint(140, 60));
	wxStaticText* totalProteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "protein: ", wxPoint(290, 60)); //text
	wxStaticText* totalCarbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "carbs: ", wxPoint(440, 60));
	wxStaticText* totalFatText = new wxStaticText(summaryFramePanel, wxID_ANY, "fat: ", wxPoint(590, 60));

	wxStaticText* realKcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "9999", wxPoint(170, 60));
	wxStaticText* realProteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "999", wxPoint(335, 60)); //realtext
	wxStaticText* realCarbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "999", wxPoint(475, 60));
	wxStaticText* realFatText = new wxStaticText(summaryFramePanel, wxID_ANY, "999", wxPoint(615, 60));

	wxStaticText* slashKcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "/", wxPoint(195, 60));
	wxStaticText* slashProteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "/", wxPoint(355, 60)); //slash
	wxStaticText* slashCarbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "/", wxPoint(495, 60));
	wxStaticText* slashFatText = new wxStaticText(summaryFramePanel, wxID_ANY, "/", wxPoint(635, 60));

	wxStaticText* maxKcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "9999", wxPoint(200, 60));
	wxStaticText* maxProteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "999", wxPoint(360, 60)); //maxtext
	wxStaticText* maxCarbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "999", wxPoint(500, 60));
	wxStaticText* maxFatText = new wxStaticText(summaryFramePanel, wxID_ANY, "999", wxPoint(640, 60));

	wxStaticText* typeText = new wxStaticText(summaryFramePanel, wxID_ANY, "type:", wxPoint(120, 100));
	wxStaticText* nameText = new wxStaticText(summaryFramePanel, wxID_ANY, "name:", wxPoint(220, 100));
	wxStaticText* kcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "kcal:", wxPoint(320, 100));
	wxStaticText* proteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "protein:", wxPoint(420, 100)); //tabela
	wxStaticText* carbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "carbs:", wxPoint(520, 100));
	wxStaticText* fatText = new wxStaticText(summaryFramePanel, wxID_ANY, "fat:", wxPoint(620, 100));

	datePicker = new wxDatePickerCtrl(summaryFramePanel, wxID_ANY, wxDefaultDateTime, wxPoint(390, 20), wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
	datePicker->SetValue(wxDateTime::Today());

	wxButton* returnButton = new wxButton(summaryFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30));

	returnButton->Bind(wxEVT_BUTTON, &SummaryFrame::OnReturnButtonClick, this);
	datePicker->Bind(wxEVT_DATE_CHANGED, &SummaryFrame::OnDateChanged, this);

	this->SetDisplay();
}

void SummaryFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}

void SummaryFrame::AddMealBox()
{
	wxStaticText* typeText = new wxStaticText(summaryFramePanel, wxID_ANY, "breakfast", wxPoint(120, 100+delay));
	wxStaticText* nameText = new wxStaticText(summaryFramePanel, wxID_ANY, "name", wxPoint(220, 100+delay));
	wxStaticText* kcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "100", wxPoint(320, 100 + delay));
	wxStaticText* proteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "23", wxPoint(420, 100 + delay)); //tabela
	wxStaticText* carbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "123", wxPoint(520, 100 + delay));
	wxStaticText* fatText = new wxStaticText(summaryFramePanel, wxID_ANY, "3", wxPoint(620, 100 + delay));
	delay += 20;
}

void SummaryFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}

void SummaryFrame::OnDateChanged(wxDateEvent& event)
{
	wxMessageBox("Date changed");
	AddMealBox();
	Refresh();
}