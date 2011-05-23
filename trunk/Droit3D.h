#ifndef DROIT3D_H
#define DROIT3D_H

#include "Droit.h"
#include "wxIncludes.h"
#include "Element3D.h"

class Droit3D : public Element3D, virtual public Droit
{
	public :
	
		Droit3D();
		Droit3D(Vecteur3D, Vecteur3D, double, unsigned int, unsigned int, unsigned int, unsigned int);
		Droit3D(Droit3D const&);
		virtual ~Droit3D();
		
		virtual void dessine() const;
		virtual Droit3D* copie() const = 0;
	
	protected :
	
};


#endif

