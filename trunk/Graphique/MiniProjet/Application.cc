#include "Application.h"
 
bool Application::OnInit()
{
    //On alloue la fenêtre
    fenetreGL=new FenetreGL(wxT("Telescope"),wxSize(640, 480));
     
    //Définie comme fenêtre principale
    SetTopWindow(fenetreGL);
    
    Connect(wxID_ANY, wxEVT_TIMER, wxTimerEventHandler(Application::rotationCiel));
    
    timerCiel = new wxTimer(this);
    timerCiel->Start(50);
     
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
	telescope.dessine();
	ciel.dessine();
}

void Application::rotationCiel(wxTimerEvent& event)
{
	ciel.rotation();
	rafraichir();
}

void Application::rafraichir()
{
	fenetreGL->rafraichir();
}

//Remplacement du main
IMPLEMENT_APP(Application);
