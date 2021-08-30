#pragma once

#include "wx/wx.h"
#include "IDs.h"

class ShininessPanel : public wxPanel
{
public:
	ShininessPanel(wxPanel *parent, std::string name, int slID);
	~ShininessPanel();
	int getValue();

private:
	wxBoxSizer *box = nullptr;
	wxSlider *shininess = nullptr;
	wxStaticText *title = nullptr;
};

