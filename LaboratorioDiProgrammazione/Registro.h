#pragma once
#include <string>
#include<map>
#include"Attivit�.h"

class Registro
{
	multimap <int, Attivit�*> registro;

public:
	Registro();

	void AggiungiAttivit�();
};

