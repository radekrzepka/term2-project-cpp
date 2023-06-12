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
	WelcomeFrame(const wxString& title); // konstruktor 
private:
	Database* db;
	void SetDisplay(); // funkcja definiujaca rozmiary okienka
	void OnAddingFrameButtonClick(wxCommandEvent& event); 
	void OnDataFrameButtonClick(wxCommandEvent& event);
	void OnSummaryFrameButtonClick(wxCommandEvent& event); // funkcje wykonujace sie po kliknieciu buttonow
	void OnLogOutFrameButtonClick(wxCommandEvent& event);
};

class SummaryFrame : public wxFrame {
public:
	SummaryFrame(const wxString& title); // konstruktor
private:
	Database* db;
	UserTargets userTargets;
	int delay = 40; // zmienna wykorzystana jako przerwa miedzy wierszami dodawanych posilkow
	wxPanel* summaryFramePanel; // panel
	wxDatePickerCtrl* datePicker;
	void SetDisplay();
	void AddMealBox(); // funkcja dodajaca posilek do meal planu
	void OnReturnButtonClick(wxCommandEvent& event); // funkcje wykonujace sie po kliknieciu buttonow
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
	wxSpinCtrl* ageSpinCtrl; //deklaracje kontrolek
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
	wxChoice* typeChoice; //deklaracje kontrolek
	wxSpinCtrl* kcalSpinCtrl;
	wxSpinCtrl* proteinSpinCtrl;
	wxSpinCtrl* carbsSpinCtrl;
	wxSpinCtrl* fatSpinCtrl;
	void SetDisplay();
	bool validate();
	void OnReturnButtonClick(wxCommandEvent& event);
	void OnAddButtonClick(wxCommandEvent& event);
};