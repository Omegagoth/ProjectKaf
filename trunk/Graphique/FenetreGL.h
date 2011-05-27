#ifndef FENETRE_H
#define FENETRE_H
 
#include "wxIncludes"
#include "VueOpenGL.h"
 
class FenetreGL : public wxFrame //Héritage
{
    public:
        FenetreGL(wxString titre, wxSize taille);
        //void rafraichir();
        
    private:
		//VueOpenGL* vueopengl;
		wxFlexGridSizer* vert;
		wxBoxSizer* hori;
		wxStaticText* texte;

		//void ajuster(wxSizeEvent& event);
};


#endif

