#ifndef VUEOPENGL_H
#define VUEOPENGL_H
 
#include "wxIncludes"
#include <iostream>
 
class VueOpenGL: public wxGLCanvas
{
	public:
	
		VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
     
		void InitOpenGL();

		void redimensionne(int largeur, int hauteur); //permet d'ajuster la vue OpenGL à la taille de la fenetre

	private:

		void dessine(wxPaintEvent& event);
	
 
};


#endif


