#include "pch.h"
#include <wx/wx.h>
#include "../LaboratorioDiProgrammazione/Attivita.h"
#include "C:\Users\andre\source\repos\LaboratorioDiProgrammazione\LaboratorioDiProgrammazione\Attivita.cpp"



TEST(Attivita, CheckValidit‡Orari) {

	wxString a = "Test Attivita";
	wxString b = "17-01-2024";
	wxString c = "16:42";
	wxString d = "17:43";
	wxString e = "16:43";
	Attivita att(a, b, c, d);
	ASSERT_FALSE(att.Validit‡Orari(d, c));
	ASSERT_FALSE(att.Validit‡Orari(e, c));
	ASSERT_TRUE(att.Validit‡Orari(c, e));
	ASSERT_TRUE(att.Validit‡Orari(c, d));
}

TEST(Attivita, MyConstructor) {
	
	wxString a = "Test Attivita";
	wxString b = "17-01-2024";
	wxString c = "16:42";
	wxString d = "17:43";
	Attivita att(a, b, c, d);
	ASSERT_EQ(a, att.GetDescrizione());
	ASSERT_EQ(b, att.GetData());
	ASSERT_EQ(c, att.GetOraInizio());
	ASSERT_EQ(d, att.GetOraFine());

}

TEST(Attivita, SovraccaricamentoOperatore ) {
	wxString a = "Test Attivita";
	wxString b = "17-01-2024";
	wxString c = "16:42";
	wxString d = "17:43";

	wxString e = "Test Attivit";
	wxString f = "18-01-2024";
	wxString g = "16:43";
	wxString h = "17:44";

	Attivita att1(a, b, c, d);
	Attivita att2(e, b, c, d);
	Attivita att3(a, f, c, d);
	Attivita att4(a, b, g, d);
	Attivita att5(a, b, c, h);
	Attivita att6(a, b, c, d);

	ASSERT_TRUE(att1 != att2);
	ASSERT_TRUE(att1 != att3);
	ASSERT_TRUE(att1 != att4);
	ASSERT_TRUE(att1 != att5);
	ASSERT_FALSE(att1 != att6);

}

