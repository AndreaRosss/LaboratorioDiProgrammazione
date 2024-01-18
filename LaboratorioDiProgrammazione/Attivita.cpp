#include "Attivita.h"
#include "MyErrorException.h"
using namespace std;

Attivita::Attivita(const wxString& descrizione,const wxString& data, const wxString& oraInizio,const wxString& oraFine) : 
	Descrizione(descrizione), Data(data), OraInizio(oraInizio), OraFine(oraFine){

	//if (!Validit‡Orari(oraInizio, oraFine)) {
		//throw MyErrorException("Impossibile creare l'Attivita. Orari Impossibili.");
	//}
}

bool Attivita::operator!=(const Attivita& Attivita)
{
	if (Descrizione.IsSameAs(Attivita.Descrizione) && Data.IsSameAs(Attivita.Data) && OraInizio.IsSameAs(Attivita.OraInizio) && OraFine.IsSameAs(Attivita.OraFine)) {
		return true;
	}
	else return false;
}

bool Attivita::Validit‡Orari(const wxString& a, const wxString& b)
{	
	wxDateTime Inizio, Fine;
	Inizio.ParseFormat(a, "%H:%M:%S");
	Fine.ParseFormat(b, "%H:%M:%S");
	if (Inizio < Fine) {
		return true;
	}
	else false;
}
