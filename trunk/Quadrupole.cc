#include <iostream>
#include "Quadrupole.h"
using namespace std;

Quadrupole::Quadrupole()
:Droit(), champs_magnetique(0)  {}

Quadrupole::Quadrupole(Vecteur3D v1, Vecteur3D v2, double d1, double d2)
:Droit(v1,v2, d), champs_magnetique(d2)  {}

Quadrupole::Quadrupole(Quadrupole const& q)
:Droit(q), champs_magnetique(q.getchamps_magnetique)  {}

Quadrupole::~Quadrupole()  {}

double Quadrupole::getchamps_magnetique() const
{return champs_magnetique;}

vois Quadrupole::setchamps_magnetique(double const& d)
{champs_magnetique = d;}