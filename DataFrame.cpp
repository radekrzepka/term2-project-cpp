#include "App.h"
#include "Frames.h"
#include <wx/wx.h>

DataFrame::DataFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* dataFramePanel = new wxPanel(this, wxID_ANY);

	wxButton* returnButton = new wxButton(dataFramePanel, wxID_ANY, "return", wxPoint(10, 10), wxSize(75, 30));

	returnButton->Bind(wxEVT_BUTTON, &DataFrame::OnReturnButtonClick, this);

	this->SetDisplay();
}

void DataFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}

void DataFrame::OnReturnButtonClick(wxCommandEvent& event)
{
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
	Close();
}
