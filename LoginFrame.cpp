#define _CRT_SECURE_NO_WARNINGS 

#include <wx/wx.h>
#include <iostream>
#include <iomanip>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <string>
#include <sstream>

#include "Frames.h"

std::string sha256(const std::string& password) {
	unsigned char hash[SHA256_DIGEST_LENGTH];
	EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr);
	EVP_DigestUpdate(mdctx, password.c_str(), password.length());
	EVP_DigestFinal_ex(mdctx, hash, nullptr);
	EVP_MD_CTX_free(mdctx);

	std::stringstream ss;
	for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
		ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
	}

	return ss.str();
}

LoginFrame::LoginFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	db = new Database("127.0.0.1", "root", "");
	wxPanel* loginFramePanel = new wxPanel(this, wxID_ANY);

	wxStaticText* loginText = new wxStaticText(loginFramePanel, wxID_ANY, "Log in: ", wxPoint(10, 50));

	wxStaticText* loginNameText = new wxStaticText(loginFramePanel, wxID_ANY, "Enter name: ", wxPoint(10, 80));
	loginName = new wxTextCtrl(loginFramePanel, wxID_ANY, "", wxPoint(10, 110), wxSize(100, -1));

	wxStaticText* loginPasswordText = new wxStaticText(loginFramePanel, wxID_ANY, "Enter password: ", wxPoint(10, 140));
	loginPassword = new wxTextCtrl(loginFramePanel, wxID_ANY, "", wxPoint(10, 170), wxSize(100, -1), wxTE_PASSWORD);

	wxButton* loginButton = new wxButton(loginFramePanel, wxID_ANY, "Log in", wxPoint(10, 200), wxSize(75, 30));

	wxStaticText* registerText = new wxStaticText(loginFramePanel, wxID_ANY, "Register: ", wxPoint(10, 230));

	wxStaticText* registerNameText = new wxStaticText(loginFramePanel, wxID_ANY, "Enter name: ", wxPoint(10, 260));
	registerName = new wxTextCtrl(loginFramePanel, wxID_ANY, "", wxPoint(10, 290), wxSize(100, -1));

	wxStaticText* registerPasswordText = new wxStaticText(loginFramePanel, wxID_ANY, "Enter password: ", wxPoint(10, 320));
	registerPassword = new wxTextCtrl(loginFramePanel, wxID_ANY, "", wxPoint(10, 350), wxSize(100, -1), wxTE_PASSWORD);

	wxButton* registerButton = new wxButton(loginFramePanel, wxID_ANY, "Register", wxPoint(10, 380), wxSize(75, 30));
	
	loginButton->Bind(wxEVT_BUTTON, &LoginFrame::OnLoginButtonClick, this);
	registerButton->Bind(wxEVT_BUTTON, &LoginFrame::OnRegisterClick, this);
	this->SetDisplay();
}

void LoginFrame::SetDisplay() {
	this->SetClientSize(800, 600);
	this->Center();
	this->Show();
}

void LoginFrame::OnLoginButtonClick(wxCommandEvent& event)
{
	wxString name = loginName->GetValue();
	wxString password = loginPassword->GetValue();
	std::string hashedPassword = sha256(password.ToStdString());

	if (db->getUserPassword(name.ToStdString()) == hashedPassword) {
		WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories");
		Close();
	}
	else {
		wxString message = wxString("Enter valid login details");
		wxMessageBox(message);
	}
}

void LoginFrame::OnRegisterClick(wxCommandEvent& event)
{
	wxString name = registerName->GetValue();
	wxString password = registerPassword->GetValue();
	
	bool userInDb = db->checkIfNameInDb(name.ToStdString());

	if (userInDb) {
		wxString error = wxString("A user with the given name already exists");
		wxMessageBox(error);
	}
	else if (name.length() == 0 || password.length() == 0) {
		wxString error = wxString("Complete all fields");
		wxMessageBox(error);
	}
	else {
		std::string hashedPassword = sha256(password.ToStdString());

		db->insertUser(name.ToStdString(), hashedPassword);

		registerName->SetValue("");
		registerPassword->SetValue("");

		wxString message = wxString("The account was created correctly, you can log in");
		wxMessageBox(message);
	}
}
