#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attivita.h"
#include "SfogliaRegistroFrame.h"
using namespace std;


#ifndef UNIT_TESTING_REGISTRO_H
#define UNIT_TESTING_REGISTRO_H


class Registro
{
private:

	multimap <wxString, Attivita> reg;

public:
	Registro();

	void AggiungiAttivita(const wxString& descrizione, const wxString& data, const wxString& orainizio, const wxString& orafine);

	bool CheckKey(const vector<wxString>& v,const wxString& k);

	void MostraAttivitaSfogliaRegistroFrame(SfogliaRegistroFrame* x);

	vector<wxString> GetKeys();

	wxArrayString GetKeysToString();

	Attivita RicercaAttivitaPerDescrizione(const wxString& x);

	Attivita RicercaAttivitaPerData(const wxString& x);

	int GetNumeroTotaleAttivita();

	int GetNumeroAttivitaDiUnGioro(const wxString& data);

	void ModificaAttivita(Attivita Attivita);

	void CancellaAttivita(Attivita Attivita);

};
#endif // !UNIT_TESTING_REGISTRO_H

