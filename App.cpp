#define _CRT_SECURE_NO_WARNINGS 

#include "App.h"
#include "Frames.h"
#include "wx/wx.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	LoginFrame* loginFrame = new LoginFrame("Log in or register"); // poczatek aplikacji, okienko logowania 
	return true;
}