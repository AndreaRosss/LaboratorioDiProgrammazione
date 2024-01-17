#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/listctrl.h>
using namespace std;

class Registro;

class SfogliaRegistroFrame : public wxFrame
{
public:
	SfogliaRegistroFrame(wxFrame* parent, Registro* registro);

private:
	Registro* registr;
	wxPanel* panel;
	wxArrayString as;
	wxChoice* choiche;
	wxListBox* descrizione;
	void OnChoiceChanged(wxCommandEvent& evt);

public:
	wxListBox* GetDescrizione() {
		return descrizione;
	}
	wxChoice* GetChoice() {
		return choiche;
	}
};


