#include "Accelerateur.h"

using namespace std;

//--------d�finition des m�thodes get----------------------------------------------------------------------------

vector<Particule*> Accelerateur::getparticules() const
{
    return particules;
}

Particule Accelerateur::getparticule(unsigned int i) const
{
    return *particules[i-1];
}

vector<Element*> Accelerateur::getelements() const
{
    return elements;
}

Element Accelerateur::getelement(unsigned int i) const
{
    return *elements[i-1];
}

//--------d�finition des constructeurs---------------------------------------------------------------------------

Accelerateur::Accelerateur()
:particules(), elements()
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
    elements.push_back(new Element(e));
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
        out << "L'acc�l�rateur est constituer des " << (a.getelements()).size() << " �l�ments suivants :" << endl;

        for (int unsigned i(0); i<(a.getelements()).size(); ++i)
        {
            out << a.getelement(i+1);
        }
    }
    else
    {
        out << "L'acc�l�rateur est compos�e de l'�l�ment suivant :" << endl
        << a.getelement(1);
    }

    if((a.getparticules()).size() != 1)
    {
        out << "L'acc�l�rateur contient les " << (a.getparticules()).size() << " particules suivantes :" << endl;

        for (int unsigned i(0); i<(a.getparticules()).size(); ++i)
        {
            out << a.getparticule(i+1);
        }
    }
    else
    {
        out << "L'acc�l�rateur contient la particule suivante :" << endl
        << a.getparticule(1);
    }

    return out;
}
