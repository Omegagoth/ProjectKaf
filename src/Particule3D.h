#ifndef PARTICULE3D_H
#define PARTICULE3D_H

#include "Particule.h"
#include "wxIncludes.h"

class Particule3D : public Particule
{
	public :
	
		Particule3D();
		Particule3D(Vecteur3D position, Vecteur3D quantite_mouv, double masse, double charge);
        Particule3D(Vecteur3D, double, Vecteur3D, double, double);
        Particule3D(Particule3D const&);
        virtual ~Particule3D();
	
		void dessine() const;
	
	protected :
};



#endif

