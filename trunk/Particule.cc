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

//--------définition des constructeurs---------------------------------------------------------------------------

Particule::Particule()
: position(), vitesse(), masse(0), charge(0),force()
{

}

Particule::Particule(Vecteur3D x, Vecteur3D p, double m, double c)
: position(x), vitesse (), masse(m), charge(c), force()
{
    double n(p.norme_carre());
    double a(sqrt( (m*m + n/(C*C)) ));
    vitesse.setx(p.getx()/a);
    vitesse.sety(p.gety()/a);
    vitesse.setz(p.getz()/a);
}

Particule::Particule(Vecteur3D x, double e, Vecteur3D d, double m, double c)
: position(x), vitesse(), masse(m), charge(c), force()
{
    Vecteur3D v(~d);

    double n(C*sqrt(1-m*m/(e*e)));
    vitesse = n*v;
}

//--------définition des méthodes--------------------------------------------------------------------------------

void Particule::ajoute_forcemagn(Vecteur3D const& B, double dt)
{
    if (dt != 0)
    {
        double e(1.60217653e-19);
        Vecteur3D f(charge*vitesse^B);
        force += f.rotation(vitesse^f, asin(dt*f.norme()*C*C / (2 * masse *e * 1e9 * getgamma() * vitesse.norme()) ) );
    }
}

void Particule::bouger(double dt)
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
}

//--------définition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Particule p)
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


