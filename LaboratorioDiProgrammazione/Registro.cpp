#include "Registro.h"
#include <map>
#include <iterator>
#include <vector>
using namespace std;

Registro::Registro(){}

void Registro::AggiungiAttivit�(Attivit�* attivit�) {
	
	registro.insert({ attivit�->GetData(), attivit� });
}



bool Registro::CheckKey(vector<int> v, int k)
{
	for (int i = 0; i < v.size(); i++) {
		if (k == v[i]) {
			return false;
		}
	}
	return true;
}

vector<int> Registro::GetKeys()
{
	vector<int> Chiavi;
	for (auto it = registro.begin(); it != registro.end(); it++) {

		if (CheckKey(Chiavi, it->first)) {

			Chiavi.push_back(it->first);
		}
	}
	return Chiavi;
}
