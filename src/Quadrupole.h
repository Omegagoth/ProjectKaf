#ifndef QUADRUPOLE_H
#define QUADRUPOLE_H

#include <iostream>
#include "Droit.h"

using namespace std;

class Quadrupole : virtual public Droit
{
	public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

    double getintensite() const;											//retourne l'intensite du champs magnetique de l'element
    virtual Vecteur3D getchamps_magnetique(Particule const& p) const;		//retourne le champs magnetique en fonction de la position de la particule

//--------prototypage des méthodes set----------------------------------------------------------------------------

    void setintensite(double const&);										//permet de modifier l'intensite du champs magnetique

//--------prototypage des constructeurs/destructeur---------------------------------------------------------------

	Quadrupole();											//constructeur par default qui initialise a 0
	Quadrupole(Vecteur3D, Vecteur3D, double, double);		//constructeur qui prend en argument l'entree, la sortie, le rayon et l'intensite du champs magnetique
	Quadrupole(Quadrupole const&);							//constructeur de copie
	virtual ~Quadrupole();									//destructeur

//--------prototypage des méthodes--------------------------------------------------------------------------------

	Vecteur3D coordonnees_locales(Particule const& p) const; 	//retourne le vecteur de position de la particule dans les coordonnees local (par rapport a la trajectoire ideal)
	//virtual Quadrupole* copie() const;                      	//méthode de copie polymorphique
	virtual void affiche(ostream&) const;                    	//méthode polymorphique d'affichage
	//virtual void dessine(Quadrupole const&) const;




    protected :

//--------définition des attributs-------------------------------------------------------------------------------

	double intensite;		// intensite du champs magnetique
};

#endif
