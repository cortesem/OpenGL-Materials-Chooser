#include "ShininessPanel.h"

ShininessPanel::ShininessPanel(wxPanel *parent, std::string name, int slID)
	: wxPanel(parent, wxID_ANY, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	box = new wxBoxSizer(wxVERTICAL);

	shininess = new wxSlider(this, slID, 5000, 0, 12800, wxPoint(-1, -1), wxSize(350, -1),
		wxSL_HORIZONTAL | wxSL_BOTTOM | wxSL_LABELS, wxDefaultValidator, "meow");
	
	wxFont headerFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true);

	title = new wxStaticText(this, wxID_ANY, name, wxPoint(-1, -1), wxSize(-1, -1),
		wxALIGN_CENTRE_HORIZONTAL, "");
	title->SetFont(headerFont);

	box->Add(title, 1, wxCENTER | wxALL, 5);
	box->Add(shininess, 1, wxCENTER | wxALL, 5);

	this->SetSizer(box);
}

ShininessPanel::~ShininessPanel()
{

}

int ShininessPanel::getValue()
{
	return shininess->GetValue();
}