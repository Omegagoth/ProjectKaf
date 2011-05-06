#include "VueOpenGL.h"
#include "Application.h"

VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille, wxPoint const& position)
:wxGLCanvas(parent, wxID_ANY, position, taille, wxSUNKEN_BORDER), camera(88, 0.61, 0.44)
{
    Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::dessine));
    Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(VueOpenGL::appuiTouche));
    Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(VueOpenGL::bougeSouris));
}

VueOpenGL::~VueOpenGL()
{}

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

void VueOpenGL::dessineSol(double taille)
{
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture("texture/sol.jpg"));
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex3d(taille, taille, 0);
	
	glTexCoord2d(0,-4);
	glVertex3d(taille, -taille, 0);
	
	glTexCoord2d(-4,-4);
	glVertex3d(-taille, -taille, 0);
	
	glTexCoord2d(-4,0);
	glVertex3d(-taille, taille, 0);
	
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
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
    camera.setVue();
    
    //Commandes de dessin ici
    /*glPushMatrix();
	glTranslated(1,1,1);
	glRotated(-20,0,1,0);
	glScaled(0.5,0.5,0.5);
	
	
	glEnable(GL_LINE_SMOOTH);
	
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
	
	dessineSol(100);
	dessineRepere();
	wxGetApp().dessine();
     
 
    // Finalement, envoi du dessin à l écran
    glFlush();
    SwapBuffers();
}

void VueOpenGL::appuiTouche(wxKeyEvent& event)
{
    switch(event.GetKeyCode())
    {
         // décrémente l'angle phi de la caméra lorsque l'on appuie sur la flèche gauche
        case WXK_LEFT:
            camera.setPhi(camera.getPhi() - 0.1);
            break;
        // incrémente l'angle phi de la caméra lorsque l'on appuie sur la flèche droite      
        case WXK_RIGHT:
             camera.setPhi(camera.getPhi() + 0.1);
             break;
        // décrémente l'angle theta de la caméra lorsque l'on appuie sur la flèche haut       
        case WXK_UP:
            camera.setTheta(camera.getTheta() - 0.1);
            break;
        // incrémente l'angle theta de éa caméra lorsque l'on appuie sur la flèche bas     
        case WXK_DOWN:
            camera.setTheta(camera.getTheta() + 0.1);
            break;
        // diminue le rayon de la  caméra si on appuie sur 'W'
        case 'W': //Attention
            camera.setRayon(camera.getRayon() - 1);
            break;
        // augmente le rayon de la caméra si on appuie sur 'S'
        case 'S':
            camera.setRayon(camera.getRayon() + 1);
            break;
    }
    
    Refresh(false);
}

