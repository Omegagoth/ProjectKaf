#ifndef DIPOLE3D_H
#define DIPOLE3D_H

#include "wxIncludes.h"
#include "Courbe3D.h"
#include "Dipole.h"


#define DIPOLE_ROUGE 0
#define DIPOLE_VERT 0
#define DIPOLE_BLEU 255
#define DIPOLE_TRANSPARENCE 255
#define DIPOLE_PRECISION 5




class Dipole3D : public Courbe3D, public Dipole
{
	public :
	
		Dipole3D();
		Dipole3D(Vecteur3D re, Vecteur3D rs, double R, double k, double i, unsigned int p = DIPOLE_PRECISION, unsigned int r = DIPOLE_ROUGE,
				unsigned int v = DIPOLE_VERT, unsigned int b = DIPOLE_BLEU, unsigned int t = DIPOLE_TRANSPARENCE);
		Dipole3D(Dipole3D const&);
		virtual ~Dipole3D();
		
		virtual Dipole3D* copie() const;
	
	protected :
	
};



#endif

