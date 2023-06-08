#pragma once
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

class Meal {
public:
	wxString name;
	int kcal;
	int protein;
	int carbs;
	int fat;
	wxDateTime date;
	int type;
};