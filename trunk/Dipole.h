#ifndef DIPOLE_H
#define DIPOLE_H

#include <iostream>
#include "Courbe.h"
using namespace std;


class Dipole : public Courbe									//  A FAIRE  //	
{
	
	protected :
	static double intensite;		// Intensité du champs magnétique vertical.
	
	
	//-------------------------------------------------------------------------------------------------------
	
	
	public :
	
	Dipole();														// constructeur par défault sans arguments
	Dipole(Vecteur3D, Vecteur3D, double, double);					// constructeur avec arguments
	Dipole(const Dipole &);											// constructeur de copie
	~Dipole();														// destructeur
	
	
	//-------------------------------------------------------------------------------------------------------
	
	
	double getintensite() const;				// méthodes get/set
	void setintensite(double);
	
	Vecteur3D getchamps_magnetique() const;		// méthode renvoyant le champs magnétique sous forme de vecteur.
	
	
	virtual void dessine(Dipole const&) const;
	
};

#endif