#pragma once
#include <string>
#include <iostream>
using namespace std;

class Attività
{
	string Descrizione;
	int Data;
	int OraInizio;
	int OraFine;

public:
	Attività() {
		cin >> Descrizione;
		cin >> Data;
		cin >> OraInizio;
		cin >> OraFine;
	}

	int GetData() {
		return this->Data;
	}
};

