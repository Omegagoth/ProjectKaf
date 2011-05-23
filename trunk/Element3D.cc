#include "Element3D.h"
#define ELEMENT_ROUGE 255
#define ELEMENT_VERT 255
#define ELEMENT_BLEU 255
#define ELEMENT_TRANSPARENCE 255




Couleurs Element3D::getcouleurs() const
{
	return couleurs;
}




void Element3D::setcouleurs(Couleurs const& c)
{
	couleurs = c;
}




Element3D::Element3D()
: Element(), couleurs(ELEMENT_ROUGE, ELEMENT_VERT,ELEMENT_BLEU, ELEMENT_TRANSPARENCE)
{}

Element3D::Element3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r = ELEMENT_ROUGE, unsigned int v = ELEMENT_VERT,
					unsigned int b = ELEMENT_BLEU, unsigned int t = ELEMENT_TRANSPARENCE)
: Element(re,rs,R), couleurs(r,v,b,t)
{}

Element3D::Element3D(Element3D const& e)
: Element(e), couleurs(e.getcouleurs())
{}

Element3D::~Element3D()
{}
