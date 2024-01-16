#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attività.h"
#include "SfogliaRegistroFrame.h"
using namespace std;



class Registro
{
public:

	multimap <wxString, Attività> reg;

public:
	Registro();

	void AggiungiAttività(const wxString& descrizione, const wxString& data, const wxString& orainizio, const wxString& orafine);

	bool CheckKey(const vector<wxString>& v,const wxString& k);

	void MostraAttivitàSfogliaRegistroFrame(SfogliaRegistroFrame* x);

	vector<wxString> GetKeys();

	wxArrayString GetKeysToString();

	Attività RicercaAttivitàPerDescrizione(const wxString& x);

	void ModificaAttività();

	void CancellaAttività();

};


