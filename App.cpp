#define _CRT_SECURE_NO_WARNINGS 

#include "App.h"
#include "Frames.h"
#include "wx/wx.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories"); // otwarcie okienka powitalnego 
	return true;
}