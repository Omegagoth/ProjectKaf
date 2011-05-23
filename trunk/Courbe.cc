#include "Courbe.h"



//--------définition des méthodes get----------------------------------------------------------------------------

double Courbe::getcourbure() const
{
    return courbure;
}

Vecteur3D Courbe::getcentre() const
{
    return 1./2*(re + rs) + 1./courbure *sqrt(1 - courbure*courbure*(rs - re).norme_carre()/4)*(getdirection()^E3);
}

double Courbe::getangle() const
{
	return (re-getcentre()).angle(rs-getcentre());
}




//--------définition des méthodes get----------------------------------------------------------------------------

void Courbe::setcourbure(double const& d)
{
    courbure = d;
}




//--------définition des constructeurs---------------------------------------------------------------------------

Courbe::Courbe()
: courbure(1)
{}

Courbe::Courbe(Vecteur3D e, Vecteur3D s, double r, double k)
: Element(e, s, r), courbure(k)
{
    if(1/(courbure*courbure) < (rs-re).norme_carre()/4)
    {
        courbure = courbure*2/((rs-re).norme()*abs(courbure));
    }
}

Courbe::Courbe(const Courbe& c)
:Element(c), courbure(c.getcourbure())
{}


Courbe::~Courbe()
{}




//--------définition des méthodes--------------------------------------------------------------------------------

bool Courbe::heurte_bord(Particule const& p) const
{
    Vecteur3D X(p.getposition() - getcentre());
    return (X - 1/abs(courbure)*(~(X - X.getz()*E3))).norme_carre() > Re*Re;
}

Vecteur3D Courbe::getu(Particule const& p) const
{
	return ~(getpos_relative(p) - (p.getposition().getz() * E3));
}



//--------définition des méthodes privées------------------------------------------------------------------------

Vecteur3D Courbe::getpos_relative(Particule const& p) const
{
    return p.getposition() - getcentre();
}




//--------définition des surcharges externes---------------------------------------------------------------------

ostream& operator<< (ostream& out, Courbe const& c)
{
    out << "Entrée : " << c.getre() << endl
    << "Sortie : " << c.getrs() << endl
    << "Section : " << c.getRe() << endl
    << "Rayon de courbure : " << 1/c.getcourbure() << endl
    << "Centre de courbure : " << c.getcentre() << endl;

    return out;
}

