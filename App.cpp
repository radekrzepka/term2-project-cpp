#include "App.h"
#include "Frames.h"
#include "wx/wx.h"

wxIMPLEMENT_APP(App);

Values values;

bool App::OnInit() {
	WelcomeFrame* welcomeFrame = new WelcomeFrame("Calories"); // otwarcie okienka powitalnego 
	return true;
}