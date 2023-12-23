#include "AggiungiAttivit‡Frame.h"
#include <wx/wx.h>
#include <wx/calctrl.h>
#include <wx/datectrl.h>
#include <wx/timectrl.h>

#include <string>
using namespace std;

AggiungiAttivit‡Frame::AggiungiAttivit‡Frame() : wxFrame(nullptr, wxID_ANY, "Aggiungi Attivit‡") {
	wxPanel* panel = new wxPanel(this);

	wxStaticText* campo2 = new wxStaticText(panel, wxID_ANY, "Data:", wxPoint(10, 10), wxSize(100, 100));
	wxDatePickerCtrl* Data = new wxDatePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxPoint(50, 10), wxDefaultSize, 4L);

	wxStaticText* campo3 = new wxStaticText(panel, wxID_ANY, "OraInizio:", wxPoint(200, 10), wxSize(100, 100));
	wxTimePickerCtrl* oraInizio = new wxTimePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxPoint(250, 10), wxDefaultSize, 0L);

	wxStaticText* campo4 = new wxStaticText(panel, wxID_ANY, "OraFine:", wxPoint(350, 10), wxSize(100, 100));
	wxTimePickerCtrl* oraFine = new wxTimePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxPoint(400, 10), wxDefaultSize, 0L);

	wxStaticText* campo1 = new wxStaticText(panel, wxID_ANY, "Descrizione:", wxPoint(10, 50), wxSize(100, 100));
	wxTextCtrl* SezioneDescrizione = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 75), wxSize(580, 150));

	wxButton* aggiungiAttivit‡ = new wxButton(panel, wxID_ANY, "Aggiungi Attivit‡", wxPoint(225, 300), wxSize(150, -1));

}

