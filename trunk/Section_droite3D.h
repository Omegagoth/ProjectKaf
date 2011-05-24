#ifndef SECTION_DROITE3D_H
#define SECTION_DROITE3D_H

#include "wxIncludes.h"
#include "Section_droite.h"
#include "Droit3D.h"


#define SECTION_DROITE_ROUGE 255
#define SECTION_DROITE_VERT 174
#define SECTION_DROITE_BLEU 200
#define SECTION_DROITE_TRANSPARENCE 255


class Section_droite3D : public Droit3D, public Section_droite
{
	public :
		
		Section_droite3D();
		Section_droite3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r = SECTION_DROITE_ROUGE, unsigned int v = SECTION_DROITE_VERT,
		unsigned int b = SECTION_DROITE_BLEU, unsigned int t = SECTION_DROITE_TRANSPARENCE);
		Section_droite3D(Section_droite3D const&);
		virtual ~Section_droite3D();
		
		virtual Section_droite3D* copie() const;
	
	protected :
	
};


#endif

