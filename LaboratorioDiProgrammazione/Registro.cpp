#include "Registro.h"
#include <map>
#include <iterator>
#include <vector>
using namespace std;

Registro::Registro(){}

void Registro::AggiungiAttività(const wxString descrizione,const wxString data, const wxString orainizio, const wxString orafine) {

	Attività attività(descrizione, data, orainizio, orafine);
	registro.insert({data, attività});
}



bool Registro::CheckKey(vector<wxString> v, wxString k)
{
	for (int i = 0; i < v.size(); i++) {
		if (k == v[i]) {
			return false;
		}
	}
	return true;
}

vector<wxString> Registro::GetKeys()
{
	vector<wxString> Chiavi;
	for (auto it = registro.begin(); it != registro.end(); it++) {

		if (CheckKey(Chiavi, it->first)) {

			Chiavi.push_back(it->first);
		}
	}
	return Chiavi;
}
