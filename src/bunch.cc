#include "bunch.h"
#include <cmath>

//--------------------constructeurs/destructeurs---------------------------------------

Bunch::Bunch()
:Faisceau(), ecart_type(0), emittance(0), A22(0), A12(0) {}

Bunch::Bunch(Particule3D const& ref, double l, double ecart, double emi, double a12, double a22, double lon, double nb)
:Faisceau(ref, l), ecart_type(ecart), emittance(emi), A12(a12), A22(a22), bunch_longueur(lon), nb_particule3D(nb)
{}

Bunch::Bunch(Bunch const& b)
:Faisceau(b), ecart_type(b.getecart_type()), emittance(b.getemittance()), A22(b.getA22()), A12(b.getA12()), bunch_longueur(b.getbunch_longueur()), nb_particule3D(b.getnb_particule3D())
{}

Bunch::~Bunch() 
{}

//--------------------------methodes get---------------------------------

double Bunch::getecart_type() const
{return ecart_type;}

double Bunch::getemittance() const
{return emittance;}

double Bunch::getbunch_longueur() const
{return bunch_longueur;}

double Bunch::getnb_particule3D() const
{
	return nb_particule3D;
}

double Bunch::getA22() const
{return A22;}

double Bunch::getA12() const
{return A12;}

double Bunch::getA11() const
{return (1 + (A12*A12)) / A22;}

double Bunch::gettheta() const
{return atan( (2 * A12) / (getA11() - A22));}

double Bunch::geta() const
{return getA11() * pow(cos(gettheta()), 2) - 2 * ( A12 * cos(gettheta()) * sin(gettheta()) ) + A22 * pow(sin(gettheta()), 2);}

double Bunch::getb() const
{return getA11() * pow(sin(gettheta()), 2) - 2 * ( A12 * cos(gettheta()) * sin(gettheta()) ) + A22 * pow(cos(gettheta()), 2);}

double Bunch::getx()		
{return sqrt(gaussienne(0, emittance / geta()));}

double Bunch::gety()		
{return sqrt(gaussienne(0, emittance / getb()));}

double Bunch::getr()
{return cos(gettheta()) * getx() + sin(gettheta()) * gety();}

double Bunch::getVr()
{return cos(gettheta()) * gety() - sin(gettheta()) * getx();}

double Bunch::getx_z()		
{return sqrt(gaussienne(0, emittance / geta()));}

double Bunch::gety_z()		
{return sqrt(gaussienne(0, emittance / getb()));}

double Bunch::getz()
{return cos(gettheta()) * getx_z() + sin(gettheta()) * gety_z();}

double Bunch::getVz()
{return cos(gettheta()) * gety_z() - sin(gettheta()) * getx_z();}

double Bunch::getnorme2_vitesse()
{return gaussienne(reference.getvitesse().norme_carre(), ecart_type);}



//-------------------------methodes publiques----------------------------------


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


Faisceau& Bunch::creation(double dt)
{
	double debit(getnb_particule3D() / bunch_longueur);
	double fraction(debit*dt);
	int nombre(fraction);
	fraction -= nombre;
	if ( uniforme(0.0, 1.0) < fraction ) ++nombre;
	
	for (int unsigned i(0); i < nombre; ++i) 
	{
		Vecteur3D E3(0,0,1);
		Particule3D p(reference);
		p.setvitesse(getVr() * p.getappartient()->getu(reference) + getVz() * E3 + sqrt( getnorme2_vitesse() - getVr()*getVr() - getVz()*getVz()) * p.getappartient()->getu(reference) ^ E3);
		double composante_s(gaussienne(0, bunch_longueur / 4));
		
		p.setposition(reference.getposition() + getr() * p.getappartient()->getu(reference) + getz() * E3 + composante_s * p.getappartient()->getu(reference) ^ E3);
		
		Vpart.push_back(new Particule3D(p));
		
	}
	
	return (*this);
}









