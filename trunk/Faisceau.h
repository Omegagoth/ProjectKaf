#ifndef FAISCEAU_H
#define FAISCEAU_H

#include <iostream>
#include <vector>
#include "Particule3D.h"
#include "Element.h"

using namespace std;


class Faisceau
{
	
	protected :
	
	Particule3D reference;			// particule de reference
	double lambda;
	vector<Particule3D*> Vpart;		//collection de pointeurs sur des particules
	
	public :
	
	Faisceau(Particule3D, double);	//constructeur qui prend en argument la particule de reference et lambda
	Faisceau(Faisceau const&);		//constructeur de copie
	Faisceau();						//constructeur par defaut qui initialise a des valeurs nulles
	virtual ~Faisceau();			// destructeur
	
	//---------------------------------------------------------------
	
	void setreference(Particule3D const&); 	//permet de modifier la particule de reference
	void setlambda(double);					//permet de modifier lambda
	
	//---------------------------------------------------------------
	
	Particule3D getreference() const;		//retourne la particule de reference
	double getnb_particule3D() const;		//retourne le nombre de macro-particules contenues dans le faisceau
	double getlambda() const;				//retourne lambda
	vector<Particule3D*> getVpart() const;	//retourne la collection de pointeur sur des particules
	
	//---------------------------------------------------------------
	
	Faisceau& ajoute_Vpart(Particule3D const&);	//permet d'ajouter une particule au faisceau
	Faisceau& clear_Vpart();					//permet de supprimer toutes les particules du faisceau
	Faisceau& clear_Vpart(int i);				//permet de supprimer la i eme particule du faisceau

	
	//---------------------------------------------------------------
	
	double getenergie_moy() const;				//retourne l'energie moyenne du faisceau
	
	//---------------------------------------------------------------
	
	double getemittancevert() const;			//retourne l'emittance verticale
	
	double getemittancehori() const;			//retourne l'emittance horizontale
	
	//---------------------------------------------------------------
	
	double getA11vert() const;
	
	double getA12vert() const;
	
	double getA22vert() const;
	
	double getA11hori() const;				//retourne les coefficient A11, A12 et A22 verticaux et horizontaux
	
	double getA12hori() const;
	
	double getA22hori() const;
	
	virtual double getbunch_longueur() const;	// retourne 0
	
	virtual Faisceau& creation(double);			// ne fait rien
	
	
	
	//---------------------------------------------------------------
	
	Faisceau& bouger(double);					//fait bouger toute les particules du faisceau
	
	Faisceau& ajoute_forcemagn(double);			//ajoute la force magnetiaue a toute les particules 
	
	Faisceau& ajoute_forceinter();				//ajoute la force inter particule a tout les particules
	
	
	//---------------------------------------------------------------
	
	
	private :
	
	double getposition2vert_moy() const;
	
	double getvitesse2vert_moy() const;

	double getpositionvitessevert_moy() const;		//fonctions privee permettant de calculer
													//les emittances et le coefficients d'ellipse
	double getposition2hori_moy() const;
	
	double getvitesse2hori_moy() const;
	
	double getpositionvitessehori_moy() const;
	
	//---------------------------------------------------------------
	
		
};


ostream& operator<<(ostream&, Faisceau const&); //surcharge de l'opÈrateur << permettant l'affichage dans le terminale

#endif
