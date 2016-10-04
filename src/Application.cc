#include "Application.h"


const Accelerateur* Application::getaccelerateur() const
{
	return &acc;
}

unsigned int Application::getvitesse() const
{
	return vitesse;
}

Vue Application::getcamera() const
{
	return fenetreGL->getcamera();
}

bool Application::getmode_fildefer() const
{
	return mode_fildefer;
}

bool Application::getbrouillard() const
{
	return brouillard;
}


void Application::setvitesse(unsigned int i)
{
	vitesse = 50*pow(10, i/100.);
}

void Application::setcamera(Vue v)
{
	fenetreGL->setcamera(v);
}

void Application::setmode_fildefer(bool m)
{
	mode_fildefer = m;
}

void Application::setbrouillard(bool b)
{
	brouillard = b;
}


Application::Application()
: wxApp()
{}


bool Application::OnInit()
{
	//On alloue la fenêtre de contrôle
	fenetreControle = new FenetreControle();
	
    //On alloue la fenêtre OpenGL
    fenetreGL=new FenetreGL(wxT("Accélérateur"),wxSize(640, 480));
    
    //Définie comme fenêtre principale
    SetTopWindow(fenetreGL);
    
    //On connecte l'évenement du timer avec la fonction evolue de l'Application
    Connect(wxID_ANY, wxEVT_TIMER, wxTimerEventHandler(Application::evolue));
    
    //On initialise le timer de la simulation
    simulation_timer = new wxTimer(this);
    simulation_timer->Start(3);
    
    //On initialise l'accélérateur
    acc.ajoute_element(Fodo3D(Vecteur3D(3,2,0),Vecteur3D(3,-2,0),0.1,1.2,1));
    acc.ajoute_element(Dipole3D(Vecteur3D(3,-2,0), Vecteur3D(2,-3,0), 0.1, 1.,5.89158,10));
    acc.ajoute_element(Fodo3D(Vecteur3D(2,-3,0), Vecteur3D(-2,-3,0),0.1,1.2,1));
    acc.ajoute_element(Dipole3D(Vecteur3D(-2,-3,0), Vecteur3D(-3,-2,0),0.1,1.,5.89158,10));
    acc.ajoute_element(Fodo3D(Vecteur3D(-3,-2,0), Vecteur3D(-3,2,0),0.1,1.2,1));
    acc.ajoute_element(Dipole3D(Vecteur3D(-3,2,0), Vecteur3D(-2,3,0),0.1,1.,5.89158,10));
    acc.ajoute_element(Fodo3D(Vecteur3D(-2,3,0), Vecteur3D(2,3,0),0.1,1.2,1));
    acc.ajoute_element(Dipole3D(Vecteur3D(2,3,0), Vecteur3D(3,2,0), 0.1, 1.,5.89158,10));
    
    acc.ajoute_particule(Particule3D(Vecteur3D(3.01, 0, 0), 2, Vecteur3D(0, -2.64754e+08, 0), 0.938272, 1.60217653e-19));
    acc.ajoute_particule(Particule3D(Vecteur3D(2.99, 0, 0), 2, Vecteur3D(0, -2.64754e+08, 0), 0.938272, 1.60217653e-19));
    
    acc.getparticules()[0]->setappartient(*acc.getelements()[0]);
    acc.getparticules()[1]->setappartient(*acc.getelements()[0]);
    
    vitesse = 50*pow(10,30./100);
    setcamera(Libre);
    mode_fildefer = false;
    brouillard = false;
    

    //La fonction doit retourner true si elle s'est bien initialisée
    //Si le pointeur est nul, la fenêtre n'a pas pu s'initialiser!
    return (fenetreGL!=0);
}

GLuint* Application::getTexture(string fichier, bool mipmap)
{
    return texturemanager.getTexture(fichier, mipmap);
}

void Application::dessine()
{
	acc.dessine();
}

void Application::fermer()
{
	fenetreGL->Destroy(); //On détruit les deux fenêtres
	fenetreControle->Destroy();
	
	ExitMainLoop(); //On sort de la boucle infinie d'évenement
}


void Application::rafraichir()
{
	fenetreGL->rafraichir();
}

void Application::evolue(wxTimerEvent& event)
{
	for(unsigned int i(0); i < vitesse; ++i)
	{
		acc.evolue(1e-11);
	}
	rafraichir();
}

//Remplacement du main
IMPLEMENT_APP(Application);
