#include "Vecteur3D.h"
#include <iostream>
#include <cmath>

using namespace std;



//--------définition des méthodes get----------------------------------------------------------------------------

double Vecteur3D::getx() const
{
    return x;
}

double Vecteur3D::gety() const
{
    return y;
}

double Vecteur3D::getz() const
{
    return z;
}




//--------définition des méthodes set----------------------------------------------------------------------------

void Vecteur3D::setx(double a)
{
    x = a;
}

void Vecteur3D::sety(double a)
{
    y = a;
}

void Vecteur3D::setz(double a)
{
    z = a;
}




//--------définition des constructeurs---------------------------------------------------------------------------

Vecteur3D::Vecteur3D()
: x(0), y(0), z(0)
{}

Vecteur3D::Vecteur3D(double a, double b, double c)
: x(a), y(b), z(c)
{}





//--------définition des surcharges d'opérateurs-----------------------------------------------------------------

bool Vecteur3D::operator==(Vecteur3D const& v) const
{
    return ( (x == v.getx()) && (y == v.gety()) && (z == v.getz()) );
}

bool Vecteur3D::operator!=(Vecteur3D const& v) const
{
	return !(*this == v);
}




//--------définition des surcharges d'opérateurs arithmétique----------------------------------------------------

Vecteur3D& Vecteur3D::operator+=(Vecteur3D const& v)
{
    x += v.getx();
    y += v.gety();
    z += v.getz();

    return (*this);
}

Vecteur3D Vecteur3D::operator+(Vecteur3D const& v) const
{
    return Vecteur3D(*this) += v;
}

Vecteur3D& Vecteur3D::operator-=(Vecteur3D const& v)
{
    x -= v.getx();
    y -= v.gety();
    z -= v.getz();

    return (*this);
}

Vecteur3D Vecteur3D::operator-(Vecteur3D const& v) const
{
    return Vecteur3D(*this) -= v;
}

Vecteur3D Vecteur3D::operator-() const
{
    return Vecteur3D(-x, -y, -z);
}

double Vecteur3D::operator*(Vecteur3D const& v) const
{
    return x*v.getx() + y*v.gety() + z*v.getz();
}

Vecteur3D Vecteur3D::operator^(Vecteur3D const& v) const
{
    return Vecteur3D(y*v.getz() - z*v.gety(), z*v.getx() - x*v.getz(), x*v.gety() - y*v.getx() );
}

Vecteur3D Vecteur3D::operator~() const
{
    double n(this->norme());
    return Vecteur3D(x/n, y/n, z/n);
}





//--------définition des méthodes--------------------------------------------------------------------------------

double Vecteur3D::norme_carre() const
{
    return (*this) * (*this);   // utilisation du produit scalaire pour définir le carré de la norme.
}

double Vecteur3D::norme() const
{
    return sqrt((*this).norme_carre());   // utilisation du carré de la norme pour définir la norme
}

Vecteur3D Vecteur3D::rotation(Vecteur3D u, double const& angle) const
{
    Vecteur3D a(~u);
    return cos(angle)*(*this) + ((1 - cos(angle))*((*this) * a))*a + sin(angle)*(a^(*this));
}

double Vecteur3D::angle(Vecteur3D const& v) const
{
	int signe(0);
	if (prod_mixte(Vecteur3D(0,0,1), *this, v) >= 0)
	{
		signe = 1;
	}
	else
	{
		signe = -1;
	}
	
	cout << "	 interieur " << ((*this)*v)/v.norme()
	<< " 	acos " << acos(((*this)*v)/v.norme()) << endl;
	
	return signe*acos(((*this)*v)/v.norme());
}





//--------définition des fonctions-------------------------------------------------------------------------------

double prod_mixte(Vecteur3D a, Vecteur3D b, Vecteur3D c)
{
	return a*(b^c);
}





//--------définition des surcharges externes---------------------------------------------------------------------

Vecteur3D operator*(double const& a, Vecteur3D const& v)
{
    return Vecteur3D(a*v.getx(),a*v.gety(),a*v.getz());
}

Vecteur3D operator*(Vecteur3D const& v, double const& a)
{
    return Vecteur3D(a*v.getx(),a*v.gety(),a*v.getz());
}

ostream& operator<<(ostream& out, Vecteur3D const& v)
{
    out << "(" << v.getx() << ", " << v.gety() << ", " << v.getz() << ")";

    return out;
}


