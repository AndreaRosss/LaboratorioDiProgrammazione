#pragma once
#include <wx/wx.h>
#include "Registro.h"
#include"AggiungiAttivitàFrame.h"
#include "SfogliaRegistroFrame.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	~MainFrame() {};

	Registro* registro;

private:
	void ApriFrameAggiungiAttività(wxCommandEvent& evt);

	void ApriFrameSfogliaRegistro(wxCommandEvent& evt);

};

