#include "Droit.h"

//d�finition des constructeurs
Droit::Droit()
: Element()
{

}

Droit::Droit(Vecteur3D e, Vecteur3D s, double r)
: Element(e,s,r)
{

}

//---------------------------------------------------------------------------------------------------------------

//d�finition des m�thodes
bool Droit::touche_bord(Particule const& p) const
{
    Vecteur3D d((*this).getdirection());
    Vecteur3D X((*this).getpos_relative(p));

    return (X-(X*d)*d).norme_carre() > rayon;
}

//---------------------------------------------------------------------------------------------------------------

Vecteur3D Droit::getpos_relative(Particule const& p) const
{
    return p.getposition() - entree;
}

//---------------------------------------------------------------------------------------------------------------

//d�finition des surcharges externes
ostream& operator<<(ostream& out, Droit const& d)
{
    out << "Entr�e : " << d.getentree() << endl
    << "Sortie : " << d.getsortie() << endl
    << "Section : " << d.getrayon() << endl;
}
