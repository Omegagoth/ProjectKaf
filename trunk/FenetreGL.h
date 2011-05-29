#ifndef FENETRE_H
#define FENETRE_H
 
#include "wxIncludes.h"
#include "VueOpenGL.h"
 
class FenetreGL : public wxFrame //Héritage
{
    public:
    
		Vue getcamera() const;
		
		void setcamera(Vue);
    
        FenetreGL(wxString titre, wxSize taille);
        void rafraichir();
        
    private:
    
		VueOpenGL* vueopengl;
		wxMenuBar* statusBar;
		
		Vue camera;
		
		void redimensionne_vueopengl(wxSizeEvent& event);
		void fermer(wxCloseEvent& event);
};


#endif

