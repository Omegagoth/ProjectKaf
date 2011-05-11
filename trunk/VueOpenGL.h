#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include "wxIncludes.h"

using namespace std;

class VueOpenGL : public wxGLCanvas
{
	public :
	
		VueOpenGL(wxWindow*, wxSize const&, wxPoint const&);
		virtual ~VueOpenGL();
		
		void InitOpenGL();
	
	protected :
	
		void dessine(wxPaintEvent&);
};



#endif

