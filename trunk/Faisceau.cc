#include <iostream>
#include "Faisceau.h"
#include <cmath>

using namespace std;

Faisceau::Faisceau(Particule3D r, double l)
: reference(r), lambda(l) {}

Faisceau::Faisceau(Faisceau const& f)
: reference(f.getreference()), lambda(f.getlambda()), Vpart(f.getVpart()) {}
	//for (int unsigned i(0); i < Vpart.size(); ++i)
	//{Vpart.push_back(new Particule3D(*f.getVpart()[i]));}
	//reference = new Particule3D(f.getreference());


Faisceau::Faisceau()
: reference(), lambda(0) {}

Faisceau::~Faisceau() {clear_Vpart();}
//delete reference;}

//---------------------------------------------------------------

void Faisceau::setreference(Particule3D const& p)
{reference = p;}

void Faisceau::setlambda(double d)
{lambda = d;}

//---------------------------------------------------------------

Particule3D Faisceau::getreference() const
{return reference;}

double Faisceau::getnb_particule3D() const
{return lambda*Vpart.size();}

double Faisceau::getlambda() const
{return lambda;}

//---------------------------------------------------------------

vector<Particule3D*> Faisceau::getVpart() const
{return Vpart;}


Faisceau& Faisceau::ajoute_Vpart(Particule3D const& p)
{
	Vpart.push_back(new Particule3D(p));
	return (*this);
}

Faisceau& Faisceau::clear_Vpart()
{
	for (int unsigned i(0); i<Vpart.size(); ++i) 
	{
		delete Vpart[i];
	}
	Vpart.clear();
	return (*this);
}

Faisceau& Faisceau::clear_Vpart(int i)
{
	Vpart[i] = Vpart[Vpart.size()-1];
	Vpart.pop_back();
	return (*this);
	
}

//---------------------------------------------------------------


double Faisceau::getenergie_moy() const
{
	double s(0);
	for (int unsigned i(0); i < Vpart.size(); ++i) 
		{
			s = s + Vpart[i]->getenergie();
		}
	return s/Vpart.size();
}


//---------------------------------------------------------------


double Faisceau::getemittancevert() const
{
	return sqrt((getposition2vert_moy()) * (getvitesse2vert_moy()) - pow(getpositionvitessevert_moy(), 2));
}


double Faisceau::getemittancehori() const
{
	return sqrt((getposition2hori_moy()) * (getvitesse2hori_moy()) - pow(getpositionvitessehori_moy(), 2));
}


//---------------------------------------------------------------



Faisceau& Faisceau::bouger(double dt)
{
	for (int i(0); i < Vpart.size(); ++i) 
	{
		Vpart[i]->bouger(dt);
	}
	return (*this);
}


Faisceau& Faisceau::ajoute_forcemagn(double dt)
{
	for (int i(0); i < Vpart.size(); ++i) 
	{
		Vpart[i]->ajoute_forcemagn(Vpart[i]->getappartient()->getchamps_magnetique(*Vpart[i]), dt);
	}
	return (*this);
}


Faisceau& Faisceau::ajoute_forceinter()
{
	for (int unsigned i(0); i < Vpart.size(); ++i) 
	{
		for (int unsigned j(i+1); j < Vpart.size(); ++j) 
		{
			Vpart[j]->ajoute_forceinter(*Vpart[i]);
			Vpart[i]->ajoute_forceinter(*Vpart[j]);
		}
	}
	
	return (*this);
}


//---------------------------------------------------------------



double Faisceau::getA11vert() const
{
	return getvitesse2vert_moy()/getemittancevert();
}

double Faisceau::getA12vert() const
{
	return -(getpositionvitessevert_moy())/getemittancevert();
}

double Faisceau::getA22vert() const
{
	return getposition2vert_moy()/getemittancevert();
}

double Faisceau::getA11hori() const
{
	return getvitesse2hori_moy()/getemittancehori();
}

double Faisceau::getA12hori() const
{
	return -(getpositionvitessehori_moy())/getemittancehori();
}

double Faisceau::getA22hori() const
{
	return getposition2hori_moy()/getemittancehori();
}

double Faisceau::getbunch_longueur() const
{return 0;}

Faisceau& Faisceau::creation(double)
{return (*this);}

//---------------------------------------------------------------


double Faisceau::getposition2vert_moy() const
{
	double m(0);
	
	for (int i(0); i < Vpart.size(); ++i) 
	{
		m = m + pow(Vpart[i]->getposition().getz(), 2);
	}
	
	return m/Vpart.size();
}


double Faisceau::getvitesse2vert_moy() const
{
	double m(0);
	
	for (int i(0); i < Vpart.size(); ++i) 
	{
		m = m + pow(Vpart[i]->getvitesse().getz(), 2);
	}
	
	return m/Vpart.size();
}

double Faisceau::getpositionvitessevert_moy() const
{
	double m(0);
	
	for (int i(0); i < Vpart.size(); ++i) 
	{
		m = m + (Vpart[i]->getposition().getz())*(Vpart[i]->getvitesse().getz());
	}
	
	return m/Vpart.size();
}

double Faisceau::getposition2hori_moy() const

{
	double m(0);
	
	
		for (int i(0); i < Vpart.size(); ++i) 
		{
			m = m + pow( (Vpart[i]->getposition())*(Vpart[i]->getappartient()->getu(*Vpart[i])), 2);
		}
	
	return m/Vpart.size();
}


double Faisceau::getvitesse2hori_moy() const
{
	double m(0);
	
	
	for (int i(0); i < Vpart.size(); ++i) 
	{
		m = m + pow( (Vpart[i]->getvitesse())*(Vpart[i]->getappartient()->getu(*Vpart[i])), 2);
	}
	
	return m/Vpart.size();
	
}

double Faisceau::getpositionvitessehori_moy() const
{
	double m(0);
	
	
	for (int i(0); i < Vpart.size(); ++i) 
	{
		m = m + (((Vpart[i]->getposition())*(Vpart[i]->getappartient()->getu(*Vpart[i]))) * ((Vpart[i]->getvitesse())*(Vpart[i]->getappartient()->getu(*Vpart[i]))));
	}
	
	return m/Vpart.size();
	
}


ostream& operator<<(ostream& out, Faisceau const& f)
{
	if((f.getVpart()).size() != 1)
    {
        out << "Le faisceau contient les " << (f.getVpart()).size() << " particules suivantes :" << endl << endl;
		
        for (int unsigned i(0); i<(f.getVpart()).size(); ++i)
        {
            out << *f.getVpart()[i] << endl;
        }
    }
    else if((f.getVpart()).size() == 1)
    {
        out << "Le Faisceau contient la particule suivante :" << endl << endl
        << *f.getVpart()[0] << endl;
    }
	
	else {
		out << "erreur, faisceau vide" << endl;									//Erreur a gérer//
	}

    out << endl;
	
    return out;
	
}
