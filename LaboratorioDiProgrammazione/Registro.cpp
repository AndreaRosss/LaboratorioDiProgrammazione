#include "Registro.h"
#include <map>
using namespace std;

Registro::Registro(){}

void Registro::AggiungiAttivit�(Attivit�* attivit�) {
	
	registro.insert({ attivit�->GetData(), attivit� });
}
