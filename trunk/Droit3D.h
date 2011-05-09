#ifndef DROIT3D_H
#define DROIT3D_H

#include "Droit.h"
#include "wxIncludes.h"

class Droit3D : public Droit
{
	public :
	
		Droit3D();
		Droit3D(Vecteur3D, Vecteur3D, double);
		
		void dessine() const;
	
	protected :
	
};


#endif

