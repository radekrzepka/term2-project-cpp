#pragma once
#include <wx/wx.h> //glowna biblioteka wxWidgets

class Values {
public:
	wxString totalCalories;
};

extern Values values;

class App : public wxApp { //klasa App reprezentuje aplikacje
public:
	bool OnInit(); //metoda OnInit() reprezentuje glowna funkcje
private:

};