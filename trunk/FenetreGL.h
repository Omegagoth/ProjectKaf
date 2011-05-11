#ifndef FENETREGL_H
#define FENETREGL_H

#include "wxIncludes.h"
#include "VueOpenGL.h"

class FenetreGL : public wxFrame
{
	public :
	
		FenetreGL(wxString, wxSize);
		
		void rafraichir() const;
	
	protected :
	
		VueOpenGL* vueopengl;
};


#endif

