#ifndef DESSINABLE_H
#define DESSINABLE_H

#include "Couleurs.h"

class Dessinable
{
	public :
	
		Couleurs getcouleurs() const;
		
		void setcouleurs(Couleurs const&);
		
		Dessinable();
		Dessinable(unsigned int, unsigned int, unsigned int, unsigned int);

		virtual void dessine() const = 0;   // méthode abstraite pure : dessine un quelque chose

	protected :
		
		Couleurs couleurs;
};


#endif
