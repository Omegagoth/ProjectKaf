#ifndef QUADRUPOLE_H
#define QUADRUPOLE_H

#include <iostream>
#include "Droit.h"
using namespace std;

class Quadrupole : public Droit
{
	protected :

	double intensite;

	public :

	Quadrupole();
	Quadrupole(Vecteur3D, Vecteur3D, double, double);
	Quadrupole(Quadrupole const&);
	virtual ~Quadrupole();

	double getintensite() const;
	void setintensite(double const&);

	Vecteur3D coordonnees_locales(Particule const& p) const;

	Vecteur3D getchamps_magnetique(Particule const& p) const;

	virtual Quadrupole* copie() const;    //méthode de copie polymorphique
	virtual void affiche(ostream&) const; //méthode polymorphique d'affichage

	//virtual void dessine(Quadrupole const&) const;

};

#endif
