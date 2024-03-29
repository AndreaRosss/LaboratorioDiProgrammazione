#include "attivit�.h"
#include "MyErrorException.h"
using namespace std;

attivit�::attivit�(const wxString& descrizione,const wxString& data, const wxString& oraInizio,const wxString& oraFine) : 
	Descrizione(descrizione), Data(data), OraInizio(oraInizio), OraFine(oraFine){

	//if (!Validit�Orari(oraInizio, oraFine)) {
		//throw MyErrorException("Impossibile creare l'attivit�. Orari Impossibili.");
	//}
}

bool attivit�::operator!=(const attivit�& attivit�)
{
	if (Descrizione.IsSameAs(attivit�.Descrizione) && Data.IsSameAs(attivit�.Data) && OraInizio.IsSameAs(attivit�.OraInizio) && OraFine.IsSameAs(attivit�.OraFine)) {
		return true;
	}
	else return false;
}

bool attivit�::Validit�Orari(const wxString& a, const wxString& b)
{	
	wxDateTime Inizio, Fine;
	Inizio.ParseFormat(a, "%H:%M:%S");
	Fine.ParseFormat(b, "%H:%M:%S");
	if (Inizio < Fine) {
		return true;
	}
	else false;
}
