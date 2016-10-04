#ifndef DROIT_H
#define DROIT_H

#include "Element.h"

class Droit : virtual public Element
{
    public :

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        virtual double getlongueur() const;                                 //retourne la longueur de l'�l�ment
		virtual Vecteur3D getchamps_magnetique(Particule const&) const = 0;	//methode abstraite qui donne le champs magnetique de l'�l�ment
		virtual Vecteur3D pos_ideale(double) const;							//donne la position ideale en fonction d'une longueur (a partir de l'entree)
		virtual Vecteur3D dir_ideale(double) const;							//donne la direction ideale en fonction d'une longueur (a partir de l'entree)

//--------prototypage des constructeurs/destructeur--------------------------------------------------------------

        Droit();                             //constructeur par d�faut qui initalise a 0
        Droit(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entr�e, de sortie et le rayon de l'�l�ment
        Droit(Droit const&);                 //constructeur de copie
        virtual ~Droit();                    //destructeur

//--------prototypage des m�thodes-------------------------------------------------------------------------------

        virtual bool heurte_bord(Particule const&) const; //d�termine si la particule a ou non heurt� le bord de l'�l�ment
        virtual Droit* copie() const = 0;                 //m�thode de copie polymorphique
        virtual void affiche(ostream&) const = 0;         //m�thode abstraite polymorphique d'affichage
		virtual Vecteur3D getu(Particule const&) const;	  //m�thode revoyant le vecteur u (e3^d)
		virtual void dessine() const = 0;
		


    protected :

//--------prototypage des m�thodes priv�e------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport � l'entrer de l'�l�ment

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Droit const&); //surcharge de l'op�rateur << permettant d'afficher un Droit dans le terminale

#endif
