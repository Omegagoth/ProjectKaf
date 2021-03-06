#ifndef VUEOPENGL_H
#define VUEOPENGL_H
 
#include "wxIncludes.h"
#include "Camera.h"
#include "GLUtils.h"
 
class VueOpenGL: public wxGLCanvas
{
	public:
	
		Camera* getcamera() const;
		
		void setcamera(Camera const&);
		
		VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
		virtual ~VueOpenGL();

		void InitOpenGL();
		
		void dessineSol(double);
		
		void redimensionne(int largeur, int hauteur);

	protected:
	
		Camera* camera;
		
		void dessine(wxPaintEvent& event);
		void appuiTouche(wxKeyEvent&);
		void bougeSouris(wxMouseEvent&);
		void clicSouris(wxMouseEvent&);
		void moletteSouris(wxMouseEvent&);
		
		int x_souris;
		int y_souris;
};


#endif


