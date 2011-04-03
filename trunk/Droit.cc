#include "Droit.h"

//--------prototypage des méthodes get---------------------------------------------------------------------------

double Droit::getlongueur() const
{
    return (rs - re).norme();
}

//--------définition des constructeurs---------------------------------------------------------------------------

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

//--------définition des méthodes--------------------------------------------------------------------------------

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

//--------définition des méthodes privées------------------------------------------------------------------------

Vecteur3D Droit::getpos_relative(Particule const& p) const
{
    return p.getposition() - re;
}

//--------définition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Droit const& d)
{
    out << "Entrée : " << d.getre() << endl
    << "Sortie : " << d.getrs() << endl
    << "Section : " << d.getRe() << endl;

    return out;
}
