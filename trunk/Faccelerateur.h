#ifndef FACCELERATEUR_H
#define FACCELERATEUR_H

#include <iostream>
#include <vector>
#include "Particule3D.h"
#include "Dipole3D.h"
#include "Quadrupole3D.h"
#include "Section_droite3D.h"
#include "Fodo3D.h"
#include "Faisceau.h" 
#include "bunch.h"

using namespace std;

class Faccelerateur
{
    public :

	//--------prototypage des mÈthodes get---------------------------------------------------------------------------
	
	vector<Faisceau*> getfaisceaux() const;       //donne l'ensemble des faisceaux de l'accÈlÈrateur sous forme de tableau dynamique de pointeur
	Faisceau* getfaisceaux(unsigned int) const;   //donne un pointeur vers le iËme faisceau de l'accÈlÈrateur
	vector<Element*> getelements() const;         //donne l'ensemble des ÈlÈments de l'accÈlÈrateur sous forme de tableau dynamique de pointeur
	Element* getelements(unsigned int) const;     //donne un pointeur vers le iËme ÈlÈment de l'accÈlÈrateur
	double getperimetre() const;				  //renvoie la longueur totale de l'accelerateur

	//--------prototypage des mÈthodes set----------------------------------------------------------------------------
	
	void setfaisceaux(Faisceau const&, unsigned int);   //remplace le iËme faisceau par le faisceau passÈe en argument
	void setelements(Element const&, unsigned int);     //remplace la iËme ÈlÈment par l'ÈlÈment passÈ en argument
	
	//--------prototypage des constructeurs/destructeur--------------------------------------------------------------
	
	Faccelerateur(); //constructeur par dÈfaut qui initialise ‡ vide
	virtual ~Faccelerateur();//prototypage du destructeur
	
	//--------prototypage des mÈthodes-------------------------------------------------------------------------------
	
	Faccelerateur& ajoute_faisceau(double, Particule3D const&, double);   //mÈthode permettant de rajouter un faisceau ‡ l'accÈlÈrateur
	Faccelerateur& ajoute_element(Element const&);     //mÈthode permettant de rajouter un ÈlÈment ‡ l'accÈlÈrateur
	Faccelerateur& clear_faisceaux();                  //mÈthode permettant de supprimer tout les faisceaux de l'accÈlÈrateur
	Faccelerateur& clear_faisceaux(int unsigned);	  //mÈthode permettant de supprimer le iÈme faisceau de l'accÈlÈrateur
	Faccelerateur& clear_elements();                   //mÈthode permettant de supprimer tout les Èlements de l'accÈlÈrateur
	Faccelerateur& affecte_element();				  //mÈthode permettant d'affecter un element à chaque faisceau
	Faccelerateur& evolue(double);					  //mÈthode permettant de faire "bouger" tous les faisceaux
	
    protected :
	
	//--------dÈfinition des attributs-------------------------------------------------------------------------------
	
	vector<Faisceau*> faisceaux;   //stockage des diffÈrents faisceaux dans un tableau dynamique de pointeur
	vector<Element*> elements;     //stockage des diffÈrents Èlements de l'accÈlerateur dans un tableau dynamique de pointeur
	
	//--------prototypage des constructeurs/surcharges privÈe--------------------------------------------------------
	
	Faccelerateur(Faccelerateur const&);            //constructeur de copie qui ne fait rien
	Faccelerateur& operator=(Faccelerateur const&); //surcharge de l'opÈrateur = qui ne fait rien
	
};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Faccelerateur const&); //surcharge de l'opÈrateur << permettant l'affichage dans le terminale


#endif
