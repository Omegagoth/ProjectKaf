#include "bunch.h"
#include <cmath>



Bunch::Bunch()
:Faisceau(), ecart_type(0), emittance(0), A22(0), A11(0) {}

Bunch::Bunch(Bunch const& b)
:Faisceau(b), ecart_type(b.getecart_type), emittance(b.getemittance), A22(b.getA22), A12(b.getA12) {}

Bunch::~Bunch() 
{}

//-----------------------------------------------------------

double Bunch::getecart_type() const
{return ecart_type;}

double Bunch::getemittance() const
{return emittance;}

double Bunch::getA22() const
{return A22;}

double Bunch::getA12() const
{return A12;}

double Bunch::getA11() const
{return (1 + (A12*A12)) / A22;}

double Bunch::getbunch_longueur() const
{return 4 * ecart_type;}

double Bunch::gettheta() const
{return atan( (2 * A12) / (getA11() - A22));}

double Bunch::geta() const
{return getA11() * pow(cos(gettheta()), 2) - 2 * ( A12 * cos(gettheta()) * sin(gettheta()) ) + A22 * pow(sin(gettheta()), 2);}

double Bunch::getb() const
{return getA11() * pow(sin(gettheta()), 2) - 2 * ( A12 * cos(gettheta()) * sin(gettheta()) ) + A22 * pow(cos(gettheta()), 2);}

double Bunch::getx() const		
{return sqrt(gaussienne(0, emittance / geta()));}

double Bunch::gety() const		
{return sqrt(gaussienne(0, emittance / getb()));}

double Bunch::getr() const
{return cos(gettheta()) * getx() + sin(gettheta()) * gety();}

double Bunch::getVr() const
{return cos(gettheta()) * gety() - sin(gettheta()) * getx();}

double Bunch::getx_z() const		
{return sqrt(gaussienne(0, emittance / geta()));}

double Bunch::gety_z() const		
{return sqrt(gaussienne(0, emittance / getb()));}

double Bunch::getz() const
{return cos(gettheta()) * getx_z() + sin(gettheta()) * gety_z();}

double Bunch::getVz() const
{return cos(gettheta()) * gety_z() - sin(gettheta()) * getx_z();}



//-----------------------------------------------------------


double Bunch::gaussienne(double moyenne, double ecart_type)
{
	double v1;
	double v2;
	double s ;
	
	do {
		v1 = uniforme(-1.0, 1.0);
		v2 = uniforme(-1.0, 1.0);
		s = v1*v1 + v2*v2;
	} while ((s >= 1.0) or (s == 0.0));
	
	double x(sqrt(-2.0 * log(s) / s));
	if (uniforme(0.0, 1.0) > 0.5)
		x *= v1;
	else
		x *= v2;
	
	return moyenne + ecart_type * x;
}


Bunch& Bunch::creation(double dt)
{
	double debit(getnb_particule3D() / getbunch_longueur());
	double fraction(debit*dt);
	int nombre(fraction);
	fraction -= nombre;
	if ( uniforme(0.0, 1.0) < fraction ) ++nombre;
	
	for (int unsigned i(0); i < Vpart.size(); ++i) 
	{
		
	}
	
	return (*this);
}









