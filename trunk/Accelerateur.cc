#include "Accelerateur.h"

using namespace std;

//definition des fonctions get
vector<Particule> Accelerateur::getparticules() const
{
    return particules;
}

Particule Accelerateur::getparticule(unsigned int i) const
{
    return particules[i-1];
}

vector<Element> Accelerateur::getelements() const
{
    return elements;
}

Element Accelerateur::getelement(unsigned int i) const
{
    return elements[i-1];
}

//---------------------------------------------------------------------------------------------------------------

//d�finition des constructeurs
Accelerateur::Accelerateur()
:particules(), elements()
{

}

//---------------------------------------------------------------------------------------------------------------

//d�finition des m�thodes
void Accelerateur::ajoute_particule(Particule const& p)
{
    particules.push_back(p);
    //return (*this);
}

void Accelerateur::ajoute_element(Element const& e)
{
    elements.push_back(e);
    //return (*this);
}

Accelerateur& Accelerateur::clear_particules()
{
    particules.clear();
    return (*this);
}

Accelerateur& Accelerateur::clear_elements()
{
    elements.clear();
    return (*this);
}

//---------------------------------------------------------------------------------------------------------------

//d�finition des constructeurs/surcharges priv�e
Accelerateur::Accelerateur(Accelerateur const& a)
{

}

Accelerateur& Accelerateur::operator=(Accelerateur const& a)
{

}

//---------------------------------------------------------------------------------------------------------------

//definition des surcharges externes
ostream& operator<<(ostream& out, Accelerateur const& a)
{
    if((a.getelements()).size() != 1)
    {
        out << "L'acc�l�rateur est constituer des " << (a.getelements()).size() << " �l�ments suivants :" << endl;

        for (int i(0); i<(a.getelements()).size(); ++i)
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

        for (int i(0); i<(a.getparticules()).size(); ++i)
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
