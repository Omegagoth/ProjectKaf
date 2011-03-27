#include "Element.h"
#include <iostream>

using namespace std;

//d�finition des m�thodes get
Vecteur3D Element::getentree() const
{
    return entree;
}

Vecteur3D Element::getsortie() const
{
    return sortie;
}

double Element::getrayon() const
{
    return rayon;
}

Element Element::getsuivant() const
{
    return *suivant;
}

//---------------------------------------------------------------------------------------------------------------

//d�finition des constructeurs
Element::Element()
:entree(), sortie(), rayon(0), suivant(0)
{

}

Element::Element(Vecteur3D e, Vecteur3D s, double r)
: entree(e), sortie(s), rayon(r), suivant(0)
{
    if (prod_mixte(E3, entree, sortie) > 0)
    {
        Vecteur3D a(entree);
        entree = sortie;
        sortie = a;
    }
}

//---------------------------------------------------------------------------------------------------------------

//d�finiton des surcharges d'op�rateurs
Element& Element::operator+=(Element& e)
{
    suivant = &e;
    return (*this);
}

//---------------------------------------------------------------------------------------------------------------

//d�finition des m�thodess
bool Element::passe_suivant(Particule const& p) const
{
    return (prod_mixte(E3, p.getposition(), sortie) > 0);
}

//---------------------------------------------------------------------------------------------------------------

//d�fintion des m�thodes priv�es
Vecteur3D Element::getdirection() const
{
    return ~(sortie - entree);
}

//---------------------------------------------------------------------------------------------------------------

//d�finition des surcharges externes
ostream& operator<<(ostream& out, Element const& e)
{
    out << "Entr�e : " << e.getentree() << endl
    << "Sortie : " << e.getsortie() << endl
    << "Section : " << e.getrayon() << endl;

    return out;
}
