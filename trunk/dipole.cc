#include <iostream>
#include "Dipole.h"
#include <cmath>
using namespace std;



//-----------Dipole----------------------------------------------------------------------------------

//-----------Dipole------Constructeur/destructeur----------------------------------------------------


Dipole::Dipole() 
: Courbe() {}

Dipole::Dipole(Vecteur3D v1, Vecteur3D v2, double d1, double d2)
: Courbe(v1, v2, d1, d2)  {}

Dipole::Dipole(const Dipole& d)
:Courbe(d)  {}

Dipole::~Dipole()
{}



//-----------Dipole------get/set---------------------------------------------------------------------


double Dipole::getchamps_vertical()
{return champs_vertical;}


void Dipole::setchamps_vertical(double d)
{champs_vertical = d;}

//  virtual void dessine(Dipole const& d)         //  A FAIRE  //
//  {}
