#pragma once
#include <wx/wx.h>

class WelcomeFrame : public wxFrame {
public:
	WelcomeFrame(const wxString& title);
private:
	void SetDisplay();
	void OnSwitchButtonClick(wxCommandEvent& event);
};

class SummingFrame : public wxFrame {
public:
	SummingFrame(const wxString& title);
	void GetUpdate(wxString a);
	wxStaticText* totalCaloriesAmount;
private:
	void SetDisplay();
	void OnAddingButtonClick(wxCommandEvent& event);
};

class AddingFrame : public wxFrame {
public:
	AddingFrame(const wxString& title);
	wxTextCtrl* caloriesInput;
	wxString valueStr;
	SummingFrame* summingFrame1;
private:
	void SetDisplay();
	void OnSubmitButtonClick(wxCommandEvent& event);
	void ConvertAndAdd(wxString final, wxString added);
};