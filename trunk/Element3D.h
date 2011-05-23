#ifndef ELEMENT3D_H
#define ELEMENT3D_H

#include "wxIncludes.h"
#include "Element.h"
#include "Couleurs.h"

class Element3D : virtual public Element
{
	public :
	
	Couleurs getcouleurs() const;
	
	void setcouleurs(Couleurs const&);
	
	Element3D();
	Element3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r = ELEMENT_ROUGE, unsigned int v = ELEMENT_VERT,
			  unsigned int b = ELEMENT_BLEU, unsigned int t = ELEMENT_TRANSPARENCE);
	Element3D(Element3D const&);
	virtual ~Element3D();
	
	virtual void dessine() const = 0;
	virtual Element3D* copie() const = 0;
	
	protected :
	
		Couleurs couleurs;
};



#endif

