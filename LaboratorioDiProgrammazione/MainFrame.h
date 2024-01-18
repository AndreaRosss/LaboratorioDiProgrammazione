#pragma once
#include "Registro.h"
#include <wx/wx.h>
using namespace std;


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	~MainFrame() {};

private:
	Registro registro;

public:
	void ApriFrameAggiungiAttivita(wxCommandEvent& evt);

	void ApriFrameSfogliaRegistro(wxCommandEvent& evt);

};


