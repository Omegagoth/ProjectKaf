#ifndef SECTION_DROITE3D_H
#define SECTION_DROITE3D_H

#include "wxIncludes.h"
#include "Section_droite.h"
#include "Droit3D.h"

class Section_droite3D : public Droit3D, public Section_droite
{
	public :
		
		Section_droite3D();
		Section_droite3D(Vecteur3D, Vecteur3D, double, unsigned int, unsigned int, unsigned int, unsigned int);
		Section_droite3D(Section_droite3D const&);
		virtual ~Section_droite3D();
		
		virtual Section_droite3D* copie() const;
	
	protected :
	
};


#endif

