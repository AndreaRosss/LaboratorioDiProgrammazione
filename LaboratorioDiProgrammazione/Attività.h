#pragma once
#include<wx/wx.h>
using namespace std;


class Attività
{
	wxString Descrizione;
	wxString Data;
	wxString OraInizio;
	wxString OraFine;

public:
	Attività(const wxString& Descrizione, const wxString& Data, const wxString& OraInizio, const wxString& OraFine);


	wxString GetData() {
		return this->Data;
	}

	wxString GetDescrizione() {
		return this->Descrizione;
	}

	wxString GetOraInizio() {
		return this->OraInizio;
	}

	wxString GetOraFine() {
		return this->OraFine;
	}
};


