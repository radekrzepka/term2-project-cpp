#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

class Meal { //klasa posilku
public:
	wxString name;
	int kcal;
	int protein;
	int carbs;
	int fat;
	wxDateTime date;
	int type;
	std::string typeString;
};