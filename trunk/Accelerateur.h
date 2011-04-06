#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H

#include <iostream>
#include <vector>
#include "Particule.h"
#include "Dipole.h"
#include "Quadrupole.h"
#include "Section_droite.h"
#include "Fodo.h"

using namespace std;

class Accelerateur
{
    public :

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        vector<Particule*> getparticules() const;     //donne l'ensemble des particules de l'acc�l�rateur sous forme de vector
        Particule* getparticules(unsigned int) const; //donne un pointeur vers la i�me particule de l'acc�l�rateur
        vector<Element*> getelements() const;         //donne l'ensemble des �l�ments de l'acc�l�rateur sous forme de vector
        Element* getelements(unsigned int) const;     //donne un pointeur vers le i�me �l�ment de l'acc�l�rateur

//--------prototypage des m�thodes set----------------------------------------------------------------------------

        void setparticules(Particule const&, unsigned int); //remplace la i�me particule par la particule pass�e en argument
        void setelements(Element const&, unsigned int);     //remplace la i�me �l�ment par l'�l�ment pass� en argument

//--------prototypage des constructeurs/destructeur--------------------------------------------------------------

        Accelerateur(); //constructeur par d�faut qui initialise � vide
        ~Accelerateur();//prototypage du destructeur

//--------prototypage des m�thodes-------------------------------------------------------------------------------

        Accelerateur& ajoute_particule(Particule const&); //m�thode permettant de rajouter une particule � l'acc�l�rateur
        Accelerateur& ajoute_element(Element const&);     //m�thode permettant de rajouter un �l�ment � l'acc�l�rateur
        Accelerateur& clear_particules();                 //m�thode permettant de supprimer toutes les particules de l'acc�l�rateur
		Accelerateur& clear_particules(int unsigned);	  //m�thode permettant de supprimer la i�me particule de l'acc�l�rateur
        Accelerateur& clear_elements();                   //m�thode permettant de supprimer tout les �lements de l'acc�l�rateur
		Accelerateur& affecte_element();				  //m�thode permettant d'affecter un element � chaque particule
		Accelerateur& evolue(double);					  //m�thode permettant de faire "bouger" toute les particules

    protected :

//--------d�finition des attributs-------------------------------------------------------------------------------

        vector<Particule*> particules; //stockage des diff�rentes particules dans un tableau a taille variable
        vector<Element*> elements;     //stockage des diff�rents �lements de l'acc�lerateur dans un tableau a taille variable

//--------prototypage des constructeurs/surcharges priv�e--------------------------------------------------------

        Accelerateur(Accelerateur const&);            //constructeur de copie qui ne fait rien
        Accelerateur& operator=(Accelerateur const&); //surcharge de l'op�rateur = qui ne fait rien

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Accelerateur const&); //surcharge de l'op�rateur << permettant l'affichage dans le terminale


#endif
