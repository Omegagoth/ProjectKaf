#ifndef DROIT_H
#define DROIT_H

#include "Element.h"

class Droit : virtual public Element
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        virtual double getlongueur() const;                                 //retourne la longueur de l'élément
		virtual Vecteur3D getchamps_magnetique(Particule const&) const = 0;	//methode abstraite qui donne le champs magnetique de l'ŽlŽment
		virtual Vecteur3D pos_ideale(double) const;							//donne la position ideale en fonction d'une longueur (a partir de l'entree)
		virtual Vecteur3D dir_ideale(double) const;							//donne la direction ideale en fonction d'une longueur (a partir de l'entree)

//--------prototypage des constructeurs/destructeur--------------------------------------------------------------

        Droit();                             //constructeur par défaut qui initalise a 0
        Droit(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie et le rayon de l'élément
        Droit(Droit const&);                 //constructeur de copie
        virtual ~Droit();                    //destructeur

//--------prototypage des méthodes-------------------------------------------------------------------------------

        virtual bool heurte_bord(Particule const&) const; //détermine si la particule a ou non heurté le bord de l'élément
        virtual Droit* copie() const = 0;                 //méthode de copie polymorphique
        virtual void affiche(ostream&) const = 0;         //méthode abstraite polymorphique d'affichage
		virtual Vecteur3D getu(Particule const&) const;	  //méthode revoyant le vecteur u (e3^d)
		virtual void dessine() const = 0;
		


    protected :

//--------prototypage des méthodes privée------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport à l'entrer de l'élément

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Droit const&); //surcharge de l'opérateur << permettant d'afficher un Droit dans le terminale

#endif
