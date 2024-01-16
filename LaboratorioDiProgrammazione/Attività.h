#pragma once
#include<wx/wx.h>
using namespace std;


class Attività
{
private:
	wxString Descrizione;
	wxString Data;
	wxString OraInizio;
	wxString OraFine;

public:

	Attività(const wxString& Descrizione, const wxString& Data, const wxString& OraInizio, const wxString& OraFine);
	~Attività() {};

	bool operator!=(const Attività& attività);

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


