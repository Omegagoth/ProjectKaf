#include "Fodo.h"

double Fodo::getlongueur_droit() const
{
    return longueur_droit;
}

double Fodo::getintensite() const
{
    return intensite;
}

void Fodo::setlongueur_droit(double l)
{
    longueur_droit = l;
}

void Fodo::setintensite(double i)
{
    intensite = i;
}

void Fodo::setElement_suivant(Element& e)
{
    Element_suivant = &e;
}


Fodo::Fodo()
: longueur_droit(0), intensite(0)
{

}

Fodo::Fodo(Vecteur3D e, Vecteur3D s, double r, double l, double i)
: Droit(e,s,r), longueur_droit(l), intensite(i)
{
    Vecteur3D a(re + getlongueur()*getdirection());
    maille[0] = new Quadrupole(e, a, r, i);
    maille[1] = new Section_droite(a, a + getlongueur_droit()*getdirection(), r);
    maille[2] = new Quadrupole(a + getlongueur_droit()*getdirection(), rs - getlongueur_droit()*getdirection(), r, -i);
    maille[3] = new Section_droite(rs - getlongueur_droit()*getdirection(), rs, r);

    (*maille[0]).setElement_suivant(*maille[1]);
    (*maille[1]).setElement_suivant(*maille[2]);
    (*maille[2]).setElement_suivant(*maille[3]);
}

Fodo::Fodo(Fodo const& f)
{

}

Fodo::~Fodo()
{
    delete maille[0];
    delete maille[1];
    delete maille[2];
    delete maille[3];
}

bool Fodo::heurte_bord(Particule const& p) const
{
    return (*maille[0]).heurte_bord(p) && (*maille[1]).heurte_bord(p) && (*maille[2]).heurte_bord(p) && (*maille[3]).heurte_bord(p);
}

double Fodo::getlongueur() const
{
    return (getdirection()).norme()/2 - longueur_droit;
}
