#include "App.h"

wxIMPLEMENT_APP(App);

App::App()
{

}

App::~App()
{

}

bool App::OnInit()
{
	frame = new MainFrame();
	frame->Show(true);
	return true;
}