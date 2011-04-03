#ifndef SECTION_DROITE_H
#define SECTION_DROITE_H

#include <iostream>
#include "Droit.h"
using namespace std;

class Section_droite : public Droit										//  A FAIRE  //
{
	public :

        Section_droite();
        Section_droite(Vecteur3D, Vecteur3D, double);	// constructeurs.
        Section_droite(Section_droite const&);
        virtual ~Section_droite();
        virtual Section_droite* copie() const;          //méthode de copie polymorphique

};


#endif
