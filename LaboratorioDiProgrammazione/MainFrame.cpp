#include "MainFrame.h"
#include "Registro.h"
#include "AggiungiAttivitaFrame.h"
#include "SfogliaRegistroFrame.h"
#include <wx/wx.h>
#include <string>
using namespace std;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* AggiungiAttivita = new wxButton(panel, wxID_ANY, "Aggiungi Attivita", wxPoint(350, 250), wxSize(100, 35));
	wxButton* SfogliaRegistroAttivita = new wxButton(panel, wxID_ANY, "Sfoglia Registro Attivita", wxPoint(300, 350), wxSize(200, 35));

	AggiungiAttivita->Bind(wxEVT_BUTTON, &MainFrame::ApriFrameAggiungiAttivita, this);
	SfogliaRegistroAttivita->Bind(wxEVT_BUTTON, &MainFrame::ApriFrameSfogliaRegistro, this);

	registro = Registro();
}

void MainFrame::ApriFrameAggiungiAttivita(wxCommandEvent& evt)
{	
	AggiungiAttivitaFrame* aaf = new AggiungiAttivitaFrame(this, &registro);
	aaf->SetClientSize(600, 400);
	aaf->Center();
	aaf->Show();
}

void MainFrame::ApriFrameSfogliaRegistro(wxCommandEvent& evt)
{
	SfogliaRegistroFrame* srf = new SfogliaRegistroFrame(this, &registro);
	srf->SetClientSize(600, 400);
	srf->Center();
	srf->Show();
}


