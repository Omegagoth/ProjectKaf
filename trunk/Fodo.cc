#include "Fodo.h"



//--------d�finition des m�thodes get----------------------------------------------------------------------------

double Fodo::getlongueur_droit() const
{
    return longueur_droit;
}

double Fodo::getintensite() const
{
    return intensite;
}

vector<Element*> Fodo::getmaille() const
{
    return maille;
}

Element* Fodo::getmaille(unsigned int i) const
{
    return maille[i];
}



//--------d�finition des m�thodes set----------------------------------------------------------------------------

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
    (*maille[taille-1]).setElement_suivant(e);
}



//--------d�finition des constructeurs/destructeurs--------------------------------------------------------------

Fodo::Fodo()
: longueur_droit(0), intensite(0)
{
    maille.push_back(0);
}

Fodo::Fodo(Vecteur3D e, Vecteur3D s, double r, double l, double i)
: Droit(e,s,r), longueur_droit(l), intensite(i)
{
    Vecteur3D a(re + getlongueur()*getdirection());
    maille.push_back(new Quadrupole(e, a, r, i));
    maille.push_back(new Section_droite(a, a + getlongueur_droit()*getdirection(), r));
    maille.push_back(new Quadrupole(a + getlongueur_droit()*getdirection(), rs - getlongueur_droit()*getdirection(), r, -i));
    maille.push_back(new Section_droite(rs - getlongueur_droit()*getdirection(), rs, r));

    for (int unsigned j(0); j < maille.size()-1; ++j)
    {
        (*maille[j]).setElement_suivant(*maille[j+1]);
    }
}

Fodo::Fodo(Fodo const& f)
{
    for (int unsigned i(0); i < taille; ++i)
    {
        maille[i] = (*f.getmaille(i)).copie();
    }
}

Fodo::~Fodo()
{
    for (int unsigned i(0); i < maille.size(); ++i)
    {
        delete maille[i];
    }
}




//--------d�finition des m�thodes--------------------------------------------------------------------------------

bool Fodo::heurte_bord(Particule const& p) const
{
    return (*maille[0]).heurte_bord(p) && (*maille[1]).heurte_bord(p) && (*maille[2]).heurte_bord(p) && (*maille[3]).heurte_bord(p);
}

void Fodo::affiche(ostream& out)
{
    out << "Entr�e : " << getre() << endl
    << "Sortie : " << getrs() << endl
    << "Rayon : " << getRe() << endl
    << "Longueur des sections droites : " << getlongueur_droit() << endl
    << "Longueur des quadrup�les : " << getlongueur() << endl
    << "Intensit� : " << getintensite() << endl;
}


//--------d�finition des surcharges d'op�rateurs------------------------------------------------------------------

Fodo& Fodo::operator=(Fodo const& f)
{
    re = f.getre();
    rs = f.getrs();
    Re = f.getRe();
    Element_suivant = f.getElement_suivant();
    longueur_droit = f.getlongueur_droit();
    intensite = f.getintensite();
    maille = f.getmaille();

    return (*this);
}



//--------donne les valeurs aux static----------------------------------------------------------------------------

unsigned int Fodo::taille(4);



//--------d�finition des m�thodes priv�e--------------------------------------------------------------------------

double Fodo::getlongueur() const
{
    return (getdirection()).norme()/2 - longueur_droit;
}


//--------d�finition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Fodo& f)
{
    f.affiche(out);
    return out;
}

