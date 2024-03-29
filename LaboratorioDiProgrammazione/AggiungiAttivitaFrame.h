#pragma once
#include "Registro.h"
#include <wx/wx.h>
#include <wx/calctrl.h>
#include <wx/datectrl.h>
#include <wx/timectrl.h>
#include <wx/datetime.h>
using namespace std;

class Registro;

class AggiungiAttivitaFrame : public wxFrame
{
public:
	AggiungiAttivitaFrame(wxFrame* parent, Registro* registro);

private:

	Registro* registro;
	wxPanel* panel;
	wxDateTime* a;
	wxStaticText* campo1;
	wxDatePickerCtrl* Data;
	wxStaticText* campo2;
	wxTimePickerCtrl* oraInizio;
	wxStaticText* campo3;
	wxTimePickerCtrl* oraFine;
	wxStaticText* campo4;
	wxTextCtrl* SezioneDescrizione;
	wxButton* aggiungiAttivita;

public:
	void AggiungiAttivita(wxCommandEvent& evt);
};



