#pragma once
#include <wx/wx.h>

class WelcomeFrame : public wxFrame { // klasa okienka powitalnego
public:
	WelcomeFrame(const wxString& title);
private:
	void SetDisplay();
	void OnSwitchButtonClick(wxCommandEvent& event);
};

class SummingFrame : public wxFrame { // klasa okienka sumujacego wartosci odzywcze
public:
	SummingFrame(const wxString& title);
	void GetUpdate(wxStaticText* A, wxString a);
	wxStaticText* totalCaloriesAmount;
	wxStaticText* totalProteinAmount;
	wxStaticText* totalCarbsAmount;
	wxStaticText* totalFatAmount;
	bool isAddingFrameOpen;
private:
	void SetDisplay();
	void OnAddingButtonClick(wxCommandEvent& event); 
};

class AddingFrame : public wxFrame { // klasa okienka do wprowadzania wartosci posilkow
public:
	AddingFrame(const wxString& title);
	wxTextCtrl* nameInput;
	wxTextCtrl* caloriesInput;
	wxTextCtrl* proteinInput;
	wxTextCtrl* carbsInput;
	wxTextCtrl* fatInput;
	SummingFrame* summingFrame;
	wxString caloriesStr;
	wxString proteinStr;
	wxString carbsStr;
	wxString fatStr;
private:
	void SetDisplay();
	void OnSubmitButtonClick(wxCommandEvent& event);
	void ConvertAndAdd(wxString& final, wxString added);
};