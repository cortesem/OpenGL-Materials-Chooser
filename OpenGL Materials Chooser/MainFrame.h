#pragma once

#include "wx/wx.h"
#include "MaterialSliderPanel.h"
#include "ShininessPanel.h"
#include "GLPanel.h"
#include "MaterialsSettingsPanel.h"
#include "IDs.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();
	void OnSliderMoved(wxScrollEvent &event);
	std::string getAmbString();
	std::string getDiffString();
	std::string getSpecString();
	std::string getShinString();

private:
	void OnExit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnSliderMoved();

	wxPanel *rightPanel = nullptr;
	wxPanel *leftPanel = nullptr;
	MaterialSliderPanel *ambPanel = nullptr;
	MaterialSliderPanel *specPanel = nullptr;
	MaterialSliderPanel *diffPanel = nullptr;
	ShininessPanel *shinPanel = nullptr;
	GLPanel *display = nullptr;
	MaterialsSettingsPanel *matSettings = nullptr;

	wxDECLARE_EVENT_TABLE();
};

