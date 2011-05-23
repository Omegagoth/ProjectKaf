#ifndef DIPOLE3D_H
#define DIPOLE3D_H

#include "wxIncludes.h"
#include "Courbe3D.h"
#include "Dipole.h"

class Dipole3D : public Courbe3D, public Dipole
{
	public :
	
		Dipole3D();
		Dipole3D(Vecteur3D re, Vecteur3D rs, double R, double k, double i, unsigned int p,
				unsigned int r, unsigned int v, unsigned int b, unsigned int t);
		Dipole3D(Dipole3D const&);
		virtual ~Dipole3D();
		
		virtual Dipole3D* copie() const;
	
	protected :
	
};



#endif

