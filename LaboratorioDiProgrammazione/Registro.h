#pragma once
#include <string>
#include<map>
#include"Attività.h"

class Registro
{
	multimap <int, Attività*> registro;

public:
	Registro();

	void AggiungiAttività();
};

