#ifndef DROIT3D_H
#define DROIT3D_H

#include "Droit.h"
#include "wxIncludes.h"
#include "Element3D.h"


#define DROIT3D_ROUGE 255
#define DROIT3D_VERT 255
#define DROIT3D_BLEU 255
#define DROIT3D_TRANSPARENCE 255



class Droit3D : public Element3D, virtual public Droit
{
	public :
	
		Droit3D();
		Droit3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r = DROIT3D_ROUGE, unsigned int v = DROIT3D_VERT,
				unsigned int b = DROIT3D_BLEU, unsigned int t = DROIT3D_TRANSPARENCE);
		Droit3D(Droit3D const&);
		virtual ~Droit3D();
		
		virtual void dessine() const;
		virtual Droit3D* copie() const = 0;
	
	protected :
	
};


#endif

