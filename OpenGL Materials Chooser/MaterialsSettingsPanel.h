#pragma once

#include "wx/wx.h"
#include "IDs.h"

class MaterialsSettingsPanel : public wxPanel
{
public:
	MaterialsSettingsPanel(wxPanel *parent, std::string ambValues,
		std::string diffValues, std::string specValues, std::string shinValues);
	~MaterialsSettingsPanel();
	void setAmbString(std::string values);
	void setDiffString(std::string values);
	void setSpecString(std::string values);
	void setShinString(std::string values);

private:
	wxBoxSizer *box = nullptr;
	wxStaticText *ambient = nullptr;
	wxStaticText *diffuse = nullptr;
	wxStaticText *specular = nullptr;
	wxStaticText *shininess = nullptr;
	std::string ambText = "";
	std::string diffText = "";
	std::string specText = "";
	std::string shinText = "";
};

