#pragma once
#include <wx/wx.h>
#include <wx/calctrl.h>
#include <wx/datectrl.h>
#include <wx/timectrl.h>
#include <wx/datetime.h>
#include <string>
#include "Registro.h"
using namespace std;

class AggiungiAttivit‡Frame : public wxFrame 
{
public: 
	AggiungiAttivit‡Frame(Registro* registro);
private:

	wxPanel* panel;
	wxStaticText* campo1;
	wxDatePickerCtrl* Data;
	wxStaticText* campo2;
	wxTimePickerCtrl* oraInizio;
	wxStaticText* campo3;
	wxTimePickerCtrl* oraFine;
	wxStaticText* campo4;
	wxTextCtrl* SezioneDescrizione;
	wxButton* aggiungiAttivit‡;

	Registro* registro;

	void AggiungiAttivit‡();
};

