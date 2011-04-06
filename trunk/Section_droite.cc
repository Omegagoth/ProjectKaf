#include <iostream>
#include "Section_droite.h"
using namespace std;

Section_droite::Section_droite()
{

}

Section_droite::Section_droite(Vecteur3D v1, Vecteur3D v2, double d)
:Droit(v1,v2, d)  {}

Section_droite::Section_droite(Section_droite const& s)
:Droit(s)  {}

Section_droite::~Section_droite()  {}


Section_droite* Section_droite::copie() const
{
    return new Section_droite(*this);
}

void Section_droite::affiche(ostream& out) const
{
    out << "    Section droite :" << endl
    << "Entrée : " << getre() << endl
    << "Sortie : " << getrs() << endl
    << "Rayon : " << getRe() << endl;
}

Vecteur3D Section_droite::getchamps_magnetique(Particule const& p) const
{
	return Vecteur3D(0,0,0);
}

