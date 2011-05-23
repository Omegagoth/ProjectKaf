#ifndef SECTION_DROITE_H
#define SECTION_DROITE_H

#include <iostream>
#include "Droit.h"

using namespace std;

class Section_droite : virtual public Droit
{
	public :

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        virtual Vecteur3D getchamps_magnetique(Particule const&) const; // methode qui renvoie un vecteur nul

//--------prototypage des constructeurs/destructeur---------------------------------------------------------------

        Section_droite();                             //constructeur par defaut qui initialise a 0
        Section_droite(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entree, de sortie et le rayon
        Section_droite(Section_droite const&);        //constructeur de copie
        virtual ~Section_droite();                    //destructeur

//--------prototypage des m�thodes--------------------------------------------------------------------------------

        virtual Section_droite* copie() const; //m�thode de copie polymorphique
        virtual void affiche(ostream&) const;  //m�thode polymorphique d'affichage
};


#endif
