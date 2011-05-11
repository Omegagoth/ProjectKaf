#include "VueOpenGL.h"



VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition)
: wxGLCanvas(parent, wxID_ANY, position, taille, wxSUNKEN_BORDER)
{
	Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::dessine));
	
	SetFocus();
}

VueOpenGL::~VueOpenGL()
{}

void VueOpenGL::InitOpenGL()
{
	//On s'adresse au constexte OpenGL courant
	SetCurrent();
	
	//gestion de la profondeur
	glEnable(GL_DEPTH_TEST);
	
	//fixe la perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(65., 4./3, 1., 1000.)
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glMatrixMode(GL_MODELVIEW);
}




void VueOpenGL::dessine()
{
	//relatif au contexte OpenGL courant
	SetCurrent();
	
	//Initialise la gestion de la profondeur
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//place le repère en (0,0,0)
	glLoadIdentity();
	
	//place la camera
	gluLookAt(2.0, 2.0, 2.0 //position (x,y,z) de la camera
			  0.0, 0.0, 0.0 //point visé
			  0.0, 0.0, 1.0); //vecteur directeur de la verticale
	
	wxGetApp().dessine();
	
	//affiche le dessin a l'écran
	glFlush();
	SwapBuffers();
}

