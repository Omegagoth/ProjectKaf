#ifndef QUADRUPOLE3D_H
#define QUADRUPOLE3D_H

#include "Quadrupole.h"
#include "Droit3D.h"
#include "wxIncludes.h"


#define QUADRUPOLE_ROUGE 74
#define QUADRUPOLE_VERT 225
#define QUADRUPOLE_BLEU 23
#define QUADRUPOLE_TRANSPARENCE 255


class Quadrupole3D : public Droit3D, public Quadrupole
{
	public :
	
		Quadrupole3D();
		Quadrupole3D(Vecteur3D re, Vecteur3D rs, double R, double i, unsigned int r = QUADRUPOLE_ROUGE, unsigned int v = QUADRUPOLE_VERT,
					 unsigned int b = QUADRUPOLE_BLEU, unsigned int t = QUADRUPOLE_TRANSPARENCE);
		Quadrupole3D(Quadrupole3D const&);
		virtual ~Quadrupole3D();
		
		Quadrupole3D* copie() const;
	
	protected :
	
};


#endif

