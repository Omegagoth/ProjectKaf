#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H

#include <iostream>
#include <vector>
#include "Particule3D.h"
#include "Dipole3D.h"
#include "Quadrupole.h"
#include "Section_droite3D.h"
#include "Fodo.h"

using namespace std;

class Accelerateur
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        vector<Particule*> getparticules() const;     //donne l'ensemble des particules de l'accélérateur sous forme de tableau dynamique de pointeur
        Particule* getparticules(unsigned int) const; //donne un pointeur vers la ième particule de l'accélérateur
        vector<Element*> getelements() const;         //donne l'ensemble des éléments de l'accélérateur sous forme de tableau dynamique de pointeur
        Element* getelements(unsigned int) const;     //donne un pointeur vers le ième élément de l'accélérateur

//--------prototypage des méthodes set----------------------------------------------------------------------------

        void setparticules(Particule const&, unsigned int); //remplace la ième particule par la particule passée en argument
        void setelements(Element const&, unsigned int);     //remplace la ième élément par l'élément passé en argument

//--------prototypage des constructeurs/destructeur--------------------------------------------------------------

        Accelerateur(); //constructeur par défaut qui initialise à vide
        virtual ~Accelerateur();//prototypage du destructeur

//--------prototypage des méthodes-------------------------------------------------------------------------------

        Accelerateur& ajoute_particule(Particule const&); //méthode permettant de rajouter une particule à l'accélérateur
        Accelerateur& ajoute_element(Element const&);     //méthode permettant de rajouter un élément à l'accélérateur
        Accelerateur& clear_particules();                 //méthode permettant de supprimer toutes les particules de l'accélérateur
		Accelerateur& clear_particules(int unsigned);	  //méthode permettant de supprimer la iéme particule de l'accélérateur
        Accelerateur& clear_elements();                   //méthode permettant de supprimer tout les élements de l'accélérateur
		Accelerateur& affecte_element();				  //méthode permettant d'affecter un element à chaque particule
		Accelerateur& evolue(double);					  //méthode permettant de faire "bouger" toute les particules
		void dessine() const;

    protected :

//--------définition des attributs-------------------------------------------------------------------------------

        vector<Particule*> particules; //stockage des différentes particules dans un tableau dynamique de pointeur
        vector<Element*> elements;     //stockage des différents élements de l'accélerateur dans un tableau dynamique de pointeur

//--------prototypage des constructeurs/surcharges privée--------------------------------------------------------

        Accelerateur(Accelerateur const&);            //constructeur de copie qui ne fait rien
        Accelerateur& operator=(Accelerateur const&); //surcharge de l'opérateur = qui ne fait rien

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Accelerateur const&); //surcharge de l'opérateur << permettant l'affichage dans le terminale


#endif
