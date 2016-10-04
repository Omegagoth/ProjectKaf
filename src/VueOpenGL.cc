#include "VueOpenGL.h"
#include "Application.h"

Camera* VueOpenGL::getcamera() const
{
	return camera;
}


void VueOpenGL::setcamera(Camera const& c)
{
	camera = c.copie();
}

VueOpenGL::VueOpenGL(wxWindow* parent, wxSize const& taille, wxPoint const& position)
:wxGLCanvas(parent, wxID_ANY, position, taille, wxSUNKEN_BORDER), camera(new Camera()), x_souris(0), y_souris(0)
{	
    Connect(wxEVT_PAINT, wxPaintEventHandler(VueOpenGL::dessine));
    Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(VueOpenGL::appuiTouche));
    Connect(wxEVT_MOTION, wxMouseEventHandler(VueOpenGL::bougeSouris));
    Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(VueOpenGL::clicSouris));
    Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(VueOpenGL::moletteSouris));
    
    SetCursor(wxCURSOR_SIZENESW);
    
    SetFocus();
}

VueOpenGL::~VueOpenGL()
{}

void VueOpenGL::InitOpenGL()
{
	//indique que les instructions OpenGL s'adressent au contexte OpenGL courant
	SetCurrent();
	
	glClearDepth(1.0); //Initialise le tampon de profondeur
	// Active la gestion de la profondeur
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); //Choisi le type de test de la profondeur
	
	//On initialise la perspective
	redimensionne(640, 480);
	
	// fixe le fond d'écran à noir
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	// prépare à travailler sur le modèle  
	// (données de l'application)
	glMatrixMode(GL_MODELVIEW);
	
	//On initialise le brouillard
	glEnable(GL_FOG);
	GLfloat couleur[4] = {0.05, 0.05, 0.05, 1.0};
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf (GL_FOG_DENSITY, 0.004);
	glFogfv(GL_FOG_COLOR, couleur);
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

void VueOpenGL::redimensionne(int largeur, int hauteur)
{
	//On ajuste la taille de la fenêtre OpenGL à celle de la fenêtre
	glViewport(0, 0, largeur, hauteur);
	SetSize(largeur, hauteur);
	
	//On réinitialise la matrice de projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//On fixe la perspective pour garder les proportions
	gluPerspective(65.0, (double)largeur/hauteur, 0.1, 1000.0);
	
	//On prépare le travaille sur le modèle
	glMatrixMode(GL_MODELVIEW);
}

void VueOpenGL::dessine(wxPaintEvent& event)
{
    // indique que le code est relatif au contexte OPenGL courant
    SetCurrent();
    //initialise les données liées à la couleur et à la gestion de la profondeur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(wxGetApp().getbrouillard()) //On active ou non le brouillard
    {
		glEnable(GL_FOG);
	}
	else
	{
		glDisable(GL_FOG);
	}
     
    // initialise GL_MODELVIEW
    // place le repère en (0,0,0)
    glLoadIdentity();
    
    // place la caméra (fixe le point de vue)
    camera->setVue();
    
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
            camera->setPosition(camera->getPosition() - (Vecteur3D(0,0,1)^camera->getdirection())*0.1);
            break;
        // incrémente l'angle phi de la caméra lorsque l'on appuie sur la flèche droite      
        case WXK_RIGHT:
             camera->setPosition(camera->getPosition() + (Vecteur3D(0,0,1)^camera->getdirection())*0.1);
             break;
        // décrémente l'angle theta de la caméra lorsque l'on appuie sur la flèche haut       
        case WXK_UP:
            camera->setPosition(camera->getPosition() - camera->getdirection()*0.1);
            break;
        // incrémente l'angle theta de éa caméra lorsque l'on appuie sur la flèche bas     
        case WXK_DOWN:
            camera->setPosition(camera->getPosition() + camera->getdirection()*0.1);
            break;
        // diminue le rayon de la  caméra si on appuie sur 'W'
        case 'W':
            camera->setRayon(camera->getRayon() - 1);
            break;
        // augmente le rayon de la caméra si on appuie sur 'S'
        case 'S':
            camera->setRayon(camera->getRayon() + 1);
            break;
        case WXK_SPACE:
			camera->resetVue();
			break;
		case WXK_PAGEUP :
			camera->setPosition(camera->getPosition() - ((Vecteur3D(0,0,1)^camera->getdirection())^camera->getdirection())*0.1);
			break;
		case WXK_PAGEDOWN :
			camera->setPosition(camera->getPosition() + ((Vecteur3D(0,0,1)^camera->getdirection())^camera->getdirection())*0.1);
			break;
    }
    
    Refresh(false);
}

void VueOpenGL::bougeSouris(wxMouseEvent& event)
{
	if(event.RightIsDown())
	{
		int x(0), y(0);
		event.GetPosition(&x,&y);
		
		camera->setPhi(camera->getPhi() - (x_souris-x)/50.);
		camera->setTheta(camera->getTheta() + (y_souris-y)/50.);
		
		event.GetPosition(&x_souris, &y_souris);
		
		Refresh(false);
	}
}

void VueOpenGL::clicSouris(wxMouseEvent& event)
{
	event.GetPosition(&x_souris, &y_souris);
}

void VueOpenGL::moletteSouris(wxMouseEvent& event)
{
	camera->setRayon(camera->getRayon() - event.GetWheelRotation()/60.);
	Refresh(false);
}


