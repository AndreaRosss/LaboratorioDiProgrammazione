#include "AggiungiAttivit‡Frame.h"
#include <wx/wx.h>
#include <wx/calctrl.h>
#include <wx/datectrl.h>
#include <wx/timectrl.h>
#include <wx/datetime.h>
#include <string>
using namespace std;

AggiungiAttivit‡Frame::AggiungiAttivit‡Frame(Registro* registro) : wxFrame(nullptr, wxID_ANY, "Aggiungi Attivit‡") {
	panel = new wxPanel(this);

	campo1 = new wxStaticText(panel, wxID_ANY, "Data:", wxPoint(10, 10), wxSize(100, 100));
	Data = new wxDatePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxPoint(50, 10), wxDefaultSize, 4L);

	campo2 = new wxStaticText(panel, wxID_ANY, "OraInizio:", wxPoint(200, 10), wxSize(100, 100));
	oraInizio = new wxTimePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxPoint(250, 10), wxDefaultSize, 0L);

	campo3 = new wxStaticText(panel, wxID_ANY, "OraFine:", wxPoint(350, 10), wxSize(100, 100));
	oraFine = new wxTimePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxPoint(400, 10), wxDefaultSize, 0L);

	campo4 = new wxStaticText(panel, wxID_ANY, "Descrizione:", wxPoint(10, 50), wxSize(100, 100));
	SezioneDescrizione = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 75), wxSize(580, 150));

	aggiungiAttivit‡ = new wxButton(panel, wxID_ANY, "Aggiungi Attivit‡", wxPoint(225, 300), wxSize(150, -1));
	aggiungiAttivit‡->Bind(wxEVT_BUTTON, &AggiungiAttivit‡Frame::AggiungiAttivit‡, this);

	this->registro = registro;

}

void AggiungiAttivit‡Frame::AggiungiAttivit‡(wxCommandEvent& evt){
	
	//estrazione data
	wxDateTime d = Data->GetValue();
	wxString data = d.Format("%d-%m-%Y");

	//estrazione ora inizio
	wxDateTime oi = oraInizio->GetValue();
	wxString orainizio = d.Format("%H:%M");

	//estrazione ora fine
	wxDateTime of = oraFine->GetValue();
	wxString orafine = d.Format("%H:%M");

	//estrazione Descrizione
	wxString desc = SezioneDescrizione->GetValue();

	//crea Attivit‡ con i dati estratti, necessario modificare costruttore.
	Attivit‡* attivit‡ = new Attivit‡(desc, data, orainizio, orafine);
	registro->AggiungiAttivit‡(attivit‡);

}

