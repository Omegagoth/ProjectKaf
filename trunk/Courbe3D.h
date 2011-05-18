#ifndef COURBE3D_H
#define COURBE3D_H

#include "wxIncludes.h"
#include "Courbe.h"
#include <vector>

class Courbe3D : public Courbe
{
	public :
	
		Courbe3D();
		Courbe3D(Vecteur3D, Vecteur3D, double, double);
		virtual ~Courbe3D();
		
		void dessine() const;
		
		virtual Vecteur3D getchamps_magnetique(Particule const&) const{}
		virtual Courbe3D* copie() const{}
		virtual void affiche(ostream&) const{}
	
	protected :
	
		void partie_tore(double, Vecteur3D) const;
	
};

#endif
