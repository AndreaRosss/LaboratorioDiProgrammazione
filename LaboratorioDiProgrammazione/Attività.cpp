#include "Attività.h"
using namespace std;

Attività::Attività(const wxString& descrizione,const wxString& data, const wxString& oraInizio,const wxString& oraFine) : 
	Descrizione(descrizione), Data(data), OraInizio(oraInizio), OraFine(oraFine){}
