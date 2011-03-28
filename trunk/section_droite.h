#ifndef SECTION_DROITE_H
#define SECTION_DROITE_H

#include <iostream>
#include "Vecteur3D.h"
#include "Particule.h"
#include "Element.h"
using namespace std;

class Section_droite : public Droit										//  A FAIRE  //
{
	Section_droite();
	Section_droite(Vecteur3D, Vecteur3D, double);	// constructeurs.
	Section_droite(Section_droite const&);
	~Section_droite();
	
};


#endif