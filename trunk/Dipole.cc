#include <iostream>
#include "Dipole.h"
#include <cmath>
using namespace std;



//--------d�finition des m�thodes get----------------------------------------------------------------------------

double Dipole::getintensite() const
{
    return intensite;
}

Vecteur3D Dipole::getchamps_magnetique(Particule const&) const
{
    return E3*intensite;
}




//--------d�finition des m�thodes set----------------------------------------------------------------------------

void Dipole::setintensite(double d)
{
    intensite = d;
}



//--------d�finition des constructeurs/destructeurs--------------------------------------------------------------

Dipole::Dipole()
: intensite(0)
{}

Dipole::Dipole(Vecteur3D re, Vecteur3D rs, double Re, double k, double i)
: Courbe(re, rs, Re, k), intensite(i)
{}

Dipole::Dipole(const Dipole& d)
: Courbe(d), intensite(d.getintensite())
{}

Dipole::~Dipole()
{}




//--------d�finition des m�thodes--------------------------------------------------------------------------------

/*Dipole* Dipole::copie() const
{
    return new Dipole(*this);
}*/

void Dipole::affiche(ostream& out) const
{
    out << "    Dip�le :" << endl
    << "Entr�e : " << getre() << endl
    << "Sortie : " << getrs() << endl
    << "Rayon : " << getRe() << endl
    << "Rayon de courbure : " << getcourbure() << endl
    << "Centre de courbure : " << getcentre() << endl
    << "Intensit� : " << getintensite() << endl;
}

