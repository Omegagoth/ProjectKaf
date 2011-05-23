#include "Section_droite3D.h"

#define SECTION_DROITE_ROUGE 255
#define SECTION_DROITE_VERT 174
#define SECTION_DROITE_BLEU 200
#define SECTION_DROITE_TRANSPARENCE 255




Section_droite3D::Section_droite3D()
: Element(Vecteur3D(1,1,0), Vecteur3D(1,0,0), 0.1), Droit(), Droit3D(Vecteur3D(1,1,0), Vecteur3D(1,0,0), 0.1,SECTION_DROITE_ROUGE, SECTION_DROITE_VERT, SECTION_DROITE_BLEU, SECTION_DROITE_TRANSPARENCE), Section_droite(Vecteur3D(1,1,0), Vecteur3D(1,0,0), 0.1)
{}

Section_droite3D::Section_droite3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r = SECTION_DROITE_ROUGE, unsigned int v = SECTION_DROITE_VERT,
									unsigned int b = SECTION_DROITE_BLEU, unsigned int t = SECTION_DROITE_TRANSPARENCE)
: Element(re,rs,R), Droit(re,rs,R), Droit3D(re,rs,R,r,v,b,t), Section_droite(re,rs,R)
{}

Section_droite3D::Section_droite3D(Section_droite3D const& s)
: Element(s), Droit(s), Droit3D(s), Section_droite(s)
{}

Section_droite3D::~Section_droite3D()
{}




Section_droite3D* Section_droite3D::copie() const
{
	return new Section_droite3D(*this);
}


