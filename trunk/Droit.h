#ifndef DROIT_H
#define DROIT_H

#include "Element.h"

class Droit : public Element
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        double getlongueur() const; //retourne la longueur de l'élément

//--------prototypage des constructeurs/destructeur--------------------------------------------------------------

        Droit();                             //constructeur par défaut qui initalise a 0
        Droit(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie et le rayon de l'élément
        Droit(Droit const&);                 //constructeur de copie
        virtual ~Droit();                    //destructeur

//--------prototypage des méthodes-------------------------------------------------------------------------------

        virtual bool heurte_bord(Particule const&) const; //détermine si la particule a ou non heurté le bord de l'élément
        virtual Droit* copie() const;                     //méthode de copie polymorphique



    protected :

//--------prototypage des méthodes privée------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport à l'entrer de l'élément

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Droit const&); //surcharge de l'opérateur << permettant d'afficher un Droit dans le terminale

#endif
