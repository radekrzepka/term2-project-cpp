#include "App.h"
#include "Frames.h"
#include <wx/wx.h>

AddingFrame::AddingFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* addingFramePanel = new wxPanel(this, wxID_ANY);

	wxButton* returnButton = new wxButton(addingFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30));

	returnButton->Bind(wxEVT_BUTTON, &AddingFrame::OnReturnButtonClick, this);

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

