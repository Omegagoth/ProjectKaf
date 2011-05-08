#ifndef VUEOPENGL_H
#define VUEOPENGL_H
 
#include "wxIncludes"
#include "Camera.h"
#include "GLUtils.h"
 
class VueOpenGL: public wxGLCanvas
{
	public:
		
		VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
		virtual ~VueOpenGL();

		void InitOpenGL();
		
		void dessineSol(double);

	protected:
	
		Camera camera;
		
		void dessine(wxPaintEvent& event);
		void appuiTouche(wxKeyEvent&);
		void bougeSouris(wxMouseEvent&);
		void clicSouris(wxMouseEvent&);
		void moletteSouris(wxMouseEvent&);
		
		int x_souris;
		int y_souris;
};


#endif


