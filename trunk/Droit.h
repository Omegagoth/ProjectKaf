#ifndef DROIT_H
#define DROIT_H

#include "Element.h"
#include "Particule.h"

class Droit : public Element
{
    public :

        //protoypage des constructeurs
        Droit(); //constructeur par d�faut qui initalise a 0
        Droit(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entr�e, de sortie et le rayon de l'�l�ment

//---------------------------------------------------------------------------------------------------------------

        //prototypage des m�thodes
        bool touche_bord(Particule const&) const; //d�termine si la particule a ou non heurt� le bord de l'�l�ment
        bool passe_suivant(Particule const&) const; //d�termine si la particule � d�passer la sortie de l'�l�ment

//---------------------------------------------------------------------------------------------------------------

    protected :

        //prototypage des m�thodes priv�es
        Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport � l'entrer de l'�l�ment

};

//---------------------------------------------------------------------------------------------------------------
//prototypage des surcharges externes
ostream& operator<<(ostream&, Droit const&); //surcharge de l'op�rateur << permettant d'afficher un Droit dans le terminale

#endif
