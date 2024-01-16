#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attivitą.h"
#include "SfogliaRegistroFrame.h"
using namespace std;



class Registro
{
private:

	multimap <wxString, Attivitą> reg;

public:
	Registro();

	void AggiungiAttivitą(const wxString& descrizione, const wxString& data, const wxString& orainizio, const wxString& orafine);

	bool CheckKey(const vector<wxString>& v,const wxString& k);

	void MostraAttivitąSfogliaRegistroFrame(SfogliaRegistroFrame* x);

	vector<wxString> GetKeys();

	wxArrayString GetKeysToString();

	Attivitą RicercaAttivitąPerDescrizione(const wxString& x);

	Attivitą RicercaAttivitąPerData(const wxString& x);

	int GetNumeroTotaleAttivitą();

	int GetNumeroAttivitąDiUnGioro(const wxString& data);

	void ModificaAttivitą(Attivitą attivitą);

	void CancellaAttivitą(Attivitą attivitą);

};


