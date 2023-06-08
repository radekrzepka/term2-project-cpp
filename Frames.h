#pragma once
#include "Data.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

class WelcomeFrame : public wxFrame { // klasa okienka powitalnego
public:
	WelcomeFrame(const wxString& title);
private:
	void SetDisplay();
	void OnAddingFrameButtonClick(wxCommandEvent& event);
	void OnDataFrameButtonClick(wxCommandEvent& event);
	void OnSummaryFrameButtonClick(wxCommandEvent& event);
};

class SummaryFrame : public wxFrame {
public:
	SummaryFrame(const wxString& title);
private:
	void SetDisplay();
	void OnReturnButtonClick(wxCommandEvent& event);
};

class DataFrame : public wxFrame {
public:
	DataFrame(const wxString& title);
private:
	Data* data;
	wxSpinCtrl* weightSpinCtrl;
	wxSpinCtrl* heightSpinCtrl;
	wxSpinCtrl* ageSpinCtrl;
	wxRadioBox* sexRadioBox;
	wxRadioBox* targetRadioBox;
	wxRadioBox* activityRadioBox;
	void SetDisplay();
	double Calculate();
	void OnReturnButtonClick(wxCommandEvent& event);
	void OnCalculateButtonClick(wxCommandEvent& event);
};

class AddingFrame : public wxFrame {
public:
	AddingFrame(const wxString& title);
private:
	wxDatePickerCtrl* datePicker;
	void SetDisplay();
	void OnReturnButtonClick(wxCommandEvent& event);
	void OnDateChanged(wxDateEvent& event);
};

//class SummingFrame : public wxFrame { // klasa okienka sumujacego wartosci odzywcze
//public:
//	SummingFrame(const wxString& title);
//	void GetUpdate(wxStaticText* A, wxString a);
//	wxStaticText* totalCaloriesAmount;
//	wxStaticText* totalProteinAmount;
//	wxStaticText* totalCarbsAmount;
//	wxStaticText* totalFatAmount;
//	bool isAddingFrameOpen;
//private:
//	void SetDisplay();
//	void OnAddingButtonClick(wxCommandEvent& event); 
//	void OnClose(wxCloseEvent& event);
//};
//class AddingFrame : public wxFrame { // klasa okienka do wprowadzania wartosci posilkow
//public:
//	AddingFrame(const wxString& title);
//	wxTextCtrl* nameInput;
//	wxTextCtrl* caloriesInput;
//	wxTextCtrl* proteinInput;
//	wxTextCtrl* carbsInput;
//	wxTextCtrl* fatInput;
//	wxString nameStr;
//	wxString caloriesStr;
//	wxString proteinStr;
//	wxString carbsStr;
//	wxString fatStr;
//	SummingFrame* summingFrame;
//private:
//	void SetDisplay();
//	void OnSubmitButtonClick(wxCommandEvent& event);
//	void ConvertAndAdd(wxString& final, wxString added);
//};