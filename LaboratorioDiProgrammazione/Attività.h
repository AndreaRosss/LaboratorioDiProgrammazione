#pragma once
#include <string>
#include <iostream>
using namespace std;

class Attivit�
{
	string Descrizione;
	int Data;
	int OraInizio;
	int OraFine;

public:
	Attivit�() {
		cin >> Descrizione;
		cin >> Data;
		cin >> OraInizio;
		cin >> OraFine;
	}

	int GetData() {
		return this->Data;
	}
};

