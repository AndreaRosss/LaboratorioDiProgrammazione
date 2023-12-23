#pragma once
#include <wx/wx.h>
#include "Registro.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	Registro* registro;
private:
	void ApriFrameAggiungiAttività(wxCommandEvent& evt);

};

