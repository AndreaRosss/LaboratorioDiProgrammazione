#pragma once
#include<wx/wx.h>
using namespace std;


class Attivit�
{
private:
	wxString Descrizione;
	wxString Data;
	wxString OraInizio;
	wxString OraFine;

public:

	Attivit�(const wxString& Descrizione, const wxString& Data, const wxString& OraInizio, const wxString& OraFine);
	~Attivit�() {};

	bool operator!=(const Attivit�& attivit�);

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


