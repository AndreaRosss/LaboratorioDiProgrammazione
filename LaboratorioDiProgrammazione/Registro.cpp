#include "Registro.h"
#include "Attività.h"
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

