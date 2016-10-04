#include "FenetreGL.h"
#include "Application.h"

Vue FenetreGL::getcamera() const
{
	return camera;
}

void FenetreGL::setcamera(Vue v)
{
	camera = v;
	if(camera == Libre)
	{
		vueopengl->setcamera(*new Camera());
	}
	else
	{
		vueopengl->setcamera(*new CameraSuivre());
	}
}

 
FenetreGL::FenetreGL(wxString titre, wxSize taille)
: wxFrame(0, wxID_ANY, titre, wxDefaultPosition, taille, wxDEFAULT_FRAME_STYLE | wxSYSTEM_MENU),
  vueopengl (new VueOpenGL(this)), camera(Libre)
{
    //On centre la fenêtre sur l'écran
    Center();
    //Et on l'affiche
    Show(true);
    
    vueopengl->InitOpenGL();
    
    Connect(wxEVT_SIZE, wxSizeEventHandler(FenetreGL::redimensionne_vueopengl));
    Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(FenetreGL::fermer));
}

void FenetreGL::rafraichir()
{
	vueopengl->Refresh(false);
}

void FenetreGL::redimensionne_vueopengl(wxSizeEvent& event)
{
	vueopengl->redimensionne(GetSize().GetWidth(), GetSize().GetHeight()); //On redimensionne la fenêtre OpenGL pour qu'elle occupe toute la fenêtre
}

void FenetreGL::fermer(wxCloseEvent& event)
{
	wxGetApp().fermer();
}

