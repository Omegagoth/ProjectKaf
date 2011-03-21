#ifndef COURBE_H
#define COURBE_H

#include <cmath>
#include "Element.h"
#include "Particule.h"

class Courbe : public Element
{
    public :

        //prototypage des méthodes get
        double getcourbure() const; //donne l'inverse du rayon de courbure de l'élément courbe
        Vecteur3D getcentre() const; //donne le centre de courbure de l'élément

//---------------------------------------------------------------------------------------------------------------

        //prototypage des constructeurs
        Courbe(); //constructeur par défaut qui initialise a 0
        Courbe(Vecteur3D, Vecteur3D, double, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie, la section et l'inverse du rayon de courbure orienter

//---------------------------------------------------------------------------------------------------------------

        //prototypage des méthodes
        bool touche_bord(Particule const&) const; //détermine si la particule a ou non heurté le bord de l'élément
        bool passe_suivant(Particule const&) const; //détermine si la particule à dépasser la sortie de l'élément

//---------------------------------------------------------------------------------------------------------------

    protected :

        //définiton des attributs
        double courbure;

//---------------------------------------------------------------------------------------------------------------

        //prototypage des méthodes privée
        Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport au centre de courbure de l'élément : X = positon - centre de courbure

};

//---------------------------------------------------------------------------------------------------------------

//prototypage des surcharges externes
ostream& operator<<(ostream& out, Courbe const&); //surcharge de l'opérateur << permettant d'afficher un Courbe dans le terminal

#endif
