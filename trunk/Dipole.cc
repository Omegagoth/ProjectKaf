#include <iostream>
#include "Dipole.h"
#include <cmath>
using namespace std;



//-----------Dipole----------------------------------------------------------------------------------

//-----------Dipole------Constructeur/destructeur----------------------------------------------------

double Dipole::intensite(0);

Dipole::Dipole()
{}

Dipole::Dipole(Vecteur3D v1, Vecteur3D v2, double d1, double d2)
: Courbe(v1, v2, d1, d2)  {}

Dipole::Dipole(const Dipole& d)
:Courbe(d)  {}

Dipole::~Dipole()
{}



//-----------Dipole------get/set---------------------------------------------------------------------


double Dipole::getintensite() const
{return intensite;}


void Dipole::setintensite(double d)
{intensite = d;}

Vecteur3D Dipole::getchamps_magnetique() const
{return E3*intensite;}

//  virtual void dessine(Dipole const& d)         //  A FAIRE  //
//  {}

Dipole* Dipole::copie() const
{
    return new Dipole(*this);
}
