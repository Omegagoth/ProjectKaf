#ifndef VUEOPENGL_H
#define VUEOPENGL_H
 
#include "wxIncludes"
 
class VueOpenGL: public wxGLCanvas
{
public:
    VueOpenGL(wxWindow* parent, wxSize const& taille=wxDefaultSize, wxPoint const& position=wxDefaultPosition);
     
    void InitOpenGL();
     
private:
    void dessine(wxPaintEvent& event);
 
};


#endif


