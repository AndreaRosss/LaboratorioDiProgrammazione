#pragma once
#include <string>
#include<map>
#include <vector>
#include"Attività.h"

class Registro
{
	multimap <int, Attività*> registro;

public:
	Registro();

	void AggiungiAttività(Attività* attività);

	bool CheckKey(vector<int> v, int k);

	vector<int> GetKeys();
};

