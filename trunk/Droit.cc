#include "Droit.h"

//--------définition des constructeurs---------------------------------------------------------------------------

Droit::Droit()
: Element()
{

}

Droit::Droit(Vecteur3D e, Vecteur3D s, double r)
: Element(e,s,r)
{

}

//--------définition des méthodes--------------------------------------------------------------------------------

bool Droit::touche_bord(Particule const& p) const
{
    Vecteur3D d(getdirection());
    Vecteur3D X(getpos_relative(p));

    return (X-(X*d)*d).norme_carre() > rayon;
}

//--------définition des méthodes privées------------------------------------------------------------------------

Vecteur3D Droit::getpos_relative(Particule const& p) const
{
    return p.getposition() - entree;
}

//--------définition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Droit const& d)
{
    out << "Entrée : " << d.getentree() << endl
    << "Sortie : " << d.getsortie() << endl
    << "Section : " << d.getrayon() << endl;

    return out;
}
