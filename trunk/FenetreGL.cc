#include "FenetreGL.h"

FenetreGL::FenetreGL(wxString titre, wxSize taille)
: wxFrame(0, wxID_ANY, titre, wxDefaultPosition, taille, wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMAXIMIZE_BOX) ),
  vueopengl(new VueOpenGL(this))
{
	//On centre la fenêtre
	Center();
	
	//et on l'affiche
	Show(true);
	
	vueopengl->InitOpenGL();
}



void FenetreGL::rafraichir() const
{
	vueopengl->Refresh(false);
}

