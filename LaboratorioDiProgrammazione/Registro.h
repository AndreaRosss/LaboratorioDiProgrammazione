#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attività.h"

class Registro
{
	multimap <wxString, Attività*> registro;

public:
	Registro();

	void AggiungiAttività(Attività* attività);

	bool CheckKey(vector<wxString> v, wxString k);

	vector<wxString> GetKeys();
};

