#include "MainFrame.h"
#include <wx/wx.h>
#include <string>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title){
	wxPanel* panel = new wxPanel(this);
	wxButton* button1 = new wxButton(panel, wxID_ANY, "Aggiungi Attività", wxPoint(350, 250), wxSize(100, 35));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Sfoglia Registro Attività", wxPoint(300, 350), wxSize(200, 35));
}
