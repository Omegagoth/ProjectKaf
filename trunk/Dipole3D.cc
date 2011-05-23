#include "Dipole3D.h"
#define DIPOLE_ROUGE 255
#define DIPOLE_VERT 255
#define DIPOLE_BLEU 255
#define DIPOLE_TRANSPARENCE 255
#define DIPOLE_PRECISION 3




Dipole3D::Dipole3D()
: Element(Vecteur3D(3,2,0), Vecteur3D(2,-1,0), 0.1), Courbe(Vecteur3D(3,2,0), Vecteur3D(2,-1,0), 0.1,1/4.), Courbe3D(Vecteur3D(3,2,0), Vecteur3D(2,-1,0), 0.1,1/4.,DIPOLE_PRECISION,DIPOLE_ROUGE,DIPOLE_VERT,DIPOLE_BLEU,DIPOLE_TRANSPARENCE), Dipole()
{}

Dipole3D::Dipole3D(Vecteur3D re, Vecteur3D rs, double R, double k, double i, unsigned int p = DIPOLE_PRECISION, unsigned int r = DIPOLE_ROUGE,
				unsigned int v = DIPOLE_VERT, unsigned int b = DIPOLE_BLEU, unsigned int t = DIPOLE_TRANSPARENCE)
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
