#pragma once
#include <wx/wx.h>
#include "Registro.h"
#include <wx/statline.h>
#include <wx/listctrl.h>
#include "wxListVIewComboPopUp.h"

class SfogliaRegistroFrame : public wxFrame
{
public:
	SfogliaRegistroFrame(wxFrame* parent, vector<wxString> v, multimap<wxString, Attivit�*> registro);

private:
	wxPanel* panel;
	multimap<wxString, Attivit�*> registro;
	wxArrayString as;
	wxChoice* choiche;
	wxListBox* descrizione;

	void OnChoiceChanged(wxCommandEvent& evt);
};

