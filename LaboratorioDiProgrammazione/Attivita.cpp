#include "Attivita.h"
#include "MyErrorException.h"
using namespace std;

Attivita::Attivita(const wxString& descrizione,const wxString& data, const wxString& oraInizio,const wxString& oraFine) : 
	Descrizione(descrizione), Data(data), OraInizio(oraInizio), OraFine(oraFine){

	if (!ValiditaOrari(oraInizio, oraFine)) {
		throw MyErrorException("Impossibile creare l'Attivita. Orari Impossibili.");
	}
}

bool Attivita::operator!=(const Attivita& Attivita) const
{
	if (Descrizione.IsSameAs(Attivita.Descrizione) && Data.IsSameAs(Attivita.Data) && OraInizio.IsSameAs(Attivita.OraInizio) && OraFine.IsSameAs(Attivita.OraFine)) {
		return false;
	}
	else return true;
}

bool Attivita::ValiditaOrari(const wxString& a, const wxString& b)
{	
	wxDateTime Inizio, Fine;
	Inizio.ParseTime(a);
	Fine.ParseTime(b);
	if (Inizio.GetHour() < Fine.GetHour()) {
		return true;
	}
	else {
		if (Inizio.GetHour() == Fine.GetHour()) {
			if (Inizio.GetMinute() < Fine.GetMinute()) {
				return true;
			}
		}
	}
	return false;
}
