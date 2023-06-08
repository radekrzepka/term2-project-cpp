#include "App.h"
#include "Frames.h"
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

AddingFrame::AddingFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* addingFramePanel = new wxPanel(this, wxID_ANY);

	wxStaticText* dateText = new wxStaticText(addingFramePanel, wxID_ANY, "Choose date: ", wxPoint(10, 50));
	wxStaticText* mealText = new wxStaticText(addingFramePanel, wxID_ANY, "Choose meal: ", wxPoint(10, 75));
	wxStaticText* macroText = new wxStaticText(addingFramePanel, wxID_ANY, "Enter macro", wxPoint(10, 100)); //text
	wxStaticText* calorieText = new wxStaticText(addingFramePanel, wxID_ANY, "kcal: ", wxPoint(10, 125)); 
	wxStaticText* proteinText = new wxStaticText(addingFramePanel, wxID_ANY, "protein: ", wxPoint(10, 150));
	wxStaticText* carbsText = new wxStaticText(addingFramePanel, wxID_ANY, "carbs: ", wxPoint(10, 175));
	wxStaticText* fatText = new wxStaticText(addingFramePanel, wxID_ANY, "fat: ", wxPoint(10, 200));

	datePicker = new wxDatePickerCtrl(addingFramePanel, wxID_ANY, wxDefaultDateTime, wxPoint(85, 45), wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
	datePicker->SetValue(wxDateTime::Today());

	wxButton* returnButton = new wxButton(addingFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30));

	returnButton->Bind(wxEVT_BUTTON, &AddingFrame::OnReturnButtonClick, this);
	datePicker->Bind(wxEVT_DATE_CHANGED, &AddingFrame::OnDateChanged, this);

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

void AddingFrame::OnDateChanged(wxDateEvent& event)
{

}

//wxPanel* addingFramePanel = new wxPanel(this, wxID_ANY);
//wxButton* submitAddingButton = new wxButton(addingFramePanel, wxID_ANY, "Submit", wxPoint(250, 50), wxSize(100, 100)); // button wprowadzajacy posilek do aplikacji
//wxStaticText* inputNameText = new wxStaticText(addingFramePanel, wxID_ANY, "Name:", wxPoint(5, 10)); // tekst
//wxStaticText* inputCaloriesText = new wxStaticText(addingFramePanel, wxID_ANY, "Calories:", wxPoint(5, 40)); // tekst
//wxStaticText* inputProteinText = new wxStaticText(addingFramePanel, wxID_ANY, "Protein:", wxPoint(5, 70)); // tekst
//wxStaticText* inputCarbsText = new wxStaticText(addingFramePanel, wxID_ANY, "Carbs:", wxPoint(5, 100)); // tekst
//wxStaticText* inputFatText = new wxStaticText(addingFramePanel, wxID_ANY, "Fat:", wxPoint(5, 130)); // tekst
//nameInput = new wxTextCtrl(addingFramePanel, wxID_ANY, "", wxPoint(55, 5), wxSize(100, -1));
//caloriesInput = new wxTextCtrl(addingFramePanel, wxID_ANY, "", wxPoint(55, 35), wxSize(100, -1));
//proteinInput = new wxTextCtrl(addingFramePanel, wxID_ANY, "", wxPoint(55, 65), wxSize(100, -1));
//carbsInput = new wxTextCtrl(addingFramePanel, wxID_ANY, "", wxPoint(55, 95), wxSize(100, -1));
//fatInput = new wxTextCtrl(addingFramePanel, wxID_ANY, "", wxPoint(55, 125), wxSize(100, -1));
//submitAddingButton->Bind(wxEVT_BUTTON, &AddingFrame::OnSubmitButtonClick, this);

//void AddingFrame::OnSubmitButtonClick(wxCommandEvent& event) {
//	nameStr = nameInput->GetValue();
//	caloriesStr = caloriesInput->GetValue();
//	proteinStr = proteinInput->GetValue();
//	carbsStr = carbsInput->GetValue();
//	fatStr = fatInput->GetValue();
//	Product product(nameStr, caloriesStr, proteinStr, carbsStr, fatStr);
//	ConvertAndAdd(values.totalCalories, caloriesStr);
//	ConvertAndAdd(values.totalProtein, proteinStr);
//	ConvertAndAdd(values.totalCarbs, carbsStr);
//	ConvertAndAdd(values.totalFat, fatStr);
//	summingFrame->GetUpdate(summingFrame->totalCaloriesAmount, values.totalCalories);
//	summingFrame->GetUpdate(summingFrame->totalProteinAmount, values.totalProtein);               // todo przeniesc to do innej metody bo gowno jebane
//	summingFrame->GetUpdate(summingFrame->totalCarbsAmount, values.totalCarbs);
//	summingFrame->GetUpdate(summingFrame->totalFatAmount, values.totalFat);
//	summingFrame->isAddingFrameOpen = false;
//	Close();
//}
//
//void AddingFrame::ConvertAndAdd(wxString& final, wxString added)
//{
//	int a{}, b{}, c{};
//	wxString result;
//	added.ToInt(&a);
//	final.ToInt(&b);
//	c = a + b;
//	result = wxString::Format("%d", c);
//	final = result;
//}

