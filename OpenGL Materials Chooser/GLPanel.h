#pragma once

#include "wx/wx.h"
#include <gl/glew.h>
#include <gl/GLU.h>
#include <wx/glcanvas.h>
#include <iomanip>
#include <sstream>
#include "IDs.h"

class GLPanel : public wxGLCanvas
{
public:
	GLPanel(wxPanel *parent);
	~GLPanel();
	void OnSliderMoved(int id, float value);
	std::string getAmbString();
	std::string getDiffString();
	std::string getSpecString();
	std::string getShinString();

private:
	void InitGLEW();
	void InitGL();
	void draw(wxPaintEvent &event);
	void OnInternalIdle();
	void OnEraseBackground(wxEraseEvent& e);

	wxGLContext *glContext = nullptr;
	GLUquadricObj *sphere1 = nullptr;
	GLUquadricObj *sphere2 = nullptr;

	GLfloat mat_ambient[4];
	GLfloat mat_diffuse[4];
	GLfloat mat_specular[4];
	GLfloat mat_shininess[1];

	
	int rotateVal;
};

