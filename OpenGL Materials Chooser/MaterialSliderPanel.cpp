#include "MaterialSliderPanel.h"

MaterialSliderPanel::MaterialSliderPanel(wxPanel *parent, std::string name, int rID, int gID, int bID, int aID)
	: wxPanel(parent, wxID_ANY, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN)
{
	box = new wxBoxSizer(wxVERTICAL);

	redSlider = new wxSlider(this, rID, 2000, 0, 10000, wxPoint(-1, -1), wxSize(350, -1),
		wxSL_HORIZONTAL | wxSL_BOTTOM | wxSL_LABELS, wxDefaultValidator, "");
	greenSlider = new wxSlider(this, gID, 0, 0, 10000, wxPoint(-1, -1), wxSize(350, -1),
		wxSL_HORIZONTAL | wxSL_BOTTOM | wxSL_LABELS, wxDefaultValidator, "");
	blueSlider = new wxSlider(this, bID, 0, 0, 10000, wxPoint(-1, -1), wxSize(350, -1),
		wxSL_HORIZONTAL | wxSL_BOTTOM | wxSL_LABELS, wxDefaultValidator, "");
	alphaSlider = new wxSlider(this, aID, 10000, 0, 10000, wxPoint(-1, -1), wxSize(350, -1),
		wxSL_HORIZONTAL | wxSL_BOTTOM | wxSL_LABELS, wxDefaultValidator, "");
	
	wxFont headerFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true);
	wxFont matFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	title = new wxStaticText(this, wxID_ANY, name, wxPoint(-1, -1), wxSize(-1, -1),
		wxALIGN_CENTRE_HORIZONTAL, "");
	title->SetFont(headerFont);
	redText = new wxStaticText(this, wxID_ANY, "Red", wxPoint(-1, -1), wxSize(-1, -1),
		wxALIGN_CENTRE_HORIZONTAL, "");
	redText->SetFont(matFont);
	greenText = new wxStaticText(this, wxID_ANY, "Green", wxPoint(-1, -1), wxSize(-1, -1),
		wxALIGN_CENTRE_HORIZONTAL, "");
	greenText->SetFont(matFont);
	blueText = new wxStaticText(this, wxID_ANY, "Blue", wxPoint(-1, -1), wxSize(-1, -1),
		wxALIGN_CENTRE_HORIZONTAL, "");
	blueText->SetFont(matFont);
	alphaText = new wxStaticText(this, wxID_ANY, "Alpha", wxPoint(-1, -1), wxSize(-1, -1),
		wxALIGN_CENTRE_HORIZONTAL, "");
	alphaText->SetFont(matFont);

	box->Add(title, 0, wxCENTER | wxALL);
	box->Add(redText, 0, wxCENTER | wxALL);
	box->Add(redSlider, 0, wxCENTER | wxALL);
	box->Add(greenText, 0, wxCENTER | wxALL);
	box->Add(greenSlider, 0, wxCENTER | wxALL);
	box->Add(blueText, 0, wxCENTER | wxALL);
	box->Add(blueSlider, 0, wxCENTER | wxALL);
	box->Add(alphaText, 0, wxCENTER | wxALL);
	box->Add(alphaSlider, 0, wxCENTER | wxALL);

	this->SetSizer(box);
}
MaterialSliderPanel::~MaterialSliderPanel()
{

}

int MaterialSliderPanel::getRedValue()
{
	return redSlider->GetValue();
}

int MaterialSliderPanel::getGreenValue()
{
	return greenSlider->GetValue();
}

int MaterialSliderPanel::getBlueValue()
{
	return blueSlider->GetValue();
}

int MaterialSliderPanel::getAlphaValue()
{
	return alphaSlider->GetValue();
}