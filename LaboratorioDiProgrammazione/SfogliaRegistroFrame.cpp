#include "Registro.h"
#include "SfogliaRegistroFrame.h"
#include <wx/combobox.h>
#include <wx/combo.h>
#include <wx/wx.h>
using namespace std;

SfogliaRegistroFrame::SfogliaRegistroFrame(wxFrame* parent,  Registro* registro) : wxFrame(parent, wxID_ANY, "Aggiungi Attivita"), registr(registro){
	panel = new wxPanel(this);
	as = registr->GetKeysToString();
	choiche = new wxChoice(panel, wxID_ANY, wxPoint(250, 10), wxSize(100,-1),as);
	descrizione = new wxListBox(panel, wxID_ANY, wxPoint(10, 80), wxSize(550, 200));
	choiche->Bind(wxEVT_CHOICE, &SfogliaRegistroFrame::OnChoiceChanged, this);
}

void SfogliaRegistroFrame::OnChoiceChanged(wxCommandEvent& evt)
{
	registr->MostraAttivitaSfogliaRegistroFrame(this);
}


