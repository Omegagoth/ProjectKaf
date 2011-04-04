#ifndef DIPOLE_H
#define DIPOLE_H

#include <iostream>
#include "Courbe.h"
using namespace std;


class Dipole : public Courbe									//  A FAIRE  //
{

	protected :

	double intensite;		// Intensité du champs magnétique vertical.


	//-------------------------------------------------------------------------------------------------------


	public :

        Dipole();														// constructeur par défault sans arguments
        Dipole(Vecteur3D, Vecteur3D, double, double,double);			// constructeur avec arguments
        Dipole(const Dipole &);											// constructeur de copie
        virtual ~Dipole();												// destructeur


//-------------------------------------------------------------------------------------------------------


        double getintensite() const;				// méthodes get/set
        void setintensite(double);

        Vecteur3D getchamps_magnetique() const;		// méthode renvoyant le champs magnétique sous forme de vecteur.

        virtual Dipole* copie() const;              //méthode de copie polymorphique
        virtual void affiche(ostream&) const;       //méthode polymorphique d'affichage

	//virtual void dessine(Dipole const&) const;

};

#endif
