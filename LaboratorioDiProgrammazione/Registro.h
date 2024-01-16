#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attivit‡.h"
#include "SfogliaRegistroFrame.h"
using namespace std;



class Registro
{
private:

	multimap <wxString, Attivit‡> reg;

public:
	Registro();

	void AggiungiAttivit‡(const wxString& descrizione, const wxString& data, const wxString& orainizio, const wxString& orafine);

	bool CheckKey(const vector<wxString>& v,const wxString& k);

	void MostraAttivit‡SfogliaRegistroFrame(SfogliaRegistroFrame* x);

	vector<wxString> GetKeys();

	wxArrayString GetKeysToString();

	Attivit‡ RicercaAttivit‡PerDescrizione(const wxString& x);

	Attivit‡ RicercaAttivit‡PerData(const wxString& x);

	int GetNumeroTotaleAttivit‡();

	int GetNumeroAttivit‡DiUnGioro(const wxString& data);

	void ModificaAttivit‡(Attivit‡ attivit‡);

	void CancellaAttivit‡(Attivit‡ attivit‡);

};


