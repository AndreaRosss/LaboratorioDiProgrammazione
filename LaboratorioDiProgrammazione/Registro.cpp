#include "Registro.h"
#include <map>
using namespace std;

Registro::Registro(){}

void Registro::AggiungiAttività() {
	Attività* attività = new Attività;
	registro.insert({ attività->GetData(), attività });
}
