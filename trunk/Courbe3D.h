#ifndef COURBE3D_H
#define COURBE3D_H

#include "wxIncludes.h"
#include "Courbe.h"
#include "Element3D.h"
#include <vector>

class Courbe3D : public Element3D, virtual public Courbe
{
	public :
	
		unsigned int getprecision() const;
		
		void setprecision(unsigned int);
	
		Courbe3D();
		Courbe3D(Vecteur3D, Vecteur3D, double, double, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
		Courbe3D(Courbe3D const&);
		virtual ~Courbe3D();
		
		virtual void dessine() const;
		virtual Courbe3D* copie() const = 0;
	
	protected :
	
		int unsigned precision;
};

#endif
