#include "Quadrupole3D.h"

#define QUADRUPOLE_ROUGE 74
#define QUADRUPOLE_VERT 225
#define QUADRUPOLE_BLEU 23
#define QUADRUPOLE_TRANSPARENCE 255





Quadrupole3D::Quadrupole3D()
: Element(), Droit(), Droit3D(), Quadrupole()
{}

Quadrupole3D::Quadrupole3D(Vecteur3D re, Vecteur3D rs, double R, double i, unsigned int r, unsigned int v, unsigned int b, unsigned int t)
: Element(re,rs,R), Droit(re,rs,R), Droit3D(re,rs,R,r,v,b,t), Quadrupole(re,rs,R,i)
{}

Quadrupole3D::Quadrupole3D(Quadrupole3D const& q)
: Element(q), Droit(q), Droit3D(q), Quadrupole(q)
{}

Quadrupole::~Quadrupole()
{}




Quadrupole3D* Quadrupole3D::copie() const
{
	return new Quadrupole3D(*this);
}


