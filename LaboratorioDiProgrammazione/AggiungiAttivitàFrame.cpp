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

	this->registro = registro;

}

void AggiungiAttivit‡Frame::AggiungiAttivit‡(){
	
	//estrazione data
	wxDateTime d = Data->GetValue();
	string a = to_string(d.GetDay());
	string b = to_string(d.GetMonth());
	string c = to_string(d.GetYear());
	a.append(b).append(c);

	//estrazione ora inizio
	wxDateTime orainizio = oraInizio->GetValue();
	string ora1 = to_string(orainizio.GetHour());
	string minuto1 = to_string(orainizio.GetMinute());
	string orai = ora1.append(minuto1);

	//estrazione ora fine
	wxDateTime orafine = oraFine->GetValue();
	string ora2 = to_string(orafine.GetHour());
	string minuto2 = to_string(orafine.GetMinute());
	string oraf = ora2.append(minuto2);

	//estrazione Descrizione
	string desc = SezioneDescrizione->GetValue().ToStdString();

	//crea Attivit‡ con i dati estratti, necessario modificare costruttore.
	Attivit‡* attivit‡ = new Attivit‡(desc, stoi(a), orai, oraf);
	registro->AggiungiAttivit‡(attivit‡);

}

