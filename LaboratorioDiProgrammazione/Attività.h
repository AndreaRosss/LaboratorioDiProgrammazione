#pragma once
#include <string>
#include <iostream>
using namespace std;

class Attività
{
	string Descrizione;
	int Data;
	string OraInizio;
	string OraFine;

public:
	Attività(string Descrizione, int Data, string OraInizio, string OraFine);
		

	int GetData() {
		return this->Data;
	}
};

