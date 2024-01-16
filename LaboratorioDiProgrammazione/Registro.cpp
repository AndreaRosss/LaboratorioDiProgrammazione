#include "Registro.h"
#include "Attività.h"
#include "MyErrorException.h"
#include <map>
#include <iterator>
#include <vector>
using namespace std;


Registro::Registro(){}

void Registro::AggiungiAttività(const wxString& descrizione,const wxString& data, const wxString& orainizio, const wxString& orafine) {
	
	Attività attività(descrizione, data, orainizio, orafine);
	reg.insert({data, attività});
}



bool Registro::CheckKey(const vector<wxString>& v,const wxString& k)
{
	for (int i = 0; i < v.size(); i++) {
		if (k == v[i]) {
			return false;
		}
	}
	return true;
}

void Registro::MostraAttivitàSfogliaRegistroFrame(SfogliaRegistroFrame* x)
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

vector<wxString> Registro::GetKeys()
{
	vector<wxString> Chiavi;
	for (auto it = reg.begin(); it != reg.end(); it++) {

		if (CheckKey(Chiavi, it->first)) {

			Chiavi.push_back(it->first);
		}
	}
	return Chiavi;
}

wxArrayString Registro::GetKeysToString()
{
	wxArrayString as;
	vector<wxString> Chiavi = GetKeys();
	for (int i = 0; i < Chiavi.size(); i++) {
		as.Add(Chiavi[i]);
	}
	return as;
}

//TBD: questa funzione verrà utilizzata nel binding di un bottone del MainFrame.
//sarà lì che posizioneremo il blocco try. Il catche del blocco try aprirà un nuovo frame (ErrorFrame, da implementare)
//che mostrerà il messaggio con cui è stata creata l'eccezione. Successivamente la finestra che mostra l'attività
// mostrerà l'Attività Vuota. 
Attività Registro::RicercaAttivitàPerDescrizione(const wxString& x)
{
	for (auto it = reg.begin(); it != reg.end(); it++) {
		if (it->second.GetDescrizione().Contains(x)) {
			return it->second;
		}
	}
	throw MyErrorException("Nessuna attività contiene queste parole");
	return Attività("", "", "", ""); //crea Attività Vuota come oggetto globale al quale si può sempre accedere, per non ricrearla ogni volta.
}

//Aggiungere formato data come suggerimento
Attività Registro::RicercaAttivitàPerData(const wxString& x)
{
	for (auto it = reg.begin(); it != reg.end(); it++) {
		if (it->second.GetData().Contains(x)) {
			return it->second;
		}
	}
	throw MyErrorException("In questa data non sono state svolte attività");
	return Attività("", "", "", "");
}

int Registro::GetNumeroTotaleAttività()
{
	return reg.size();
}

int Registro::GetNumeroAttivitàDiUnGioro(const wxString& Data)
{
	return reg.count(Data);
}

void Registro::ModificaAttività(Attività attività)
{
	auto it = reg.begin();
	while (it != reg.end() && it->second != attività) {
		++it;
	}
}

void Registro::CancellaAttività(Attività attività)
{	
	auto it = reg.begin();
	while (it != reg.end()  && it->second != attività) {
		++it;
	}
	if (it != reg.end()) {
		reg.erase(it);
	}
}

