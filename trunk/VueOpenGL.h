#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include "wxIncludes.h"
#include "Camera.h"

class VueOpenGL : public wxGLCanvas
{
	public :
	
		VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
		virtual ~VueOpenGL();
		
		void InitOpenGL();
		
	private :
	
		void dessine(wxPaintEvent&);
};


#endif

