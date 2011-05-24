#include "Dipole3D.h"





Dipole3D::Dipole3D()
: Element(), Courbe(), Courbe3D(), Dipole()
{}

Dipole3D::Dipole3D(Vecteur3D re, Vecteur3D rs, double R, double k, double i, unsigned int p, unsigned int r,
				unsigned int v, unsigned int b, unsigned int t)
: Element(re,rs,R), Courbe(re,rs,R,k), Courbe3D(re,rs,R,k,p,r,v,b,t), Dipole(re,rs,R,k,i)
{}

Dipole3D::Dipole3D(Dipole3D const& d)
: Element(d), Courbe(d), Courbe3D(d), Dipole(d)
{}

Dipole3D::~Dipole3D()
{}



Dipole3D* Dipole3D::copie() const
{
	return new Dipole3D(*this);
}
