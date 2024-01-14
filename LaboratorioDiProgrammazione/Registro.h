#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attivit�.h"

class Registro
{
public:

	multimap <wxString, Attivit�> registro;

public:
	Registro();

	void AggiungiAttivit�(const wxString descrizione, const wxString data, const wxString orainizio, const wxString orafine);

	bool CheckKey(vector<wxString> v, wxString k);

	vector<wxString> GetKeys();

	multimap <wxString, Attivit�> GetRegistro() {
		return this->registro;
	}
	
};

