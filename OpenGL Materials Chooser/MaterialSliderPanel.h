#pragma once

#include "wx/wx.h"
#include "IDs.h"

class MaterialSliderPanel : public wxPanel
{
public:
	MaterialSliderPanel(wxPanel *parent, std::string name, int rID, int gID, int bID, int aID);
	~MaterialSliderPanel();
	int getRedValue();
	int getGreenValue();
	int getBlueValue();
	int getAlphaValue();

private:
	wxBoxSizer *box = nullptr;
	wxSlider *redSlider = nullptr;
	wxSlider *blueSlider = nullptr;
	wxSlider *greenSlider = nullptr;
	wxSlider *alphaSlider = nullptr;
	wxStaticText *title = nullptr;
	wxStaticText *redText = nullptr;
	wxStaticText *blueText = nullptr;
	wxStaticText *greenText = nullptr;
	wxStaticText *alphaText = nullptr;
};

