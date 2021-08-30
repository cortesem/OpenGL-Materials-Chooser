#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_COMMAND_SCROLL(wxID_ANY, MainFrame::OnSliderMoved)
wxEND_EVENT_TABLE()

MainFrame::MainFrame()
	: wxFrame(nullptr, wxID_ANY, "OpenGL Materials Chooser", 
		wxPoint(50, 50), wxSize(1200, 900))
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_EXIT);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);

	CreateStatusBar();
	SetStatusText("");

	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);

	wxBoxSizer *mainBox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *rightBox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *leftBox = new wxBoxSizer(wxVERTICAL);

	rightPanel = new wxPanel(this, wxID_ANY);
	ambPanel = new MaterialSliderPanel(rightPanel, "Ambient", AMB_SL_RED,
		AMB_SL_GREEN, AMB_SL_BLUE, AMB_SL_ALPHA);
	specPanel = new MaterialSliderPanel(rightPanel, "Specular", SPEC_SL_RED,
		SPEC_SL_GREEN, SPEC_SL_BLUE, SPEC_SL_ALPHA);
	diffPanel = new MaterialSliderPanel(rightPanel, "Diffuse", DIFF_SL_RED,
		DIFF_SL_GREEN, DIFF_SL_BLUE, DIFF_SL_ALPHA);
	shinPanel = new ShininessPanel(rightPanel, "Shininess", SHIN_SL);

	rightBox->Add(ambPanel, 0, wxEXPAND | wxCENTER | wxALL);
	rightBox->Add(diffPanel, 0, wxEXPAND | wxCENTER | wxALL);
	rightBox->Add(specPanel, 0, wxEXPAND | wxCENTER | wxALL);
	rightBox->Add(shinPanel, 0, wxEXPAND | wxCENTER | wxALL);
	rightPanel->SetSizer(rightBox);

	leftPanel = new wxPanel(this, wxID_ANY);
	display = new GLPanel(leftPanel);
	matSettings = new MaterialsSettingsPanel(leftPanel, getAmbString(),
		getDiffString(), getSpecString(), getShinString());

	leftBox->Add(display, 0, wxEXPAND | wxCENTER | wxALL);
	leftBox->Add(matSettings, 0, wxEXPAND | wxCENTER | wxALL);
	leftPanel->SetSizer(leftBox);

	mainBox->Add(leftPanel, 0, wxEXPAND | wxCENTER | wxALL);
	mainBox->Add(rightPanel, 0, wxEXPAND | wxCENTER | wxALL);

	this->SetSizer(mainBox);

	this->Centre();

}

MainFrame::~MainFrame()
{

}

void MainFrame::OnExit(wxCommandEvent &event)
{
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox("This is a wxWidgets Template Program",
		"About Template Program", wxOK | wxICON_INFORMATION);
}

// This ones ugly I know, just wanted to get something together quick.
void MainFrame::OnSliderMoved(wxScrollEvent &event)
{
	int id = event.GetId();
	int value;

	switch (id) {
	case AMB_SL_RED:
		value = ambPanel->getRedValue();
		matSettings->setAmbString(getAmbString());
		break;
	case AMB_SL_GREEN:
		value = ambPanel->getGreenValue();
		matSettings->setAmbString(getAmbString());
		break;
	case AMB_SL_BLUE:
		value = ambPanel->getBlueValue();
		matSettings->setAmbString(getAmbString());
		break;
	case AMB_SL_ALPHA:
		value = ambPanel->getAlphaValue();
		matSettings->setAmbString(getAmbString());
		break;
	case SPEC_SL_RED:
		value = specPanel->getRedValue();
		matSettings->setSpecString(getSpecString());
		break;
	case SPEC_SL_GREEN:
		value = specPanel->getGreenValue();
		matSettings->setSpecString(getSpecString());
		break;
	case SPEC_SL_BLUE:
		value = specPanel->getBlueValue();
		matSettings->setSpecString(getSpecString());
		break;
	case SPEC_SL_ALPHA:
		value = specPanel->getAlphaValue();
		matSettings->setSpecString(getSpecString());
		break;
	case DIFF_SL_RED:
		value = diffPanel->getRedValue();
		matSettings->setDiffString(getDiffString());
		break;
	case DIFF_SL_GREEN:
		value = diffPanel->getGreenValue();
		matSettings->setDiffString(getDiffString());
		break;
	case DIFF_SL_BLUE:
		value = diffPanel->getBlueValue();
		matSettings->setDiffString(getDiffString());
		break;
	case DIFF_SL_ALPHA:
		value = diffPanel->getAlphaValue();
		matSettings->setDiffString(getDiffString());
		break;
	case SHIN_SL :
		value = shinPanel->getValue() * 100;
		matSettings->setShinString(getShinString());
		break;
	}

	display->OnSliderMoved(id, (float)(value) / 10000);
}

std::string MainFrame::getAmbString()
{
	return display->getAmbString();
}

std::string MainFrame::getDiffString()
{
	return display->getDiffString();
}

std::string MainFrame::getSpecString()
{
	return display->getSpecString();
}

std::string MainFrame::getShinString()
{
	return display->getShinString();
}