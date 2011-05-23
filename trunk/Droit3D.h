#ifndef DROIT3D_H
#define DROIT3D_H

#include "Droit.h"
#include "wxIncludes.h"
#include "Element3D.h"


#define DROIT3D_ROUGE
#define DROIT3D_VERT
#define DROIT3D_BLEU
#define DROIT3D_TRANSPARENCE



class Droit3D : public Element3D, virtual public Droit
{
	public :
	
		Droit3D();
		Droit3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r = , unsigned int v, unsigned int b, unsigned int t);
		Droit3D(Droit3D const&);
		virtual ~Droit3D();
		
		virtual void dessine() const;
		virtual Droit3D* copie() const = 0;
	
	protected :
	
};


#endif

