#include "MainFrame.h"
#include"AggiungiAttivit‡Frame.h"
#include <wx/wx.h>
#include "Registro.h"
#include <string>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* AggiungiAttivit‡ = new wxButton(panel, wxID_ANY, "Aggiungi Attivit‡", wxPoint(350, 250), wxSize(100, 35));
	wxButton* SfogliaRegistroAttivit‡ = new wxButton(panel, wxID_ANY, "Sfoglia Registro Attivit‡", wxPoint(300, 350), wxSize(200, 35));

	AggiungiAttivit‡->Bind(wxEVT_BUTTON, &MainFrame::ApriFrameAggiungiAttivit‡, this);

	Registro* registro = new Registro();
}

void MainFrame::ApriFrameAggiungiAttivit‡(wxCommandEvent& evt)
{
	AggiungiAttivit‡Frame* aaf = new AggiungiAttivit‡Frame(registro);
	aaf->SetClientSize(600, 400);
	aaf->Center();
	aaf->Show();
}


