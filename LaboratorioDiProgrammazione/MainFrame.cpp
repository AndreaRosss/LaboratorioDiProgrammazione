#include "MainFrame.h"
#include "Registro.h"
#include "AggiungiAttivitàFrame.h"
#include "SfogliaRegistroFrame.h"
#include <wx/wx.h>
#include <string>
using namespace std;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* AggiungiAttività = new wxButton(panel, wxID_ANY, "Aggiungi Attività", wxPoint(350, 250), wxSize(100, 35));
	wxButton* SfogliaRegistroAttività = new wxButton(panel, wxID_ANY, "Sfoglia Registro Attività", wxPoint(300, 350), wxSize(200, 35));

	AggiungiAttività->Bind(wxEVT_BUTTON, &MainFrame::ApriFrameAggiungiAttività, this);
	SfogliaRegistroAttività->Bind(wxEVT_BUTTON, &MainFrame::ApriFrameSfogliaRegistro, this);

	registro = Registro();
}

void MainFrame::ApriFrameAggiungiAttività(wxCommandEvent& evt)
{	
	AggiungiAttivitàFrame* aaf = new AggiungiAttivitàFrame(this, &registro);
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


