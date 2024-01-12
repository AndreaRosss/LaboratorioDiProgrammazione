#pragma once
#include <wx/wx.h>
#include "Registro.h"
#include"AggiungiAttivit‡Frame.h"
#include "SfogliaRegistroFrame.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	~MainFrame() {};

	Registro* registro;

private:
	void ApriFrameAggiungiAttivit‡(wxCommandEvent& evt);

	void ApriFrameSfogliaRegistro(wxCommandEvent& evt);

};

