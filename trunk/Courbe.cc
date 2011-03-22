#include "Courbe.h"

//définition des méthodes get
double Courbe::getcourbure() const
{
    return courbure;
}

Vecteur3D Courbe::getcentre() const
{
    return 1./2*(entree + sortie) + 1/courbure *sqrt(1 - courbure*courbure*(sortie - entree).norme_carre()/4)*((*this).getdirection()^E3);
}

//---------------------------------------------------------------------------------------------------------------

//définition des constructeurs
Courbe::Courbe()
: Element(), courbure(1)
{

}

Courbe::Courbe(Vecteur3D e, Vecteur3D s, double r, double k)
: Element(e, s, r), courbure(k)
{

}

//---------------------------------------------------------------------------------------------------------------

//définition des méthodes
bool Courbe::touche_bord(Particule const& p) const
{
    Vecteur3D X(p.getposition() - (*this).getcentre());
    return (X - 1/abs(courbure)*(~(X - X.getx()*E3))).norme_carre() > rayon;
}

//---------------------------------------------------------------------------------------------------------------

//définition des méthodes privées
Vecteur3D Courbe::getpos_relative(Particule const& p) const
{
    return p.getposition() - (*this).getcentre();
}

//---------------------------------------------------------------------------------------------------------------

//définition des surcharges externes
ostream& operator<< (ostream& out, Courbe const& c)
{
    out << "Entrée : " << c.getentree() << endl
    << "Sortie : " << c.getsortie() << endl
    << "Section : " << c.getrayon() << endl
    << "Rayon de courbure : " << 1/c.getcourbure() << endl
    << "Centre de courbure : " << c.getcentre() << endl;

    return out;
}
