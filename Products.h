#pragma once
#include <wx/wx.h>

class Product {
public:
	Product(wxString a, wxString b, wxString c, wxString d, wxString e);
	wxString name;
	wxString kcal;
	wxString protein;
	wxString carbs;
	wxString fat;
};