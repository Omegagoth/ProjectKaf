#ifndef COURBE_H
#define COURBE_H

#include <cmath>
#include "Element.h"

class Courbe : public Element
{
    public :

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        double getcourbure() const; //donne l'inverse du rayon de courbure de l'�l�ment courbe
        Vecteur3D getcentre() const; //donne le centre de courbure de l'�l�ment

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        void setcourbure(double const&); //permet de changer la valeur du rayon de courbure

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Courbe(); //constructeur par d�faut qui initialise � 0
        Courbe(Vecteur3D, Vecteur3D, double, double); //constructeur qui prend en argument le vecteur d'entr�e, de sortie, la section et l'inverse du rayon de courbure orienter
        Courbe(const Courbe &);                       //constructeur de copie
        ~Courbe();                                    //destructeur

//--------prototypage des m�thodes-------------------------------------------------------------------------------

        virtual bool touche_bord(Particule const&) const; //d�termine si la particule a ou non heurt� le bord de l'�l�ment



    protected :

//--------d�finition des attributs-------------------------------------------------------------------------------

        double courbure;

//--------prototypage des m�thodes priv�e------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport au centre de courbure de l'�l�ment : X = positon - centre de courbure

};




//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream& out, Courbe const&); //surcharge de l'op�rateur << permettant d'afficher un Courbe dans le terminal


#endif
