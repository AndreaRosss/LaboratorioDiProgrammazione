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

	bool CheckKey(const vector<wxString>& v, const wxString& k) const;

public:

	Registro();

	void AggiungiAttivita(const wxString& descrizione, const wxString& data, const wxString& orainizio, const wxString& orafine);

	vector<wxString> GetKeys() const;

	void MostraAttivitaSfogliaRegistroFrame(SfogliaRegistroFrame* x);

	Attivita RicercaAttivitaPerDescrizione(const wxString& x) const;

	Attivita RicercaAttivitaPerData(const wxString& x) const;

	int GetNumeroTotaleAttivita() const;

	int GetNumeroAttivitaDiUnGioro(const wxString& data) const;

	void ModificaAttivita(Attivita& Attivita,const wxString& NuovaDescrizione);

	void CancellaAttivita(Attivita Attivita);

};
#endif // !UNIT_TESTING_REGISTRO_H

