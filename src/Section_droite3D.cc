#include "Section_droite3D.h"




Section_droite3D::Section_droite3D()
: Element(), Droit(), Droit3D(), Section_droite()
{}

Section_droite3D::Section_droite3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r, unsigned int v, unsigned int b, unsigned int t)
: Element(re,rs,R), Droit(re,rs,R), Droit3D(re,rs,R,r,v,b,t), Section_droite(re,rs,R)
{}

Section_droite3D::Section_droite3D(Section_droite3D const& s)
: Element(s), Droit(s), Droit3D(s), Section_droite(s)
{}

Section_droite3D::~Section_droite3D()
{}




Section_droite3D* Section_droite3D::copie() const
{
	return new Section_droite3D(*this);
}


