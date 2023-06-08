#pragma once
#include <wx/wx.h>

class Meal {
public:
	Meal(wxString a, wxString b, wxString c, wxString d, wxString e);
	wxString name;
	wxString kcal;
	wxString protein;
	wxString carbs;
	wxString fat;
};