#pragma once
#include <string>
#include <iostream>
using namespace std;

class Attivit�
{
	string Descrizione;
	int Data;
	string OraInizio;
	string OraFine;

public:
	Attivit�(string Descrizione, int Data, string OraInizio, string OraFine);
		

	int GetData() {
		return this->Data;
	}
};

