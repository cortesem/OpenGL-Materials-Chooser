#include "MaterialsSettingsPanel.h"

MaterialsSettingsPanel::MaterialsSettingsPanel(wxPanel *parent, std::string ambValues,
	std::string diffValues, std::string specValues, std::string shinValues)
	: wxPanel(parent, wxID_ANY, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	box = new wxBoxSizer(wxVERTICAL);
	box->AddSpacer(5);
	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	ambText =  "GLfloat mat_ambient[] = ";
	diffText = "GLfloat mat_diffuse[] = ";
	specText = "GLfloat mat_specular[] = ";
	shinText = "GLfloat mat_shininess[] = ";

	ambient = new wxStaticText(this, wxID_ANY, ambText + ambValues, wxPoint(-1, -1),
		wxSize(-1, -1), wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE, "");
	ambient->SetFont(font);
	diffuse = new wxStaticText(this, wxID_ANY, diffText + diffValues, wxPoint(-1, -1),
		wxSize(-1, -1), wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE, "");
	diffuse->SetFont(font);
	specular = new wxStaticText(this, wxID_ANY, specText + specValues, wxPoint(-1, -1),
		wxSize(-1, -1), wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE, "");
	specular->SetFont(font);
	shininess = new wxStaticText(this, wxID_ANY, shinText + shinValues, wxPoint(-1, -1),
		wxSize(-1, -1), wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE, "");
	shininess->SetFont(font);

	box->Add(ambient, 0, wxEXPAND | wxCENTER | wxALL, 12);
	box->Add(diffuse, 0, wxEXPAND | wxCENTER | wxALL, 12);
	box->Add(specular, 0, wxEXPAND | wxCENTER | wxALL, 12);
	box->Add(shininess, 0, wxEXPAND | wxCENTER | wxALL, 12);

	this->SetSizer(box);
}

MaterialsSettingsPanel::~MaterialsSettingsPanel()
{

}

void MaterialsSettingsPanel::setAmbString(std::string values)
{
	ambient->SetLabelText(ambText + values);
}

void MaterialsSettingsPanel::setDiffString(std::string values)
{
	diffuse->SetLabelText(diffText + values);
}

void MaterialsSettingsPanel::setSpecString(std::string values)
{
	specular->SetLabelText(specText + values);
}

void MaterialsSettingsPanel::setShinString(std::string values)
{
	shininess->SetLabelText(shinText + values);
}