#include "Application.h"
 
bool Application::OnInit()
{
    //On alloue la fenêtre
    fenetreGL=new FenetreGL(wxT("Telescope"),wxSize(640, 480));
     
    //Définie comme fenêtre principale
    SetTopWindow(fenetreGL);
     
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
	particule.dessine();
	droit.dessine();
	courbe.dessine();
}

void Application::rafraichir()
{
	fenetreGL->rafraichir();
}

//Remplacement du main
IMPLEMENT_APP(Application);
