#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attivit�.h"

class Registro
{
	multimap <wxString, Attivit�*> registro;

public:
	Registro();

	void AggiungiAttivit�(Attivit�* attivit�);

	bool CheckKey(vector<wxString> v, wxString k);

	vector<wxString> GetKeys();
};

