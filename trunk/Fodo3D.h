#ifndef FODO3D_H
#define FODO3D_H

#include "wxIncludes.h"
#include "Fodo.h"
#include "Section_droite3D.h"
#include "Quadrupole3D.h"
#include "Droit3D.h"

#define FODO_ROUGE 255
#define FODO_VERT 255
#define FODO_BLEU 255
#define FODO_TRANSPARENCE 100


class Fodo3D : public Droit3D, public Fodo
{
	public :
	
		Fodo3D();
		Fodo3D(Vecteur3D re, Vecteur3D rs, double R, double i, double l, unsigned int r = FODO_ROUGE, unsigned int v = FODO_VERT,
			   unsigned int b = FODO_BLEU, unsigned int t = FODO_TRANSPARENCE);
		Fodo3D(Fodo3D const&);
		~Fodo3D();
		
		virtual Fodo3D* copie() const;
		virtual void dessine() const;
};

#endif
