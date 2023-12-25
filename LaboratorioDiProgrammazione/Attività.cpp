#include "Attività.h"
using namespace std;

Attività::Attività(wxString Descrizione, wxString Data, wxString OraInizio, wxString OraFine)
{
	this->Descrizione = Descrizione;
	this->Data = Data;
	this->OraInizio = OraInizio;
	this->OraFine = OraFine;
}
