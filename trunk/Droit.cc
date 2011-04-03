#include "Droit.h"

//--------prototypage des m�thodes get---------------------------------------------------------------------------

double Droit::getlongueur() const
{
    return (rs - re).norme();
}

//--------d�finition des constructeurs---------------------------------------------------------------------------

Droit::Droit()
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

bool Droit::heurte_bord(Particule const& p) const
{
	Vecteur3D d(getdirection());
    Vecteur3D X(getpos_relative(p));

    return (X-(X*d)*d).norme_carre() > Re*Re;
}

Droit* Droit::copie() const
{
    return new Droit(*this);
}

//--------d�finition des m�thodes priv�es------------------------------------------------------------------------

Vecteur3D Droit::getpos_relative(Particule const& p) const
{
    return p.getposition() - re;
}

//--------d�finition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Droit const& d)
{
    out << "Entr�e : " << d.getre() << endl
    << "Sortie : " << d.getrs() << endl
    << "Section : " << d.getRe() << endl;

    return out;
}
