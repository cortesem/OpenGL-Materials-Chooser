#include "GLPanel.h"


GLPanel::GLPanel(wxPanel *parent)
	: wxGLCanvas(parent, wxID_ANY, NULL, wxPoint(-1, -1), wxSize(820, 615), wxBORDER_SUNKEN)
{
	glContext = new wxGLContext(this);
	Bind(wxEVT_PAINT, &GLPanel::draw, this);

	SetCurrent(*glContext);
	InitGLEW();
	InitGL();
}

GLPanel::~GLPanel()
{
	SetCurrent(*glContext);
	gluDeleteQuadric(sphere1);
	gluDeleteQuadric(sphere2);
	delete[] glContext;
}

void GLPanel::InitGLEW()
{
	// Initialize GLEW
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
}

void GLPanel::InitGL()
{

	sphere1 = gluNewQuadric();
	gluQuadricNormals(sphere1, GLU_FILL);
	sphere2 = gluNewQuadric();
	gluQuadricNormals(sphere2, GLU_FILL);

	rotateVal = 0;

	GLfloat light_position0[] = { -4.0f, 8.0f, 8.0f, 1.0f };
	GLfloat light_position1[] = { 4.0f, 8.0f, 8.0f, 1.0f };
	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	for (int i = 0; i < 4; ++i) {
		mat_ambient[i] = 0.0f;
		mat_diffuse[i] = 0.0f;
		mat_specular[i] = 0.0f;
	}
	mat_ambient[0] = 0.2f;
	mat_diffuse[0] = 0.2f;
	mat_specular[0] = 0.2f;
	mat_ambient[3] = 1.0f;
	mat_diffuse[3] = 1.0f;
	mat_specular[3] = 1.0f;
	mat_shininess[0] = 50.0f;

	// Set up and enable lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);   // This second light is currently off

	// Other OpenGL setup
	glEnable(GL_DEPTH_TEST);   // Remove hidded surfaces
	glShadeModel(GL_SMOOTH);   // Use smooth shading, makes boundaries between polygons harder to see 
	glClearColor(0.4F, 0.4F, 0.6F, 0.0F);  // Color and depth for glClear
	glClearDepth(1.0f);
	glEnable(GL_NORMALIZE);    // Renormalize normal vectors 
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);   // Nicer perspective

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 800 / 600, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void GLPanel::draw(wxPaintEvent &event)
{
	SetCurrent(*glContext);

	// set background to black
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glPushMatrix();
	glTranslatef(3.0f, 3.0f, 5.0f);
	glRotatef(rotateVal, 0.0f, 1.0f, 0.0f);
	gluSphere(sphere1, 2.0f, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.0f, -3.0f, 5.0f);
	gluSphere(sphere2, 2.0f, 10, 10);
	glPopMatrix();
	glPopMatrix();

	rotateVal = (rotateVal + 1) % 360;

	glFlush();
	SwapBuffers();

}

void GLPanel::OnInternalIdle()
{
	Refresh();
}

void GLPanel::OnEraseBackground(wxEraseEvent& e)
{
	// avoid flash, do nothing
}

void GLPanel::OnSliderMoved(int id, float value)
{

	switch (id) {
	case AMB_SL_RED:
		mat_ambient[0] = value;
		break;
	case AMB_SL_GREEN:
		mat_ambient[1] = value;
		break;
	case AMB_SL_BLUE:
		mat_ambient[2] = value;
		break;
	case AMB_SL_ALPHA:
		mat_ambient[3] = value;
		break;
	case SPEC_SL_RED:
		mat_specular[0] = value;
		break;
	case SPEC_SL_GREEN:
		mat_specular[1] = value;
		break;
	case SPEC_SL_BLUE:
		mat_specular[2] = value;
		break;
	case SPEC_SL_ALPHA:
		mat_specular[3] = value;
		break;
	case DIFF_SL_RED:
		mat_diffuse[0] = value;
		break;
	case DIFF_SL_GREEN:
		mat_diffuse[1] = value;
		break;
	case DIFF_SL_BLUE:
		mat_diffuse[2] = value;
		break;
	case DIFF_SL_ALPHA:
		mat_diffuse[3] = value;
		break;
	case SHIN_SL:
		mat_shininess[0] = value;
		break;
	}		
}

std::string GLPanel::getAmbString()
{
	std::stringstream result;
	result << "{ " << std::fixed << std::setprecision(4) << mat_ambient[0];
	for (int i = 1; i < sizeof(mat_ambient) / sizeof(mat_ambient[0]); ++i) {
		result << "f, " << mat_ambient[i];
	}
	result << "f }";

	return result.str();
}

std::string GLPanel::getDiffString()
{
	std::stringstream result;
	result << "{ " << std::fixed << std::setprecision(4) << mat_diffuse[0];
	for (int i = 1; i < sizeof(mat_diffuse) / sizeof(mat_diffuse[0]); ++i) {
		result << "f, " << mat_diffuse[i];
	}
	result << "f }";

	return result.str();
}

std::string GLPanel::getSpecString()
{
	std::stringstream result;
	result << "{ " << std::fixed << std::setprecision(4) << mat_specular[0];
	for (int i = 1; i < sizeof(mat_specular) / sizeof(mat_specular[0]); ++i) {
		result << "f, " << mat_specular[i];
	}
	result << "f }";

	return result.str();
}

std::string GLPanel::getShinString()
{
	std::stringstream result;
	result << "{ " << std::fixed << std::setprecision(2) << mat_shininess[0];
	for (int i = 1; i < sizeof(mat_shininess) / sizeof(mat_shininess[0]); ++i) {
		result << "f, " << mat_shininess[i];
	}
	result << "f }";

	return result.str();
}