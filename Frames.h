#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include "Data.h"
#include "Meal.h"
#include "Database.h"
#include "UserTargets.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

class LoginFrame : public wxFrame {
public:
	LoginFrame(const wxString& title);
private:
	Database* db;
	void SetDisplay();
	wxTextCtrl* loginName;
	wxTextCtrl* loginPassword;
	wxTextCtrl* registerName;
	wxTextCtrl* registerPassword;
	void OnLoginButtonClick(wxCommandEvent& event);
	void OnRegisterClick(wxCommandEvent& event);
};

class WelcomeFrame : public wxFrame { // klasa okienka powitalnego
public:
	WelcomeFrame(const wxString& title);
private:
	Database* db;
	void SetDisplay();
	void OnAddingFrameButtonClick(wxCommandEvent& event);
	void OnDataFrameButtonClick(wxCommandEvent& event);
	void OnSummaryFrameButtonClick(wxCommandEvent& event);
	void OnLogOutFrameButtonClick(wxCommandEvent& event);
};

class SummaryFrame : public wxFrame {
public:
	SummaryFrame(const wxString& title);
private:
	Database* db;
	UserTargets userTargets;
	int delay = 40;
	wxPanel* summaryFramePanel;
	wxDatePickerCtrl* datePicker;
	void SetDisplay();
	void AddMealBox();
	void OnReturnButtonClick(wxCommandEvent& event);
	void OnDateChanged(wxDateEvent& event);
};

class DataFrame : public wxFrame {
public:
	DataFrame(const wxString& title, bool dataCreated = true);
private:
	Database* db;
	Data* data;
	wxSpinCtrl* weightSpinCtrl;
	wxSpinCtrl* heightSpinCtrl;
	wxSpinCtrl* ageSpinCtrl;
	wxRadioBox* sexRadioBox;
	wxRadioBox* targetRadioBox;
	wxRadioBox* activityRadioBox;
	void SetDisplay();
	void Calculate();
	void OnReturnButtonClick(wxCommandEvent& event);
	void OnCalculateButtonClick(wxCommandEvent& event);
};

class AddingFrame : public wxFrame {
public:
	AddingFrame(const wxString& title);
private:
	Database* db;
	Meal* meal;
	wxTextCtrl* nameTextCtrl;
	wxDatePickerCtrl* datePicker;
	wxChoice* typeChoice;
	wxSpinCtrl* kcalSpinCtrl;
	wxSpinCtrl* proteinSpinCtrl;
	wxSpinCtrl* carbsSpinCtrl;
	wxSpinCtrl* fatSpinCtrl;
	void SetDisplay();
	bool validate();
	void OnReturnButtonClick(wxCommandEvent& event);
	void OnAddButtonClick(wxCommandEvent& event);
};