#include "Faisceau.h"
#include "Random.h"


class Bunch : public Faisceau
{
	public :
	
	Bunch();
	Bunch(Bunch const&);
	virtual ~Bunch();
	
	//-----------------------------------------------------------
	
	double getecart_type() const;
	double getemittance() const;
	double getA22() const;
	double getA12() const;
	double getA11() const;
	double gettheta() const;
	double geta() const;
	double getb() const;
	double getx() const;
	double gety() const;
	double getr() const;
	double getVr() const;
	double getx_z() const;
	double gety_z() const;
	double getz() const;
	double getVz() const;
	double getnorme2_vitesse();
	
	
	//-----------------------------------------------------------
	
	double gaussienne(double, double);
	Bunch& creation(double);
	
	//-----------------------------------------------------------
	
	protected :
	
	double ecart_type;
	double emittance;
	double A22;
	double A12;
	double bunch_longueur;
	
	
};