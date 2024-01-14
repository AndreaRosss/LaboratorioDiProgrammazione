#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attività.h"

class Registro
{
public:

	multimap <wxString, Attività> registro;

public:
	Registro();

	void AggiungiAttività(const wxString descrizione, const wxString data, const wxString orainizio, const wxString orafine);

	bool CheckKey(vector<wxString> v, wxString k);

	vector<wxString> GetKeys();

	multimap <wxString, Attività> GetRegistro() {
		return this->registro;
	}
	
};

