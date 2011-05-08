#include "VueOpenGL.h"

VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille, wxPoint const& position)
:wxGLCanvas(parent, wxID_ANY, position, taille, wxSUNKEN_BORDER)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::dessine));
}
void VueOpenGL::InitOpenGL()
{
	//indique que les instructions OpenGL s'adressent au contexte
	// OpenGL courant
	SetCurrent();
	
	// Active la gestion de la profondeur
	glEnable(GL_DEPTH_TEST);
	
	// Fixe la perspective
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, 4./3., 1.0, 1000.0);
	
	// fixe le fond d'écran à noir
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	// prépare à travailler sur le modèle  
	// (données de l'application)
	glMatrixMode(GL_MODELVIEW);
}

void VueOpenGL::dessine(wxPaintEvent& event)
{
    // indique que le code est relatif au contexte OPenGL courant
    SetCurrent();
     //initialise les données liées à la gestion de la profondeur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
    // initialise GL_MODELVIEW
    // place le repère en (0,0,0)
    glLoadIdentity();
 
    // place la caméra (fixe le point de vue)
    gluLookAt(2.0, 2.0, 2.0, // position (x, y, z) de la caméra
              0.0, 0.0, 0.0, // point visé
              0.0, 0.0, 1.0);  /* vecteur representant la direction verticale
                               de la vue (non parallèle à la direction de
                               visée)                                      */
                     
     
    //Commandes de dessin ici
    /*glPushMatrix();
	glTranslated(1,1,1);
	glRotated(-20,0,1,0);
	glScaled(0.5,0.5,0.5);
	
	
	
	glBegin(GL_QUADS);
	
	glColor3ub(255,0,0);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(1,1,-1);
	
	glColor3ub(0,255,0);
	glVertex3d(1,-1,1);
	glVertex3d(1,1,1);
	glVertex3d(1,1,-1);
	glVertex3d(1,-1,-1);
	
	glColor3ub(0,255,255);
	glVertex3d(1,-1,1);
	glVertex3d(-1,-1,1);
	glVertex3d(-1,-1,-1);
	glVertex3d(1,-1,-1);
	
	glColor3ub(255,255,0);
	glVertex3d(-1,-1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	
	glColor3ub(0,0,255);
	glVertex3d(1,-1,1);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,-1,1);
	
	glColor3ub(255,0,255);
	glVertex3d(1,-1,-1);
	glVertex3d(1,1,-1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	
	glEnd();
	
	
	glPopMatrix();*/
	
	glPushMatrix();
	
	glTranslated(3,2,0);
	glRotated(90,1,0,0);
     
 
    // Finalement, envoi du dessin à l écran
    glFlush();
    SwapBuffers();
}

