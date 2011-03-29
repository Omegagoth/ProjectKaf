#include <iostream>
#include "Quadrupole.h"
using namespace std;

Quadrupole::Quadrupole()
:Droit(), intensite(0)  {}

Quadrupole::Quadrupole(Vecteur3D v1, Vecteur3D v2, double d1, double d2)
:Droit(v1,v2, d1), intensite(d2)  {}

Quadrupole::Quadrupole(Quadrupole const& q)
:Droit(q), intensite(q.getintensite())  {}

Quadrupole::~Quadrupole()  {}

double Quadrupole::getintensite() const
{return intensite;}

void Quadrupole::setintensite(double const& d)
{intensite = d;}

Vecteur3D Quadrupole::coordonnees_locales(Particule const& p) const
{
	return ( getpos_relative(p) - ((getpos_relative(p) * getdirection()) * getdirection()) );
}


Vecteur3D Quadrupole::getchamps_magnetique(Particule const& p) const
{
	return intensite * (( coordonnees_locales(p) * (E3^(this*).getdirection())) * E3 + (p.getposition().getz() * (E3^(this*).getdirection())));
}

