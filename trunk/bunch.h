#include "Faisceau.h"


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
	double getbunch_longueur() const;
	double gettheta() const;
	double geta() const;
	double getb() const;
	double getx() const;
	double gety() const;
	double getr() const;
	double getVr() const;
	
	
	//-----------------------------------------------------------
	
	
	
	protected :
	
	double ecart_type;
	double emittance;
	double A22;
	double A12;
	
	
};