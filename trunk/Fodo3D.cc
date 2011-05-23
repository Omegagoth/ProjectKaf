#include "Fodo3D.h"




Fodo3D::Fodo3D()
: Element(), Droit(), Droit3D(), Fodo()
{}

Fodo3D::Fodo3D(Vecteur3D re, Vecreur3D rs, double R, double i, double l, unsigned int r, unsigned int v, unsigned int b, unsigned int t)
: Element(re,rs,R), Droit(re,rs,R), Droit3D(re,rs,R,r,v,b,t), Fodo(re,rs,R,i,l)
{}

Fodo3D::Fodo3D(Fodo3D const& f)
: Element(f), Droit(f), Droit3D(f), Fodo(f)
{}

Fodo3D::~Fodo3D()
{}




Fodo3D* Fodo3D::copie() const
{
	return new Fodo3D(*this);
}


