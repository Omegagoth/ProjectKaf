#include <iostream>
#include "Faisceau.h"
#include <cmath>

using namespace std;

Faisceau::Faisceau(Particule r, double l)
: reference(r), lambda(l) {}

Faisceau::Faisceau(Faisceau const& f)
: reference(f.getreference()), lambda(f.getlambda()), Vpart(f.getVpart()) {}

Faisceau::Faisceau()
: reference(), lambda(0) {}

Faisceau::~Faisceau() {}



void Faisceau::setreference(Particule const& p)
{reference = p;}

void Faisceau::setlambda(double d)
{lambda = d;}

Particule Faisceau::getreference() const
{return reference;}

double Faisceau::getnb_particule() const
{return Vpart.size();}

double Faisceau::getlambda() const
{return lambda;}

vector<Particule*> Faisceau::getVpart() const
{return Vpart;}


Faisceau& Faisceau::ajoute_Vpart(Particule const& p)
{
	Vpart.push_back(new Particule(p));
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

double Faisceau::getenergie_moy() const
{
	double s(0);
	for (int unsigned i(0); i < Vpart.size(); ++i) 
		{
			s = s + Vpart[i]->getenergie();
		}
	return s/Vpart.size();
}

double Faisceau::getemittancevert() const
{
	return ((*this).getposition2vert_moy()) * ((*this).getvitesse2vert_moy()) - pow((*this).getpositionvitessevert_moy(), 2);
}

//double Faisceau::getemittancehori() const
//{
	
//}

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


