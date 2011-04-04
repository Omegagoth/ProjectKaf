#include "Accelerateur.h"

using namespace std;



//--------d�finition des m�thodes get----------------------------------------------------------------------------

vector<Particule*> Accelerateur::getparticules() const
{
    return particules;
}

Particule* Accelerateur::getparticules(unsigned int i) const
{
    return particules[i-1];
}

vector<Element*> Accelerateur::getelements() const
{
    return elements;
}

Element* Accelerateur::getelements(unsigned int i) const
{
    return elements[i-1];
}




//--------d�finition des constructeurs---------------------------------------------------------------------------

Accelerateur::Accelerateur()
{

}

Accelerateur::~Accelerateur()
{
    particules.clear();
    elements.clear();
}




//--------d�finition des m�thodes--------------------------------------------------------------------------------

Accelerateur& Accelerateur::ajoute_particule(Particule const& p)
{
    particules.push_back(new Particule(p));
    return (*this);
}

Accelerateur& Accelerateur::ajoute_element(Element const& e)
{
    elements.push_back(e.copie());
    return (*this);
}

Accelerateur& Accelerateur::clear_particules()
{
    for (int unsigned i(0); i<particules.size(); ++i)
    {
        delete particules[i];
    }
    particules.clear();
    return (*this);
}

Accelerateur& Accelerateur::clear_elements()
{
    for (int unsigned i(0); i<elements.size(); ++i)
    {
        delete elements[i];
    }
    elements.clear();
    return (*this);
}




//--------d�finition des constructeurs/surcharges priv�e---------------------------------------------------------

Accelerateur::Accelerateur(Accelerateur const& a)
{

}

Accelerateur& Accelerateur::operator=(Accelerateur const& a)
{

}




//--------d�finition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Accelerateur const& a)
{
    if((a.getelements()).size() != 1)
    {
        out << "L'acc�l�rateur est constituer des " << (a.getelements()).size() << " �l�ments suivants :" << endl << endl;

        for (int unsigned i(0); i<(a.getelements()).size(); ++i)
        {
            out << *a.getelements(i+1) << endl;
        }
    }
    else
    {
        out << "L'acc�l�rateur est compos�e de l'�l�ment suivant :" << endl << endl
        << *a.getelements(1) << endl;
    }

    out << endl;

    if((a.getparticules()).size() != 1)
    {
        out << "L'acc�l�rateur contient les " << (a.getparticules()).size() << " particules suivantes :" << endl << endl;

        for (int unsigned i(0); i<(a.getparticules()).size(); ++i)
        {
            out << *a.getparticules(i+1) << endl;
        }
    }
    else
    {
        out << "L'acc�l�rateur contient la particule suivante :" << endl << endl
        << *a.getparticules(1) << endl;
    }

    out << endl;

    return out;
}
