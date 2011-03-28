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
	return prod_mixte(e3, p.getposition(), rs) > 0;
}

//--------donne les valeurs aux static-----------------------------------------------------------------------------

Vecteur3D Element::E1(1,0,0);
Vecteur3D Element::E2(0,1,0);
Vecteur3D Element::E3(0,0,1);

//--------d�finition des m�thodes priv�e-------------------------------------------------------------------------------------------------------

Vecteur3D Element::getdirection() const		// methode qui renvoie la direction.
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


//------------Droit--------------------------------------------------------------------------------------------

//------------Droit-----constructeurs/destructeurs-------------------------------------------------------------



Droit::Droit()
:Element() {}


Droit::Droit(Vecteur3D v1, Vecteur3D v2, double d)
:Element(v1, v2, d)  {}


Droit::Droit(const Droit& d)
:Element(d)   {}

Droit::~Droit()
{}



//------------Droit-----public-------------------------------------------------------------



bool Droit::heurte_bord(Particule const& p)
{
	Vecteur3D d((*this).getdirection());
    Vecteur3D X((*this).getpos_relative(p));

    return (X-(X*d)*d).norme_carre() > Re;
}


double Droit::getlongueur() const
{return (rs - re).norme();}


//----------Courbe----------------------------------------------------------------------------------------------

//----------Courbe------Constructeurs/destructeurs--------------------------------------------------------------



Courbe::Courbe()
:Element(), centre_courbure(), courbure(0)  {}


Courbe::Courbe(Vecteur3D v1, Vecteur3D v2, double d1, double d2)
:Element(v1, v2, d1), courbure(d2)  {}


Courbe::Courbe(const Courbe& c)
:Element(c), courbure(c.getcourbure())  {}


Courbe::~Courbe()
{}




//----------Courbe------get----------------------------------------------------------------



Vecteur3D Courbe::getcentre_courbure() const
{return 1./2*(re + rs) + 1/courbure *sqrt(1 - courbure*courbure*(rs - re).norme_carre()/4)*((*this).getdirection()^e3);}


double Courbe::getcourbure() const
{return courbure;}



//----------Courbe-------set-------------------------------------------------------------


void Courbe::setcourbure(double const& d)
{courbure = d;}



//-----------Courbe------public-------------------------------------------------------------



bool Courbe::heurte_bord(Particule const& p)
{
	Vecteur3D X (p.getposition() - (*this).getcentre_courbure());
	return (X - 1/abs(courbure)*(~(X-X.getx()*e3))).norme_carre() > Re;
}


