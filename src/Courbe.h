#ifndef COURBE_H
#define COURBE_H

#include <cmath>
#include "Element.h"

class Courbe : virtual public Element
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        double getcourbure() const;                                         //donne l'inverse du rayon de courbure de l'élément courbe
        Vecteur3D getcentre() const;                                        //donne le centre de courbure de l'élément
		virtual Vecteur3D getchamps_magnetique(Particule const&) const = 0;	//methode abstraite qui donne le champs magnetique de l'element
		double getangle() const;											//donne l'angle au centre de l'élément courbe
		virtual double getlongueur() const;									//donne la longueur de l'element		
		virtual Vecteur3D pos_ideale(double) const;							//donne la position ideale en fonction d'une longueur (a partir de l'entree)
		virtual Vecteur3D dir_ideale(double) const;							//donne la direction ideale en fonction d'une longueur (a partir de l'entree)
//--------prototypage des méthodes set---------------------------------------------------------------------------

        void setcourbure(double const&); //permet de changer la valeur du rayon de courbure

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Courbe();                                     //constructeur par défaut qui initialise à 0
        Courbe(Vecteur3D, Vecteur3D, double, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie, la section et l'inverse du rayon de courbure oriente
        Courbe(const Courbe&);                        //constructeur de copie
        virtual ~Courbe();                            //destructeur

//--------prototypage des méthodes-------------------------------------------------------------------------------

        virtual bool heurte_bord(Particule const&) const; //détermine si la particule a ou non heurté le bord de l'élément
        virtual void affiche(ostream&) const = 0;         //méthode abstraite polymorphique d'affichage
        virtual Courbe* copie() const = 0;                //méthode abstraite de copie polymorphique
		virtual Vecteur3D getu(Particule const&) const;   //méthode abstraite revoyant le vecteur u ( {X-x3e3}1 )
		virtual void dessine() const = 0;
		

    protected :

//--------définition des attributs-------------------------------------------------------------------------------

        double courbure;

//--------prototypage des méthodes privée------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport au centre de courbure de l'élément : X = positon - centre de courbure

};




//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream& out, Courbe const&); //surcharge de l'opérateur << permettant d'afficher un Courbe dans le terminal


#endif
