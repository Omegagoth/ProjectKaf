#include <iostream>
#include <vector>
#include "Particule.h"

using namespace std;


class Faisceau
{
	
	protected :
	
	Particule reference;
	double lambda;
	vector<Particule*> Vpart;
	
	public :
	
	Faisceau(Particule, double);
	Faisceau(Faisceau const&);
	Faisceau();
	~Faisceau();
	
	void setreference(Particule const&);
	void setlambda(double);
	
	
	Particule getreference() const;
	double getnb_particule() const;
	double getlambda() const;
	vector<Particule*> getVpart() const;
	
	Faisceau& ajoute_Vpart(Particule const&);
	Faisceau& clear_Vpart();
	
	double getenergie_moy() const;
	
	double getemittancevert() const;
	
	//double getemittancehori() const;
	
	double getposition2vert_moy() const;
	
	double getvitesse2vert_moy() const;
	
	double getpositionvitessevert_moy() const;
	
	
	
};
