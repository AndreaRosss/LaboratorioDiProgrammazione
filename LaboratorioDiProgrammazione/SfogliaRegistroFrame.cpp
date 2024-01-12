#include "SfogliaRegistroFrame.h"
#include <wx/combobox.h>
#include <wx/combo.h>
#include <wx/wx.h>

SfogliaRegistroFrame::SfogliaRegistroFrame(wxFrame* parent, vector<wxString> v, multimap<wxString, Attività*> registro) : wxFrame(parent, wxID_ANY, "Aggiungi Attività")
{
	panel = new wxPanel(this);
	this->registro = registro;
	for (int i = 0; i < v.size(); i++) {
		as.Add(v[i]);
	}
	choiche = new wxChoice(panel, wxID_ANY, wxPoint(250, 10), wxSize(100,-1), as);
	descrizione = new wxListBox(panel, wxID_ANY, wxPoint(10, 80), wxSize(550, 200));
	choiche->Bind(wxEVT_CHOICE, &SfogliaRegistroFrame::OnChoiceChanged, this);
}

void SfogliaRegistroFrame::OnChoiceChanged(wxCommandEvent& evt)
{

	descrizione->Clear();
	for (auto it = registro.begin(); it != registro.end(); it++) {
		descrizione->Insert(choiche->GetStringSelection(), descrizione->GetCount());
		if (it->first.IsSameAs(choiche->GetStringSelection())) {
			descrizione->Insert((it->second->GetOraInizio()).ToStdString(), descrizione->GetCount());
			descrizione->Insert(it->second->GetDescrizione().ToStdString(), descrizione->GetCount());
			descrizione->Insert(it->second->GetOraFine().ToStdString(), descrizione->GetCount());
			descrizione->Insert("", descrizione->GetCount());
		}
	}
}


