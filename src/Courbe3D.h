#ifndef COURBE3D_H
#define COURBE3D_H

#include "wxIncludes.h"
#include "Courbe.h"
#include "Element3D.h"
#include <vector>


#define DEFAUT_PRECISION 5
#define COURBE_ROUGE 255
#define COURBE_VERT 255
#define COURBE_BLEU 255
#define COURBE_TRANSPARENCE 255


class Courbe3D : public Element3D, virtual public Courbe
{
	public :
	
		unsigned int getprecision() const;
		
		void setprecision(unsigned int);
	
		Courbe3D();
		Courbe3D(Vecteur3D re, Vecteur3D rs, double R, double k, unsigned int p = DEFAUT_PRECISION, unsigned int r = COURBE_ROUGE,
				unsigned int v = COURBE_VERT, unsigned int b = COURBE_BLEU, unsigned int t = COURBE_TRANSPARENCE);
		Courbe3D(Courbe3D const&);
		virtual ~Courbe3D();
		
		virtual void dessine() const;
		virtual Courbe3D* copie() const = 0;
	
	protected :
	
		int unsigned precision;
};

#endif
