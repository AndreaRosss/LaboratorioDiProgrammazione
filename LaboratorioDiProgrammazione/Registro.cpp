#include "Registro.h"
#include "Attivit�.h"
#include "MyErrorException.h"
#include <map>
#include <iterator>
#include <vector>
using namespace std;


Registro::Registro(){}

void Registro::AggiungiAttivit�(const wxString& descrizione,const wxString& data, const wxString& orainizio, const wxString& orafine) {
	
	Attivit� attivit�(descrizione, data, orainizio, orafine);
	reg.insert({data, attivit�});
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

void Registro::MostraAttivit�SfogliaRegistroFrame(SfogliaRegistroFrame* x)
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

//TBD: questa funzione verr� utilizzata nel binding di un bottone del MainFrame.
//sar� l� che posizioneremo il blocco try. Il catche del blocco try aprir� un nuovo frame (ErrorFrame, da implementare)
//che mostrer� il messaggio con cui � stata creata l'eccezione. Successivamente la finestra che mostra l'attivit�
// mostrer� l'Attivit� Vuota. 
Attivit� Registro::RicercaAttivit�PerDescrizione(const wxString& x)
{
	for (auto it = reg.begin(); it != reg.end(); it++) {
		if (it->second.GetDescrizione().Contains(x)) {
			return it->second;
		}
	}
	throw MyErrorException("Nessuna attivit� contiene queste parole");
	return Attivit�("", "", "", ""); //crea Attivit� Vuota come oggetto globale al quale si pu� sempre accedere, per non ricrearla ogni volta.
}

//Aggiungere formato data come suggerimento
Attivit� Registro::RicercaAttivit�PerData(const wxString& x)
{
	for (auto it = reg.begin(); it != reg.end(); it++) {
		if (it->second.GetData().Contains(x)) {
			return it->second;
		}
	}
	throw MyErrorException("In questa data non sono state svolte attivit�");
	return Attivit�("", "", "", "");
}

int Registro::GetNumeroTotaleAttivit�()
{
	return reg.size();
}

int Registro::GetNumeroAttivit�DiUnGioro(const wxString& Data)
{
	return reg.count(Data);
}

void Registro::ModificaAttivit�(Attivit� attivit�)
{
	auto it = reg.begin();
	while (it != reg.end() && it->second != attivit�) {
		++it;
	}
}

void Registro::CancellaAttivit�(Attivit� attivit�)
{	
	auto it = reg.begin();
	while (it != reg.end()  && it->second != attivit�) {
		++it;
	}
	if (it != reg.end()) {
		reg.erase(it);
	}
}

