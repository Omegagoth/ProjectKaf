#include "Fodo.h"



//--------définition des méthodes get----------------------------------------------------------------------------

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
    if (i > maille.size() && maille.size() != 0)
    {
        cerr << "Erreur getmaille : le " << i << "eme terme n'existe pas" << endl;
        return maille[maille.size()-1];
    }
    else if(maille.size() == 0)
    {
        cerr << "Erreur getmaille : la maille est vide" << endl;
        return 0;
    }
    else
    {
        return maille[i-1];
    }
}

double Fodo::getlongueur_quadrupole() const
{
    return getlongueur()/2 - longueur_droit;
}

Vecteur3D Fodo::getchamps_magnetique(Particule const& p) const
{
    Vecteur3D m;

    for (int i(0); i<maille.size(); ++i)
    {
        if (!(maille[i]->heurte_bord(p)) && !(maille[i]->passe_suivant(p)))
        {
            return maille[i]->getchamps_magnetique(p);
        }
    }
    return Vecteur3D(0,0,0);
}




//--------définition des méthodes set----------------------------------------------------------------------------

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




//--------définition des constructeurs/destructeurs--------------------------------------------------------------

Fodo::Fodo()
: longueur_droit(0), intensite(0)
{
    maille.push_back(0);
}

Fodo::Fodo(Vecteur3D e, Vecteur3D s, double r, double l, double i)
: Droit(e,s,r), longueur_droit(l), intensite(i)
{
    Vecteur3D a(re + getlongueur_quadrupole()*getdirection());
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
: Droit(f), longueur_droit(f.getlongueur_droit()), intensite(f.getintensite())
{
    for (int unsigned i(0); i < taille; ++i)
    {
        maille.push_back(f.getmaille(i+1)->copie());
    }
}

Fodo::~Fodo()
{
    for (int unsigned i(0); i < maille.size(); ++i)
    {
        delete maille[i];
    }
}




//--------définition des méthodes--------------------------------------------------------------------------------

bool Fodo::heurte_bord(Particule const& p) const
{
    return (*maille[0]).heurte_bord(p) && (*maille[1]).heurte_bord(p) && (*maille[2]).heurte_bord(p) && (*maille[3]).heurte_bord(p);
}

Fodo* Fodo::copie() const
{
    return new Fodo(*this);
}

void Fodo::affiche(ostream& out) const
{
    out << "    Maille Fodo :" << endl
    << "Entrée : " << getre() << endl
    << "Sortie : " << getrs() << endl
    << "Rayon : " << getRe() << endl
    << "Longueur des sections droites : " << getlongueur_droit() << endl
    << "Longueur des quadrupôles : " << getlongueur_quadrupole() << endl
    << "Intensité : " << getintensite() << endl;
}




//--------définition des surcharges d'opérateurs------------------------------------------------------------------

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




//--------définition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Fodo& f)
{
    f.affiche(out);
    return out;
}

