#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include "Particule.h"

using namespace std;

class Element
{
	public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        Vecteur3D getre() const;             //donne l'entree de l'élément
        Vecteur3D getrs() const;             //donne la sortie de l'élément
        double getRe() const;                //donne le rayon de l'élément
        Element* getElement_suivant() const; //donne l'élément qui suit l'élément courant
		virtual Vecteur3D getchamps_magnetique(Particule const&) const = 0;	//méthode abstraite qui donne le champs magnetique de l'élément

//--------prototypage des méthodes set----------------------------------------------------------------------------

        void setre(Vecteur3D const&);              //permet de définir l'entrée de l'élément
        void setrs(Vecteur3D const&);              //permet de définir la sortie de l'élément
        void setRe(double const&);                 //permet de définir le rayon de l'élément
        virtual void setElement_suivant(Element&); //permet de définir l'élément qui suit

//--------prototypage des constructeurs/destructeur---------------------------------------------------------------

        Element ();	                            //constructeur par défaut qui initialise l'élément a 0
        Element (Vecteur3D, Vecteur3D, double);	//constructeur qui prend en argument le vecteur d'entrée, de sortie et le rayon de l'élément
        Element (Element const&);               //constructeur de copie
        virtual ~Element();	                    //destructeur

//--------prototypage des méthodes--------------------------------------------------------------------------------

        bool passe_suivant(Particule const&);		          //détermine si la particule à dépasser la sortie de l'élément
        virtual bool heurte_bord(Particule const&) const = 0; //détermine si la particule a ou non heurté le bord de l'élément
        virtual Element* copie() const = 0;                   //méthode abstraite de copie polymorphique
        virtual void affiche(ostream&) const = 0;             //méthode abstraite polymorphique d'affichage

	protected :

//--------définition des attributs-------------------------------------------------------------------------------

        Vecteur3D re;					// position d'entrée.
        Vecteur3D rs;					// postition de sortie.
        double Re;						// Rayon de la chambre à vide.
        Element* Element_suivant;		// pointeur qui envoie sur l'element suivant.

//--------définition des statics---------------------------------------------------------------------------------

        static Vecteur3D E1;			// vecteur unitaire de x : (1,0,0)
        static Vecteur3D E2;			// vecteur unitaire de y : (0,1,0)
        static Vecteur3D E3;			// vecteur unitaire de z : (0,0,1)

//--------prototypage des méthodes privée------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const = 0; //donne la position relative d'une particule par rapport à l'entrer de l'élément
        Vecteur3D getdirection() const;                                //donne la direction moyenne de l'élément
        void orientation();                                            //vérifie que l'élément est correctement orienter (dans le sens horaire) sinon inverse les vecteurs re et rs

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Element const&);


#endif
