#ifndef QUADRUPOLE3D_H
#define QUADRUPOLE3D_H

#include "Quadrupole.h"
#include "Droit3D.h"
#include "wxIncludes.h"

class Quadrupole3D : public Droit3D, public Quadrupole
{
	public :
	
		Quadrupole3D();
		Quadrupole3D(Vecteur3D, Vecteur3D, double, double, unsigned int, unsigned int, unsigned int, unsigned int);
		Quadrupole3D(Quadrupole3D const&);
		~Quadrupole3D();
		
		Quadrupole3D* copie() const;
	
	protected :
	
};


#endif

