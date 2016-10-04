#include "Fodo3D.h"




Fodo3D::Fodo3D()
: Element(), Droit(), Droit3D(), Fodo()
{}

Fodo3D::Fodo3D(Vecteur3D re, Vecteur3D rs, double R, double i, double l, unsigned int r, unsigned int v, unsigned int b, unsigned int t)
: Element(re,rs,R), Droit(re,rs,R), Droit3D(re,rs,R,r,v,b,t), Fodo(re,rs,R,i,l)
{
	for (unsigned int i(0); i < taille; ++i)
	{
		Vecteur3D a(re + ((i+1)/taille)*getlongueur_quadrupole()*getdirection());
		maille.push_back(new Quadrupole3D(re, a, R, i));
		maille.push_back(new Section_droite3D(a, a + getlongueur_droit()*getdirection(), R));
		maille.push_back(new Quadrupole3D(a + getlongueur_droit()*getdirection(), rs - getlongueur_droit()*getdirection(), R, -i));
		maille.push_back(new Section_droite3D(rs - getlongueur_droit()*getdirection(), rs, R));
	}

    for (int unsigned j(0); j < maille.size()-1; ++j)
    {
        (*maille[j]).setElement_suivant(*maille[j+1]);
    }
}

Fodo3D::Fodo3D(Fodo3D const& f)
: Element(f), Droit(f), Droit3D(f), Fodo(f)
{}

Fodo3D::~Fodo3D()
{}




Fodo3D* Fodo3D::copie() const
{
	return new Fodo3D(*this);
}

void Fodo3D::dessine() const
{
	for(unsigned int i(0); i < maille.size(); ++i)
	{
		maille[i]->dessine();
	}
}


