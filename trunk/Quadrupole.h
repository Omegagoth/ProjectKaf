#ifndef QUADRUPOLE_H
#define QUADRUPOLE_H

#include <iostream>
#include "Vecteur3D.h"
#include "Particule.h"
#include "Element.h"
using namespace std;

class Quadrupole : public Droit
{
	protected :
	
	double champs_magnetique;
	
	public :
	
	Quadrupole();
	Quadrupole(Vecteur3D, Vecteur3D, double, double);
	Quadrupole(Quadrupole const&);
	
	double getchamps_magnetique() const;
	void setchamps_magnetique(double const&);
	
	virtual void dessine(Quadrupole const&) const;
	
};

#endif