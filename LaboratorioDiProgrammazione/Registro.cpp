#include "Registro.h"
#include "Attivita.h"
#include "MyErrorException.h"
#include <map>
#include <iterator>
#include <vector>
using namespace std;


Registro::Registro(){}

void Registro::AggiungiAttivita(const wxString& descrizione,const wxString& data, const wxString& orainizio, const wxString& orafine) {
	
	Attivita Attivita(descrizione, data, orainizio, orafine);
	reg.insert({data, Attivita});
}



bool Registro::CheckKey(const vector<wxString>& v,const wxString& k) const
{
	for (int i = 0; i < v.size(); i++) {
		if (k == v[i]) {
			return false;
		}
	}
	return true;
}

void Registro::MostraAttivitaSfogliaRegistroFrame(SfogliaRegistroFrame* x)
{	
	x->GetDescrizione()->Clear();
	auto it = reg.begin();
	for (it; it != reg.end(); it++) {
		x->GetDescrizione()->Insert(x->GetChoice()->GetStringSelection(), x->GetDescrizione()->GetCount());
		if (it->first.IsSameAs(x->GetChoice()->GetStringSelection())) {
			x->GetDescrizione()->Insert((it->second.GetOraInizio()).ToStdString(), x->GetDescrizione()->GetCount());
			x->GetDescrizione()->Insert(it->second.GetDescrizione().ToStdString(), x->GetDescrizione()->GetCount());
			x->GetDescrizione()->Insert(it->second.GetOraFine().ToStdString(), x->GetDescrizione()->GetCount());
			x->GetDescrizione()->Insert("", x->GetDescrizione()->GetCount());
		}
	}
}

vector<wxString> Registro::GetKeys() const
{
	vector<wxString> Chiavi;
	for (auto it = reg.begin(); it != reg.end(); it++) {

		if (CheckKey(Chiavi, it->first)) {

			Chiavi.push_back(it->first);
		}
	}
	return Chiavi;
}

//TBD: questa funzione verrà utilizzata nel binding di un bottone del MainFrame.
//sarà lì che posizioneremo il blocco try. Il catche del blocco try aprirà un nuovo frame (ErrorFrame, da implementare)
//che mostrerà il messaggio con cui è stata creata l'eccezione. Successivamente la finestra che mostra l'Attivita
// mostrerà l'Attivita Vuota. 
Attivita Registro::RicercaAttivitaPerDescrizione(const wxString& x) const
{
	for (auto it = reg.begin(); it != reg.end(); it++) {
		if (it->second.GetDescrizione().Contains(x)) {
			return it->second;
		}
	}
	throw MyErrorException("Nessuna Attivita contiene queste parole");
	return Attivita("", "", "", ""); //crea Attivita Vuota come oggetto globale al quale si può sempre accedere, per non ricrearla ogni volta.
}

//Aggiungere formato data come suggerimento
Attivita Registro::RicercaAttivitaPerData(const wxString& x) const
{
	for (auto it = reg.begin(); it != reg.end(); it++) {
		if (it->second.GetData().Contains(x)) {
			return it->second;
		}
	}
	throw MyErrorException("In questa data non sono state svolte Attivita");
	return Attivita("", "", "", "");
}

int Registro::GetNumeroTotaleAttivita() const
{
	return reg.size();
}

int Registro::GetNumeroAttivitaDiUnGioro(const wxString& Data) const
{
	return reg.count(Data);
}

void Registro::ModificaAttivita(Attivita& Attivita,const wxString& NuovaDescrizione)
{
	Attivita.SetDescrizione(NuovaDescrizione);
}

void Registro::CancellaAttivita(Attivita Attivita)
{	
	auto it = reg.begin();
	while (it != reg.end()  && it->second != Attivita) {
		++it;
	}
	if (it != reg.end()) {
		reg.erase(it);
	}
}

