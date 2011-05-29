#ifndef BUNCH_H
#define BUNCH_H

#include "Faisceau.h"
#include "Random.h"


class Bunch : public Faisceau
{
	public :
	
	Bunch();		//constructeur par defaut qui initialise a 0
	Bunch(Particule3D const&, double, double, double, double, double, double, double);
	// constructeur qui prend en argument une particule de reference, lambda, l'ecart-type, l'emittance, A12, A22, la longueure du bunch et le nombre de particules qu'il doit contenir
	Bunch(Bunch const&); 	// constructeur de copie
	virtual ~Bunch();		// destructeur
	
	//-----------------------------------------------------------
	
	double getecart_type() const;			// retourne l'ecart-type
	double getemittance() const;			// retourne l'emittance
	double getbunch_longueur() const;		// retourne la longueur du bunch
	double getnb_particule3D() const;		// retourne le nombre de particule qu contien le bunch
	double getA22() const;					// retourne A22
	double getA12() const;					// retourne A12
	double getA11() const;					// retourne A11
	double gettheta() const;				// retourne l'angle theta
	double geta() const;					// retourne a
	double getb() const;					// retourne b
	double getx();							// retourne x selon r
	double gety();							// retourne y selon r
	double getr();							// retourne r
	double getVr();							// retourne la vitesse selon r
	double getx_z();						// retourne x selon z
	double gety_z();						// retourne y selonz
	double getz();							// retourne z
	double getVz();							// retourne la vitesse selon z
	double getnorme2_vitesse();				// retourne la norme de la vitesse au carre
	
	
	//-----------------------------------------------------------
	
	double gaussienne(double, double);		//retourne une gaussienne, prends en argument la moy4enne et l'ecart-type
	Faisceau& creation(double);				//cree un bunch selon un pas de temps dt
	
	//-----------------------------------------------------------
	
	protected :
	
	double ecart_type;
	double emittance;
	double A22;
	double A12;
	double bunch_longueur;  		// longueur du bunch
	double nb_particule3D;			// nombre de particule contenues par le bunch
	
	
};

#endif
