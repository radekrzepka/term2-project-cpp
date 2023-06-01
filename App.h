#pragma once
#include <wx/wx.h> //glowna biblioteka wxWidgets

class Values { // klasa przechowywujaca dane
public:
	wxString totalCalories = '0';
	wxString totalProtein = '0';
	wxString totalCarbs = '0';
	wxString totalFat = '0';
};

class App : public wxApp { // klasa App reprezentuje aplikacje
public:
	bool OnInit(); // metoda OnInit() reprezentuje glowna funkcje
};

extern Values values;