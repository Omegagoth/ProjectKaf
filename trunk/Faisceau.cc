#include <iostream>
#include "Faiscau.h"
#include <cmath>

using namespace std;

Faisceau::Faisceau(Particule r, double n, double l)
: reference(r), nb_particule(n), lambda(l) {}

Faisceau::Faisceau(Faisceau const& f)
: reference(f.getreference()), nb_particule(f.getnb_particule()), lamda(f.lambda()) {}

Faisceau::Faisceau()
: reference(), nb_particule(0), lambda(0) {}

Faisceau::~Faisceau() {}



void Faisceau::setreference(Particule const& p)
{reference = p;}

void Faisceau::setnb_particule(double d)
{nb_particule = d;}

void Faisceau::setlambda(double d)
{lambda = d;}

Particule Faisceau::getreference() const
{return reference;}

double Faisceau::getnb_particule() const
{return nb_particule;}

double Faisceau::getlambda() const
{return lambda;}

vector<Particule> Faisceau::getVpart() const
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
	return s;
}

double Faisceau::getemittance() const
{
	
}



