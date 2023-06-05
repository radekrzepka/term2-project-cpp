#include "Products.h"
#include <wx/wx.h>

Product::Product(wxString a, wxString b, wxString c, wxString d, wxString e):
	name(a), kcal(b), protein(c), carbs(d), fat(e) {

}