#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <wx/wx.h> //glowna biblioteka wxWidgets

class App : public wxApp { // klasa App reprezentuje aplikacje
public:
	bool OnInit(); // metoda OnInit() reprezentuje glowna funkcje
};