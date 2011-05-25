#include <iostream>
#include <vector>
#include "Particule3D.h"
#include "Element.h"

using namespace std;


class Faisceau
{
	
	protected :
	
	Particule3D reference;
	double lambda;
	vector<Particule3D*> Vpart;
	
	public :
	
	Faisceau(Particule3D, double);
	Faisceau(Faisceau const&);
	Faisceau();
	~Faisceau();
	
	//---------------------------------------------------------------
	
	void setreference(Particule3D const&);
	void setlambda(double);
	
	//---------------------------------------------------------------
	
	Particule3D getreference() const;
	double getnb_particule3D() const;
	double getlambda() const;
	vector<Particule3D*> getVpart() const;
	
	//---------------------------------------------------------------
	
	Faisceau& ajoute_Vpart(Particule3D const&);
	Faisceau& clear_Vpart();
	Faisceau& clear_Vpart(int i);

	
	//---------------------------------------------------------------
	
	double getenergie_moy() const;
	
	//---------------------------------------------------------------
	
	double getemittancevert() const;
	
	double getemittancehori() const;
	
	//---------------------------------------------------------------
	
	double getA11vert() const;
	
	double getA12vert() const;
	
	double getA22vert() const;
	
	double getA11hori() const;
	
	double getA12hori() const;
	
	double getA22hori() const;
	
	
	
	//---------------------------------------------------------------
	
	Faisceau& bouger(double);
	
	Faisceau& ajoute_forcemagn(double);
	
	Faisceau& ajoute_forceinter();
	
	
	//---------------------------------------------------------------
	
	
	private :
	
	double getposition2vert_moy() const;
	
	double getvitesse2vert_moy() const;

	double getpositionvitessevert_moy() const;
	
	double getposition2hori_moy() const;
	
	double getvitesse2hori_moy() const;
	
	double getpositionvitessehori_moy() const;
	
	//---------------------------------------------------------------
	
		
};


ostream& operator<<(ostream&, Faisceau const&); //surcharge de l'opÈrateur << permettant l'affichage dans le terminale
