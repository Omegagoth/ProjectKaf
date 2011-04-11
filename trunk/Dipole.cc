#include <iostream>
#include "Dipole.h"
#include <cmath>
using namespace std;



//-----------Dipole----------------------------------------------------------------------------------

//-----------Dipole------Constructeur/destructeur----------------------------------------------------


Dipole::Dipole()
: intensite(0)
{}

Dipole::Dipole(Vecteur3D re, Vecteur3D rs, double Re, double k, double i)
: Courbe(re, rs, Re, k), intensite(i)  {}

Dipole::Dipole(const Dipole& d)
: Courbe(d), intensite(d.getintensite())  {}

Dipole::~Dipole()
{}



//-----------Dipole------get/set---------------------------------------------------------------------


double Dipole::getintensite() const
{return intensite;}


void Dipole::setintensite(double d)
{intensite = d;}

Vecteur3D Dipole::getchamps_magnetique(Particule const&) const
{return E3*intensite;}

//  virtual void dessine(Dipole const& d)         //  A FAIRE  //
//  {}

Dipole* Dipole::copie() const
{
    return new Dipole(*this);
}

void Dipole::affiche(ostream& out) const
{
    out << "    Dipôle :" << endl
    << "Entrée : " << getre() << endl
    << "Sortie : " << getrs() << endl
    << "Rayon : " << getRe() << endl
    << "Rayon de courbure : " << getcourbure() << endl
    << "Centre de courbure : " << getcentre() << endl
    << "Intensité : " << getintensite() << endl;
}
