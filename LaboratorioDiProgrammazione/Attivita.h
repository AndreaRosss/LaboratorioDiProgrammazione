#pragma once
#include<wx/wx.h>
using namespace std;

#ifndef UNIT_TESTING_ATTIVITA_H
#define UNIT_TESTING_ATTIVITA_H

class Attivita
{
private:
	wxString Descrizione;
	wxString Data;
	wxString OraInizio;
	wxString OraFine;

public:

	Attivita(const wxString& Descrizione, const wxString& Data, const wxString& OraInizio, const wxString& OraFine);
	~Attivita() {};

	bool operator!=(const Attivita& Attivita);

	bool ValiditàOrari(const wxString& a, const wxString& b);

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

	void SetData(const wxString& Data) {
		this->Data = Data;
	}

	void SetDescrizione(const wxString& Descrizione) {
		this->Descrizione = Descrizione;
	}

	void SetOraInizio(const wxString& OraInizio) {
		this->OraInizio = OraInizio;
	}

	void SetOraFine(const wxString& OraFine) {
		this->OraFine = OraFine;
	}
};

#endif // !UNIT_TESTING_ATTIVITA_H



