#ifndef BUNCH_H
#define BUNCH_H

#include "Faisceau.h"
#include "Random.h"


class Bunch : public Faisceau
{
	public :
	
	Bunch();
	Bunch(Particule3D const&, double, double, double, double, double, double, double);
	Bunch(Bunch const&);
	virtual ~Bunch();
	
	//-----------------------------------------------------------
	
	double getecart_type() const;
	double getemittance() const;
	double getbunch_longueur() const;
	double getnb_particule3D() const;
	double getA22() const;
	double getA12() const;
	double getA11() const;
	double gettheta() const;
	double geta() const;
	double getb() const;
	double getx();
	double gety();
	double getr();
	double getVr();
	double getx_z();
	double gety_z();
	double getz();
	double getVz();
	double getnorme2_vitesse();
	
	
	//-----------------------------------------------------------
	
	double gaussienne(double, double);
	Faisceau& creation(double);
	
	//-----------------------------------------------------------
	
	protected :
	
	double ecart_type;
	double emittance;
	double A22;
	double A12;
	double bunch_longueur;
	double nb_particule3D;
	
	
};

#endif
