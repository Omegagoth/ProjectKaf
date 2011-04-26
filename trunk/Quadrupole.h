#ifndef QUADRUPOLE_H
#define QUADRUPOLE_H

#include <iostream>
#include "Droit.h"

using namespace std;

class Quadrupole : public Droit
{
	public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

    double getintensite() const;
    virtual Vecteur3D getchamps_magnetique(Particule const& p) const;

//--------prototypage des méthodes set----------------------------------------------------------------------------

    void setintensite(double const&);

//--------prototypage des constructeurs/destructeur---------------------------------------------------------------

	Quadrupole();
	Quadrupole(Vecteur3D, Vecteur3D, double, double);
	Quadrupole(Quadrupole const&);
	virtual ~Quadrupole();

//--------prototypage des méthodes--------------------------------------------------------------------------------

	Vecteur3D coordonnees_locales(Particule const& p) const; //retourne le vecteur de position de la particule dans les coordonnees local (par rapport a la trajectoire ideal)
	virtual Quadrupole* copie() const;                       //méthode de copie polymorphique
	virtual void affiche(ostream&) const;                    //méthode polymorphique d'affichage
	//virtual void dessine(Quadrupole const&) const;




    protected :

//--------définition des attributs-------------------------------------------------------------------------------

	double intensite;
};

#endif
