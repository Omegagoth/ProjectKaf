#include <iostream>
#include "Element.h"
#include <cmath>

using namespace std;

//--------d�finition des m�thodes get----------------------------------------------------------------------------

Vecteur3D Element::getre() const
{
    return re;
}


Vecteur3D Element::getrs() const
{
    return rs;
}


double Element::getRe() const
{
    return Re;
}


Element* Element::getElement_suivant() const
{
    return Element_suivant;
}


//--------d�finition des m�thodes set----------------------------------------------------------------------------

void Element::setre(Vecteur3D const& v)
{
    re.setx(v.getx());
	re.sety(v.gety());
	re.setz(v.getz());
}

void Element::setrs(Vecteur3D const& v)
{
    rs.setx(v.getx());
	rs.sety(v.gety());
	rs.setz(v.getz());
}

void Element::setRe(double const& d)
{
    Re = d;
}



void Element::setElement_suivant(Element& v)
{
    Element_suivant = &v;
}

//--------d�finition des constructeurs/destructeurs--------------------------------------------------------------

Element::Element()
: re(), rs(), Re(0), Element_suivant(0)
{

}

Element::Element(Vecteur3D e, Vecteur3D s, double R)
: re(e), rs(s), Re(R), Element_suivant(0)
{

}

Element::~Element()
{

}

//--------d�finition des m�thodes--------------------------------------------------------------------------------

bool Element::passe_suivant(Particule const& p)
{
	return prod_mixte(E3, p.getposition(), rs) > 0;
}

//--------donne les valeurs aux static-----------------------------------------------------------------------------

Vecteur3D Element::E1(1,0,0);
Vecteur3D Element::E2(0,1,0);
Vecteur3D Element::E3(0,0,1);

//--------d�finition des m�thodes priv�e-------------------------------------------------------------------------------------------------------

Vecteur3D Element::getdirection() const
{
    return ~(rs - re);
}

//--------d�finition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Element const& e)
{
    out << "Entr�e : " << e.getre() << endl
    << "Sortie : " << e.getrs() << endl
    << "Section : " << e.getRe() << endl;

    return out;
}

