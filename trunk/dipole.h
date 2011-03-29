#ifndef DIPOLE_H
#define DIPOLE_H

#include <iostream>
#include "Courbe.h"

using namespace std;


class Dipole : public Courbe
{

	protected :
	static double champs_vertical;		// Champs magnétique vertical.


	//-------------------------------------------------------------------------------------------------------


	public :

	Dipole();														// constructeur par défault sans arguments
	Dipole(Vecteur3D, Vecteur3D, double, Vecteur3D, double);		// constructeur avec arguments
	Dipole(const Dipole &);											// constructeur de copie
	~Dipole();														// destructeur


	//-------------------------------------------------------------------------------------------------------


	double getchamps_vertical();			// méthodes get/set
	void setchamps_vertical(double);

	virtual void dessine(Dipole const&) const;

};

#endif
