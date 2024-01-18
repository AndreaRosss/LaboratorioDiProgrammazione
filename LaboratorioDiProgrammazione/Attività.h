#pragma once
#include<wx/wx.h>
using namespace std;

#ifndef UNIT_TESTING_attivit�_H
#define UNIT_TESTING_attivit�_H

class attivit�
{
private:
	wxString Descrizione;
	wxString Data;
	wxString OraInizio;
	wxString OraFine;

public:

	attivit�(const wxString& Descrizione, const wxString& Data, const wxString& OraInizio, const wxString& OraFine);
	~attivit�() {};

	bool operator!=(const attivit�& attivit�);

	bool Validit�Orari(const wxString& a, const wxString& b);

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

#endif // !UNIT_TESTING_attivit�_H



