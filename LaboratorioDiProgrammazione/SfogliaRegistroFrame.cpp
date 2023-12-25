#include "SfogliaRegistroFrame.h"
#include <wx/wx.h>

SfogliaRegistroFrame::SfogliaRegistroFrame(vector<wxString> v, Registro* registro) : wxFrame(nullptr, wxID_ANY, "Aggiungi Attività")
{
	panel = new wxPanel(this);
	this->registro = registro;
	for (int i = 0; i < v.size(); i++) {
		as.Add(v[i]);
	}
	choiche = new wxChoice(panel, wxID_ANY, wxPoint(250, 10), wxSize(100, -1), as);
}
