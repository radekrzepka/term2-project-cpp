#include "App.h"
#include "Frames.h"
#include "Meal.h"
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

AddingFrame::AddingFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* addingFramePanel = new wxPanel(this, wxID_ANY);

	wxStaticText* nameText = new wxStaticText(addingFramePanel, wxID_ANY, "Enter name: ", wxPoint(10, 50));
	wxStaticText* dateText = new wxStaticText(addingFramePanel, wxID_ANY, "Choose date: ", wxPoint(10, 80));
	wxStaticText* mealText = new wxStaticText(addingFramePanel, wxID_ANY, "Choose meal: ", wxPoint(10, 110));
	wxStaticText* macroText = new wxStaticText(addingFramePanel, wxID_ANY, "Enter macro", wxPoint(10, 140)); //text
	wxStaticText* calorieText = new wxStaticText(addingFramePanel, wxID_ANY, "kcal: ", wxPoint(10, 170)); 
	wxStaticText* proteinText = new wxStaticText(addingFramePanel, wxID_ANY, "protein: ", wxPoint(10, 200));
	wxStaticText* carbsText = new wxStaticText(addingFramePanel, wxID_ANY, "carbs: ", wxPoint(10, 230));
	wxStaticText* fatText = new wxStaticText(addingFramePanel, wxID_ANY, "fat: ", wxPoint(10, 260));

	nameTextCtrl = new wxTextCtrl(addingFramePanel, wxID_ANY, "name", wxPoint(85, 45), wxSize(100, -1));

	datePicker = new wxDatePickerCtrl(addingFramePanel, wxID_ANY, wxDefaultDateTime, wxPoint(85, 75), wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
	datePicker->SetValue(wxDateTime::Today());

	typeChoice = new wxChoice(addingFramePanel, wxID_ANY, wxPoint(85, 105), wxSize(100, -1));
	typeChoice->Append("breakfast");
	typeChoice->Append("snack I");
	typeChoice->Append("lunch");
	typeChoice->Append("snack II");
	typeChoice->Append("dinner");
	typeChoice->SetSelection(0);

	kcalSpinCtrl = new wxSpinCtrl(addingFramePanel, wxID_ANY, "", wxPoint(85, 165), wxSize(100, -1));
	kcalSpinCtrl->SetRange(1, 900);

	proteinSpinCtrl = new wxSpinCtrl(addingFramePanel, wxID_ANY, "", wxPoint(85, 195), wxSize(100, -1));
	proteinSpinCtrl->SetRange(1, 100);

	carbsSpinCtrl = new wxSpinCtrl(addingFramePanel, wxID_ANY, "", wxPoint(85, 225), wxSize(100, -1));
	carbsSpinCtrl->SetRange(1, 100);

	fatSpinCtrl = new wxSpinCtrl(addingFramePanel, wxID_ANY, "", wxPoint(85, 255), wxSize(100, -1));
	fatSpinCtrl->SetRange(1, 100);

	wxButton* returnButton = new wxButton(addingFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30));

	wxButton* addButton = new wxButton(addingFramePanel, wxID_ANY, "Add", wxPoint(10, 290), wxSize(75, 30));

	returnButton->Bind(wxEVT_BUTTON, &AddingFrame::OnReturnButtonClick, this);
	addButton->Bind(wxEVT_BUTTON, &AddingFrame::OnAddButtonClick, this);

	this->SetDisplay();
}

void AddingFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}

void AddingFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}

void AddingFrame::OnAddButtonClick(wxCommandEvent& event)
{
	meal = new Meal;
	meal->name = nameTextCtrl->GetValue();
	meal->kcal = kcalSpinCtrl->GetValue();
	meal->protein = proteinSpinCtrl->GetValue();
	meal->carbs = carbsSpinCtrl->GetValue();
	meal->fat = fatSpinCtrl->GetValue();
	meal->type = typeChoice->GetSelection();
}
