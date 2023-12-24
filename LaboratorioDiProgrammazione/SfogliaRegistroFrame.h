#pragma once
#include <wx/wx.h>
#include "Registro.h"
class SfogliaRegistroFrame : public wxFrame
{
public:
	SfogliaRegistroFrame(vector<int> v, Registro* registro);

private:
	wxPanel* panel;
	Registro* registro;
	wxArrayString as;
	wxChoice* choiche;

};

