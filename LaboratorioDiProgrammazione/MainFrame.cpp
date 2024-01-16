#include "MainFrame.h"
#include "Registro.h"
#include "AggiungiAttivit‡Frame.h"
#include "SfogliaRegistroFrame.h"
#include <wx/wx.h>
#include <string>
using namespace std;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* AggiungiAttivit‡ = new wxButton(panel, wxID_ANY, "Aggiungi Attivit‡", wxPoint(350, 250), wxSize(100, 35));
	wxButton* SfogliaRegistroAttivit‡ = new wxButton(panel, wxID_ANY, "Sfoglia Registro Attivit‡", wxPoint(300, 350), wxSize(200, 35));

	AggiungiAttivit‡->Bind(wxEVT_BUTTON, &MainFrame::ApriFrameAggiungiAttivit‡, this);
	SfogliaRegistroAttivit‡->Bind(wxEVT_BUTTON, &MainFrame::ApriFrameSfogliaRegistro, this);

	registro = Registro();
}

void MainFrame::ApriFrameAggiungiAttivit‡(wxCommandEvent& evt)
{	
	AggiungiAttivit‡Frame* aaf = new AggiungiAttivit‡Frame(this, &registro);
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


