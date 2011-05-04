#ifndef VUEOPENGL_H
#define VUEOPENGL_H
 
#include "wxIncludes"
#include "Camera.h"
#include "GLUtils.h"
 
class VueOpenGL: public wxGLCanvas
{
	public:
		
		VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);

		void InitOpenGL();
		
		void appuiTouche(wxKeyEvent&);
		void dessineSol(double);

	private:
	
		Camera camera;
		
		void dessine(wxPaintEvent& event);
};


#endif


