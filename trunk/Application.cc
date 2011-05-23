#include "Application.h"
 
bool Application::OnInit()
{
    //On alloue la fenêtre
    fenetreGL=new FenetreGL(wxT("Telescope"),wxSize(640, 480));
     
    //Définie comme fenêtre principale
    SetTopWindow(fenetreGL);
    
    //On initialise l'accélérateur
    cout << "Attention" << endl;
    acc.ajoute_element(Section_droite3D(Vecteur3D(2,1,0),Vecteur3D(2,-1,0),0.1,255,255,255,255));
    acc.ajoute_element(Dipole3D(Vecteur3D(2,-1,0), Vecteur3D(1,-2,0), 0.1, 1.,5.,10,255,255,255,255));
    acc.ajoute_element(Section_droite3D(Vecteur3D(1,-2,0), Vecteur3D(-1,-2,0),0.1,255,255,255,255));
    acc.ajoute_element(Dipole3D(Vecteur3D(-1,-2,0), Vecteur3D(-2,-1,0),0.1,1.,5.,10,255,255,255,255));
    acc.ajoute_element(Section_droite3D(Vecteur3D(-2,-1,0), Vecteur3D(-2,1,0),0.1,255,255,255,255));
    acc.ajoute_element(Dipole3D(Vecteur3D(-2,1,0), Vecteur3D(-1,2,0),0.1,1.,5.,10,255,255,255,255));
    acc.ajoute_element(Section_droite3D(Vecteur3D(-1,2,0), Vecteur3D(1,2,0),0.1,255,255,255,255));
    acc.ajoute_element(Dipole3D(Vecteur3D(1,2,0), Vecteur3D(2,1,0), 0.1, 1.,5.,10,255,255,255,255));
    cout << "C'est parti mon kiki" << endl;
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

void Application::rafraichir()
{
	fenetreGL->rafraichir();
}

//Remplacement du main
IMPLEMENT_APP(Application);
