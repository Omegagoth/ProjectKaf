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

double Bunch::getx() const		// A FAIRE //
{return ;}

double Bunch::gety() const		// A FAIRE //
{return ;}

double Bunch::getr() const
{return cos(gettheta()) * getx() + sin(gettheta()) * gety();}

double Bunch::getVr() const
{return cos(gettheta()) * gety() - sin(gettheta()) * getx();}

//-----------------------------------------------------------

