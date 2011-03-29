#ifndef COURBE_H
#define COURBE_H

#include <cmath>
#include "Element.h"

class Courbe : public Element
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        double getcourbure() const; //donne l'inverse du rayon de courbure de l'élément courbe
        Vecteur3D getcentre() const; //donne le centre de courbure de l'élément

//--------prototypage des méthodes get---------------------------------------------------------------------------

        void setcourbure(double const&); //permet de changer la valeur du rayon de courbure

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Courbe(); //constructeur par défaut qui initialise à 0
        Courbe(Vecteur3D, Vecteur3D, double, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie, la section et l'inverse du rayon de courbure orienter
        Courbe(const Courbe &);                       //constructeur de copie
        ~Courbe();                                    //destructeur

//--------prototypage des méthodes-------------------------------------------------------------------------------

        virtual bool touche_bord(Particule const&) const; //détermine si la particule a ou non heurté le bord de l'élément



    protected :

//--------définition des attributs-------------------------------------------------------------------------------

        double courbure;

//--------prototypage des méthodes privée------------------------------------------------------------------------

        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport au centre de courbure de l'élément : X = positon - centre de courbure

};




//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream& out, Courbe const&); //surcharge de l'opérateur << permettant d'afficher un Courbe dans le terminal


#endif
