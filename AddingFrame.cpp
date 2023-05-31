#include "App.h"
#include "Frames.h"
#include <wx/wx.h>

AddingFrame::AddingFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* addingFramePanel = new wxPanel(this, wxID_ANY);
	wxButton* submitAddingButton = new wxButton(addingFramePanel, wxID_ANY, "Submit", wxPoint(25, 150), wxSize(100, 20));
	wxStaticText* inputCaloriesText = new wxStaticText(addingFramePanel, wxID_ANY, "Calories:", wxPoint(5, 30));
	caloriesInput = new wxTextCtrl(addingFramePanel, wxID_ANY, "", wxPoint(55, 25), wxSize(100, -1));
	submitAddingButton->Bind(wxEVT_BUTTON, &AddingFrame::OnSubmitButtonClick, this);
	this->SetDisplay();
}

void AddingFrame::OnSubmitButtonClick(wxCommandEvent& event) {
	valueStr = caloriesInput->GetValue();
	ConvertAndAdd(values.totalCalories, valueStr);
	summingFrame1->GetUpdate(values.totalCalories);
	Close();
}

void AddingFrame::ConvertAndAdd(wxString final, wxString added)
{
	int a{}, b{}, c{};
	wxString result;
	added.ToInt(&a);
	final.ToInt(&b);
	c = a + b;
	result = wxString::Format("%d", c);
	values.totalCalories = result;
}

void AddingFrame::SetDisplay() {
	this->SetClientSize(400, 200);
	this->Center();
	this->Show();
}

