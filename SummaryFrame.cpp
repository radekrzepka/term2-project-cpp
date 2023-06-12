#define _CRT_SECURE_NO_WARNINGS 

#include "App.h"
#include "Frames.h"
#include "Database.h"
#include "Meal.h"
#include "UserTargets.h"
#include "UserId.h"

#include <wx/wx.h>

SummaryFrame::SummaryFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
	db = new Database("127.0.0.1", "root", "");
	userTargets = db->getUserTargets(UserId);

	summaryFramePanel = new wxPanel(this, wxID_ANY);

	datePicker = new wxDatePickerCtrl(summaryFramePanel, wxID_ANY, wxDefaultDateTime, wxPoint(390, 20), wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY); // kontrolka wyboru daty 
	datePicker->SetValue(wxDateTime::Today());

	AddMealBox(); //wywolanie metody dodania posilkow

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
	wxDateTime selectedDate = datePicker->GetValue();
	std::string dateString = selectedDate.Format("%Y-%m-%d").ToStdString();
	std::vector<Meal> meals = db->getMealsByDate(dateString, UserId);

	int caloriesSum = 0, carboSum = 0, proteinsSum = 0, fatsSum = 0;

	// Clear old data
	wxWindowList& children = summaryFramePanel->GetChildren();
	for (auto child : children) {
		if (child->IsKindOf(CLASSINFO(wxStaticText))) {
			summaryFramePanel->RemoveChild(child);
			child->Destroy();
		}
	}

	wxStaticText* typeText = new wxStaticText(summaryFramePanel, wxID_ANY, "type:", wxPoint(120, 100));
	wxStaticText* nameText = new wxStaticText(summaryFramePanel, wxID_ANY, "name:", wxPoint(220, 100));
	wxStaticText* kcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "kcal:", wxPoint(320, 100));
	wxStaticText* proteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "protein:", wxPoint(420, 100)); //tabela
	wxStaticText* carbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "carbs:", wxPoint(520, 100));
	wxStaticText* fatText = new wxStaticText(summaryFramePanel, wxID_ANY, "fat:", wxPoint(620, 100));

	delay = 40;

	for (Meal& meal : meals) {
		wxStaticText* typeText = new wxStaticText(summaryFramePanel, wxID_ANY, meal.typeString, wxPoint(120, 100 + delay));
		wxStaticText* nameText = new wxStaticText(summaryFramePanel, wxID_ANY, meal.name, wxPoint(220, 100 + delay));
		wxStaticText* kcalText = new wxStaticText(summaryFramePanel, wxID_ANY, std::to_string(meal.kcal), wxPoint(320, 100 + delay));
		wxStaticText* proteinText = new wxStaticText(summaryFramePanel, wxID_ANY, std::to_string(meal.protein), wxPoint(420, 100 + delay)); //tabela
		wxStaticText* carbsText = new wxStaticText(summaryFramePanel, wxID_ANY, std::to_string(meal.carbs), wxPoint(520, 100 + delay));
		wxStaticText* fatText = new wxStaticText(summaryFramePanel, wxID_ANY, std::to_string(meal.fat), wxPoint(620, 100 + delay));

		caloriesSum += meal.kcal;
		carboSum += meal.carbs;
		proteinsSum += meal.protein;
		fatsSum += meal.fat;

		delay += 20;
	}

	wxStaticText* summaryText = new wxStaticText(summaryFramePanel, wxID_ANY, "Summary for: ", wxPoint(315, 25)); //main text

	wxStaticText* totalKcalText = new wxStaticText(summaryFramePanel, wxID_ANY, "kcal: " + std::to_string(caloriesSum) + "/" + std::to_string(userTargets.caloriesTarget), wxPoint(140, 60));
	wxStaticText* totalProteinText = new wxStaticText(summaryFramePanel, wxID_ANY, "protein: " + std::to_string(proteinsSum) + "/" + std::to_string(userTargets.proteinsTarget), wxPoint(290, 60)); //text
	wxStaticText* totalCarbsText = new wxStaticText(summaryFramePanel, wxID_ANY, "carbs: " + std::to_string(carboSum) + "/" + std::to_string(userTargets.carbsTarget), wxPoint(440, 60));
	wxStaticText* totalFatText = new wxStaticText(summaryFramePanel, wxID_ANY, "fat: " + std::to_string(fatsSum) + "/" + std::to_string(userTargets.fatsTarget), wxPoint(590, 60));
}

void SummaryFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}

void SummaryFrame::OnDateChanged(wxDateEvent& event)
{
	AddMealBox();
}