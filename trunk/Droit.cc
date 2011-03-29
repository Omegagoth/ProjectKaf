#include "Droit.h"

//--------prototypage des m�thodes get---------------------------------------------------------------------------

double Droit::getlongueur() const
{
    return (rs - re).norme();
}

//--------d�finition des constructeurs---------------------------------------------------------------------------

Droit::Droit()
: Element()
{

}

Droit::Droit(Vecteur3D e, Vecteur3D s, double r)
: Element(e,s,r)
{

}

Droit::Droit(const Droit& d)
:Element(d)
{

}

Droit::~Droit()
{

}

//--------d�finition des m�thodes--------------------------------------------------------------------------------

bool Droit::heurte_bord(Particule const& p)
{
	Vecteur3D d(getdirection());
    Vecteur3D X(getpos_relative(p));

    return (X-(X*d)*d).norme_carre() > Re*Re;
}

//--------d�finition des m�thodes priv�es------------------------------------------------------------------------

Vecteur3D Droit::getpos_relative(Particule const& p) const
{
    return p.getposition() - entree;
}

//--------d�finition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Droit const& d)
{
    out << "Entr�e : " << d.getentree() << endl
    << "Sortie : " << d.getsortie() << endl
    << "Section : " << d.getrayon() << endl;

    return out;
}
