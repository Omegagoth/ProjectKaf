#include "Application.h"



void Application::dessine() const
{
	droit.dessine();
	particule.dessine();
}




bool Application::OnInit()
{
	//On alloue la fenêtre
	fenetreGL = new FenetreGL(wxT("Accelerateur"), wxSize(640, 480));
	
	//On la défine comme fenêtre principale
	SetTopWindows(fenetreGL);
	
	return (fenetreGL !=0 );
}

void Application::rafraichir() const
{
	fenetreGL->rafraichir();
}


IMPLEMENT_APP(Application);
