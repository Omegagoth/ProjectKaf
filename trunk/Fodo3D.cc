#include "Fodo3D.h"

#define FODO_ROUGE 
#define FODO_VERT 
#define FODO_BLEU 
#define FODO_TRANSPARENCE 




Fodo3D::Fodo3D()
: Element(), Droit(), Droit3D(), Fodo()
{}

Fodo3D::Fodo3D(Vecteur3D re, Vecreur3D rs, double R, double i, double l, unsigned int r = FODO_ROUGE, unsigned int v = FODO_VERT,
				unsigned int b = FODO_BLEU, unsigned int t = FODO_TRANSPARENCE)
: Element(re,rs,R), Droit(re,rs,R), Droit3D(re,rs,R,r,v,b,t), Fodo(re,rs,R,i,l)
{
	clear();
	Vecteur3D a(re + getlongueur_quadrupole()*getdirection());
    maille.push_back(new Quadrupole3D(e, a, r, i));
    maille.push_back(new Section_droite3D(a, a + getlongueur_droit()*getdirection(), r));
    maille.push_back(new Quadrupole3D(a + getlongueur_droit()*getdirection(), rs - getlongueur_droit()*getdirection(), r, -i));
    maille.push_back(new Section_droite3D(rs - getlongueur_droit()*getdirection(), rs, r));

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


