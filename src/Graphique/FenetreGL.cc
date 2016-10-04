#include "FenetreGL.h"
 
FenetreGL::FenetreGL(wxString titre, wxSize taille)
: wxFrame(0, wxID_ANY, titre, wxDefaultPosition, taille, wxDEFAULT_FRAME_STYLE),
  /*vueopengl (new VueOpenGL(this)),*/ hori(new wxBoxSizer(wxVERTICAL)), vert (new wxFlexGridSizer(2,1,10,0)), texte(new wxStaticText(this, wxID_ANY, wxT("Coucou")))
{
    //On centre la fenêtre sur l'écran
    Center();
	
	//vert->Add(vueopengl, 1, wxALL, 50);
	
	//vert->SetDimension(0,0, 540,380);
	

	vert->Add(texte, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_BOTTOM | wxGROW);

	vert->AddGrowableRow(0);

	hori->Add(vert,1, wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL | wxEXPAND);	
	SetSizer(hori);
	//vert->SetItemMinSize(vueopengl, 640,480);
	
	//Et on l'affiche
	Show();

	//Connect(wxEVT_SIZE, wxSizeEventHandler(FenetreGL::ajuster));

	//vueopengl->InitOpenGL();
}
/*
void FenetreGL::rafraichir()
{
	vueopengl->Refresh(false);
}

void FenetreGL::ajuster(wxSizeEvent& event)
{
	vueopengl->redimensionne(vert->GetSize().GetWidth()- 100, vert->GetSize().GetHeight()-120);
}*/

