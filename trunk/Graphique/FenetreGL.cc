#include "FenetreGL.h"
 
FenetreGL::FenetreGL(wxString titre, wxSize taille)
: wxFrame(0, wxID_ANY, titre, wxDefaultPosition, taille, wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMAXIMIZE_BOX)),
 vueopengl (new VueOpenGL(this))
{
    //On centre la fenêtre sur l'écran
    Center();
    //Et on l'affiche
    Show();
    
    vueopengl->InitOpenGL();
}

void FenetreGL::rafraichir()
{
	vueopengl->Refresh(false);
}

