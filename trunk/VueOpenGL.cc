#include "VueOpenGL.h"
#inlcude "Application.h"



VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille, wxPoint const& position)
: wxGLCanvas(parent, wxID_ANY, position, taille, wxSUKEN_BORDER)
{
	Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::dessine));
	
	SetFocus();
}

VueOpenGL::~VueOpenGL()
{}



void VueOpenGL::InitOpenGL()
{
	//s'adresse au contexte actuelle OpenGL
	SetCurrent();
	
	//gestion de la profondeur
	glEnable(GL_DEPTH_TEST);
	
	//fixe la perpespective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(65.0, 4./3., 1.0, 1000.0)
	
	//fixe le fond d'écran a noir
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glMatrixMode(GL_MODELVIEW);
}

void VueOpenGL::dessine(wxPaintEvent& event)
{
	SetCurrent();
	
	glClear(
}


