#include "Accelerateur.h"

using namespace std;



//--------définition des méthodes get----------------------------------------------------------------------------

vector<Particule*> Accelerateur::getparticules() const
{
    return particules;
}

Particule* Accelerateur::getparticules(unsigned int i) const
{
	if (i > particules.size())
	{
		cerr << "erreur getparticules(int)" << endl;                  //ERREUR A GERER//
		return 0;
	}
    return particules[i-1];
}

vector<Element*> Accelerateur::getelements() const
{
    return elements;
}

Element* Accelerateur::getelements(unsigned int i) const
{
	if (i > elements.size())
	{
		cerr << "erreur getelements(int)" << endl;                  //ERREUR A GERER//
		return elements[elements.size()-1];
	}
	else
	{
        return elements[i-1];
	}
}




//--------définition des constructeurs---------------------------------------------------------------------------

Accelerateur::Accelerateur()
{}

Accelerateur::~Accelerateur()
{
    particules.clear();
    elements.clear();
}




//--------définition des méthodes--------------------------------------------------------------------------------

Accelerateur& Accelerateur::ajoute_particule(Particule const& p)
{
    particules.push_back(new Particule(p));
    return (*this);
}

Accelerateur& Accelerateur::ajoute_element(Element const& e)
{
    elements.push_back(e.copie());
	if (elements.size() != 1 && e.getre() == elements[elements.size()-2]->getrs())
	{
		elements[elements.size()-2]->setElement_suivant(*elements[elements.size()-1]);
		elements[elements.size()-1]->setElement_suivant(*elements[0]);
	}

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


Accelerateur& Accelerateur::clear_particules(int unsigned i)
{
	particules[i] = particules[particules.size()-1];
	particules.pop_back();
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


Accelerateur& Accelerateur::affecte_element()
{
	for (int i(particules.size()-1); i >= 0; --i)
	{
		for (int unsigned j(0); j < elements.size() && particules[i]->getappartient() == 0; ++j)
		{
			if (!(elements[j]->heurte_bord(*particules[i])) && !(elements[j]->passe_suivant(*particules[i])))
			{
				particules[i]->setappartient(*elements[j]);
			}
		}
		if (particules[i]->getappartient() == 0)
		{
			clear_particules(i);
			cout << "Une particule a ete supprimer" << endl;
		}
	}
	return (*this);
}


Accelerateur& Accelerateur::evolue(double dt)
{
	for (int unsigned i(0); i < particules.size(); ++i)
	{
		particules[i]->ajoute_forcemagn(particules[i]->getappartient()->getchamps_magnetique(*particules[i]), dt);
		particules[i]->bouger(dt);

		if (particules[i]->getappartient()->passe_suivant(*particules[i]))
		{
			particules[i]->setappartient(*(particules[i]->getappartient()->getElement_suivant()));
		}

		if (particules[i]->getappartient()->heurte_bord(*particules[i]))
		{
			clear_particules(i);
		}
	}
	return (*this);
}




//--------définition des constructeurs/surcharges privée---------------------------------------------------------

Accelerateur::Accelerateur(Accelerateur const& a)
{}

Accelerateur& Accelerateur::operator=(Accelerateur const& a)
{}




//--------définition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Accelerateur const& a)
{
    if((a.getelements()).size() != 1)
    {
        out << "L'accélérateur est constituer des " << (a.getelements()).size() << " éléments suivants :" << endl << endl;

        for (int unsigned i(0); i<(a.getelements()).size(); ++i)
        {
            out << *a.getelements(i+1) << endl;
        }
    }
    else
    {
        out << "L'accélérateur est composée de l'élément suivant :" << endl << endl
        << *a.getelements(1) << endl;
    }

    out << endl;

    if((a.getparticules()).size() != 1)
    {
        out << "L'accélérateur contient les " << (a.getparticules()).size() << " particules suivantes :" << endl << endl;

        for (int unsigned i(0); i<(a.getparticules()).size(); ++i)
        {
            out << *a.getparticules(i+1) << endl;
        }
    }
    else
    {
        out << "L'accélérateur contient la particule suivante :" << endl << endl
        << *a.getparticules(1) << endl;
    }

    out << endl;

    return out;
}
