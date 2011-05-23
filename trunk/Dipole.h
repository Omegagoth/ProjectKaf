#ifndef DIPOLE_H
#define DIPOLE_H

#include <iostream>
#include "Courbe.h"

using namespace std;


class Dipole : virtual public Courbe
{
	public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        double getintensite() const;                                      //methode renvoyant l'intensite du champs magnetique (= norme du vecteur champs de magnetique)
        virtual Vecteur3D getchamps_magnetique(Particule const& p) const; //méthode renvoyant le champs magnétique sous forme de vecteur.

//--------prototypage des méthodes set----------------------------------------------------------------------------

        void setintensite(double);

//--------prototypage des constructeurs/destructeur---------------------------------------------------------------

        Dipole();											  // constructeur par défault sans arguments
        Dipole(Vecteur3D, Vecteur3D, double, double, double); // constructeur avec arguments
        Dipole(Dipole const&);								  // constructeur de copie
        virtual ~Dipole();									  // destructeur

//--------prototypage des méthodes--------------------------------------------------------------------------------

        //virtual Dipole* copie() const;        //méthode de copie polymorphique
        virtual void affiche(ostream&) const; //méthode polymorphique d'affichage



	protected :

//--------définition des attributs-------------------------------------------------------------------------------

        double intensite; // Intensité du champs magnétique vertical.

};

#endif
