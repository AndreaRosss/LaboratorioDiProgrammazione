#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attivit�.h"

class Registro
{
	multimap <int, Attivit�*> registro;

public:
	Registro();

	void AggiungiAttivit�(Attivit�* attivit�);

	bool CheckKey(vector<int> v, int k);

	vector<int> GetKeys();
};

