#include "pch.h"
#include <wx/wx.h>
#include "../LaboratorioDiProgrammazione/Registro.h"
#include "C:\Users\andre\source\repos\LaboratorioDiProgrammazione\LaboratorioDiProgrammazione\Registro.cpp"
#include "../LaboratorioDiProgrammazione/Attivita.h"

class RegistroSuite : public ::testing :: Test{

protected:
	virtual void SetUp() {

		wxString a = "Test Attivita";
		wxString b = "17-01-2024";
		wxString c = "16:42";
		wxString d = "17:43";

		r.AggiungiAttivita(a, b, c, d);

	}
	Registro r;
};

TEST_F(RegistroSuite, TestRicercaPerDescrizione) {
	
	Attivita att = r.RicercaAttivitaPerDescrizione("Test Attivita");
	ASSERT_EQ(att.GetDescrizione(), "Test Attivita");
	ASSERT_EQ(att.GetData(), "17-01-2024");
	ASSERT_EQ(att.GetOraInizio(), "16:42");
	ASSERT_EQ(att.GetOraFine(), "17:43");
	
}

TEST_F(RegistroSuite, TestRicercaPerData) {

	Attivita att = r.RicercaAttivitaPerData("17-01-2024");
	ASSERT_EQ(att.GetDescrizione(), "Test Attivita");
	ASSERT_EQ(att.GetData(), "17-01-2024");
	ASSERT_EQ(att.GetOraInizio(), "16:42");
	ASSERT_EQ(att.GetOraFine(), "17:43");

}


