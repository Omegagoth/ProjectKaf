#include "Particule.h"
#include <iostream>
#include <cmath>


using namespace std;



//--------définition des méthodes get----------------------------------------------------------------------------

Vecteur3D Particule::getposition() const
{
    return position;
}

Vecteur3D Particule::getvitesse() const
{
    return vitesse;
}

double Particule::getmasse() const
{
    return masse;
}

double Particule::getcharge() const
{
    return charge;
}

double Particule::getenergie() const
{
    return masse/sqrt(1 - vitesse*vitesse/(C*C));
}

double Particule::getgamma() const
{
    return 1/sqrt(1-vitesse*vitesse/(C*C));
}

Vecteur3D Particule::getforce() const
{
    return force;
}

Element* Particule::getappartient() const
{
	return appartient;
}




//--------définition des méthodes set----------------------------------------------------------------------------

void Particule::setposition(Vecteur3D const& x)
{
    position.setx(x.getx());
    position.sety(x.gety());
    position.setz(x.getz());
}

void Particule::setvitesse(Vecteur3D const& v)
{
    vitesse.setx(v.getx());
    vitesse.sety(v.gety());
    vitesse.setz(v.getz());
}

void Particule::setmasse(double const& m)
{
    masse = m;
}

void Particule::setcharge(double const& c)
{
    charge = c;
}

void Particule::setappartient(Element& e)
{
	appartient = &e;
}




//--------définition des constructeurs/destructeur---------------------------------------------------------------

Particule::Particule()
: masse(0), charge(0), appartient(0)
{}

Particule::Particule(Vecteur3D x, Vecteur3D p, double m, double c)
: position(x), masse(m), charge(c), appartient(0)
{
    double n(p.norme_carre());
    double a(sqrt( (m*m + n/(C*C)) ));
    vitesse.setx(p.getx()/a);
    vitesse.sety(p.gety()/a);
    vitesse.setz(p.getz()/a);
}

Particule::Particule(Vecteur3D x, double e, Vecteur3D d, double m, double c)
: position(x), masse(m), charge(c), appartient(0)
{
    Vecteur3D v(~d);

    double n(C*sqrt(1-m*m/(e*e)));
    vitesse = n*v;
}

Particule::Particule(Particule const& p)
: position(p.getposition()), vitesse(p.getvitesse()), masse(p.getmasse()), charge(p.getcharge()), appartient(p.getappartient())
{}

Particule::~Particule()
{}




//--------définition des méthodes--------------------------------------------------------------------------------

Particule& Particule::ajoute_forcemagn(Vecteur3D const& B, double dt)
{
    if (dt != 0)
    {
        if (B != Vecteur3D(0,0,0))
		{
		    double e(1.60217653e-19);
			Vecteur3D f(charge*vitesse^B);
			force += f.rotation(vitesse^f, asin(dt*f.norme()*C*C / (2 * masse *e * 1e9 * getgamma() * vitesse.norme()) ) );
		}
    }
	return (*this);
}

Particule& Particule::ajoute_forceinter(Particule const& p)
{
	Vecteur3D r(getposition()-p.getposition());
	force += ((pow(p.getcharge(), 2) * pow(p.getgamma(), -2)) / ( 4 * M_PI * 8.85e-12 * pow(r.norme(), 3))) * r;
	
	return (*this);
}

Particule& Particule::bouger(double dt)
{
    if(dt != 0)
    {
        double e(1.60217653e-19);
        vitesse += (dt*C*C/(getgamma()*e*masse*1e9))*force;
        position += dt*vitesse;
        force.setx(0);
        force.sety(0);
        force.setz(0);
    }
	return (*this);
}





//--------définition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Particule const& p)
{
    out << "Position : " << p.getposition() << endl
    << "Vitesse : " << p.getvitesse() << endl
    << "Energie (GeV): " << p.getenergie() << endl
    << "Masse (GeV/c^2) : " << p.getmasse() << endl
    << "Charge : " << p.getcharge() << endl
    << "Gamma : " << p.getgamma() << endl
    << "Somme des forces : " << p.getforce() << endl;

    return out;
}


