#ifndef DROIT_H
#define DROIT_H

#include "Element.h"

class Droit : public Element
{
    public :

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Droit(); //constructeur par défaut qui initalise a 0
        Droit(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie et le rayon de l'élément

//--------prototypage des méthodes-------------------------------------------------------------------------------

        virtual bool touche_bord(Particule const&) const; //détermine si la particule a ou non heurté le bord de l'élément

    protected :

//--------prototypage des méthodes privée------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport à l'entrer de l'élément

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Droit const&); //surcharge de l'opérateur << permettant d'afficher un Droit dans le terminale

#endif
