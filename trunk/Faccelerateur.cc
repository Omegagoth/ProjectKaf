#include "Faccelerateur.h"



//--------dÈfinition des mÈthodes get----------------------------------------------------------------------------

vector<Faisceau*> Faccelerateur::getfaisceaux() const
{
    return faisceaux;
}

Faisceau* Faccelerateur::getfaisceaux(unsigned int i) const
{
	if (i > faisceaux.size())
	{
		cerr << "erreur getfaisceaux(int)" << endl;                  //ERREUR A GERER//
		return 0;
	}
    return faisceaux[i-1];
}

vector<Element*> Faccelerateur::getelements() const
{
    return elements;
}

Element* Faccelerateur::getelements(unsigned int i) const
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

double Faccelerateur::getperimetre() const
{
	double p(0);
	for (int unsigned i(0); i < elements.size(); ++i)
	{
		p += elements[i]->getlongueur();
	}
	return p;
}



//--------dÈfinition des constructeurs---------------------------------------------------------------------------

Faccelerateur::Faccelerateur()
{}

Faccelerateur::~Faccelerateur()
{
    faisceaux.clear();
    elements.clear();
}




//--------dÈfinition des mÈthodes--------------------------------------------------------------------------------

Faccelerateur& Faccelerateur::ajoute_faisceau(double n, Particule3D const& reference, double lambda)
{
    faisceaux.push_back(new Faisceau(reference, lambda));
    double c(0);
    int unsigned j(1);
    
    for (int unsigned i(0); i < elements.size() && j <= n; ++i)
    {
		while(elements[i]->getlongueur() + c > j*(getperimetre()/n) && j < n)
		{
			Particule3D p(elements[i]->pos_ideale(j*(getperimetre()/n)-c), lambda*reference.getenergie(), elements[i]->dir_ideale(j*(getperimetre()/n)-c), lambda*reference.getmasse(), lambda*reference.getcharge());
			faisceaux[faisceaux.size()-1]->ajoute_Vpart(p);
			++j;
		}
		
		c += elements[i]->getlongueur();
	}
	  
    return (*this);
}

Faccelerateur& Faccelerateur::ajoute_element(Element const& e)
{
    elements.push_back(e.copie());
	if (elements.size() != 1 && e.getre() == elements[elements.size()-2]->getrs())
	{
		elements[elements.size()-2]->setElement_suivant(*elements[elements.size()-1]);
		elements[elements.size()-1]->setElement_suivant(*elements[0]);
	}
	
    return (*this);
}

Faccelerateur& Faccelerateur::clear_faisceaux()
{
    for (int unsigned i(0); i<faisceaux.size(); ++i)
    {
        delete faisceaux[i];
    }
    faisceaux.clear();
    return (*this);
}


Faccelerateur& Faccelerateur::clear_faisceaux(int unsigned i)
{
	faisceaux[i] = faisceaux[faisceaux.size()-1];
	faisceaux.pop_back();
	return (*this);
}


Faccelerateur& Faccelerateur::clear_elements()
{
    for (int unsigned i(0); i<elements.size(); ++i)
    {
        delete elements[i];
    }
    elements.clear();
    return (*this);
}


Faccelerateur& Faccelerateur::affecte_element()
{
	for (int unsigned k(0); k < faisceaux.size(); ++k) 
	{
	
		for (int i(faisceaux[k]->getVpart().size()-1); i >= 0; --i)
		{
			for (int unsigned j(0); j < elements.size() && faisceaux[k]->getVpart()[i]->getappartient() == 0; ++j)
			{
				if (!(elements[j]->heurte_bord(*(faisceaux[k]->getVpart()[i]))) && !(elements[j]->passe_suivant(*(faisceaux[k]->getVpart()[i]))))
				{
					faisceaux[k]->getVpart()[i]->setappartient(*elements[j]);
				}
			}
			
			if (faisceaux[k]->getVpart()[i]->getappartient() == 0)
			{
				faisceaux[k]->clear_Vpart(i);
				cout << "Une particule a ete supprimer" << endl;
			}
		}
	}
	return (*this);
}


Faccelerateur& Faccelerateur::evolue(double dt)
{
	for (int unsigned i(0); i < faisceaux.size(); ++i)
	{
		faisceaux[i]->ajoute_forcemagn(dt);
		
		faisceaux[i]->ajoute_forceinter();
		
		faisceaux[i]->bouger(dt);
		
		for (int unsigned j(0); j < faisceaux[i]->getVpart().size(); ++j) 
		{
			if (faisceaux[i]->getVpart()[j]->getappartient()->passe_suivant(*faisceaux[i]->getVpart()[j]))
			{
				faisceaux[i]->getVpart()[j]->setappartient(*(faisceaux[i]->getVpart()[j]->getappartient()->getElement_suivant()));
			}
		
			if (faisceaux[i]->getVpart()[j]->getappartient()->heurte_bord(*faisceaux[i]->getVpart()[j]))
			{
				faisceaux[i]->clear_Vpart(i);
			}
		}
	}
	return (*this);
}



//--------dÈfinition des constructeurs/surcharges privÈe---------------------------------------------------------

Faccelerateur::Faccelerateur(Faccelerateur const& a)
{}

Faccelerateur& Faccelerateur::operator=(Faccelerateur const& a)
{}




//--------dÈfinition des surcharges externes---------------------------------------------------------------------

ostream& operator<<(ostream& out, Faccelerateur const& a)
{
    if((a.getelements()).size() != 1)
    {
        out << "L'accÈlÈrateur est constituer des " << (a.getelements()).size() << " ÈlÈments suivants :" << endl << endl;
		
        for (int unsigned i(0); i<(a.getelements()).size(); ++i)
        {
            out << *a.getelements(i+1) << endl;
        }
    }
    else
    {
        out << "L'accÈlÈrateur est composÈe de l'ÈlÈment suivant :" << endl << endl
        << *a.getelements(1) << endl;
    }
	
    out << endl;
	
    if((a.getfaisceaux()).size() != 1)
    {
        out << "L'accÈlÈrateur contient les " << (a.getfaisceaux()).size() << " faisceaux suivants :" << endl << endl;
		
        for (int unsigned i(0); i<(a.getfaisceaux()).size(); ++i)
        {
            out << *a.getfaisceaux()[i] << endl;
        }
    }
    else
    {
        out << "L'accÈlÈrateur contient le faisceau suivant :" << endl << endl
        << *a.getfaisceaux()[0] << endl;
    }
	
    out << endl;
	
    return out;
}

