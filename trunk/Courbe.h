#ifndef COURBE_H
#define COURBE_H

#include <cmath>
#include "Element.h"

class Courbe : public Element
{
    public :

        //prototypage des m�thodes get
        double getcourbure() const; //donne l'inverse du rayon de courbure de l'�l�ment courbe
        Vecteur3D getcentre() const; //donne le centre de courbure de l'�l�ment

//---------------------------------------------------------------------------------------------------------------

        //prototypage des constructeurs
        Courbe(); //constructeur par d�faut qui initialise a 0
        Courbe(Vecteur3D, Vecteur3D, double, double); //constructeur qui prend en argument le vecteur d'entr�e, de sortie, la section et l'inverse du rayon de courbure orienter

//---------------------------------------------------------------------------------------------------------------

        //prototypage des m�thodes
        virtual bool touche_bord(Particule const&) const; //d�termine si la particule a ou non heurt� le bord de l'�l�ment

//---------------------------------------------------------------------------------------------------------------

    protected :

        //d�finiton des attributs
        double courbure;

//---------------------------------------------------------------------------------------------------------------

        //prototypage des m�thodes priv�e
        virtual Vecteur3D getpos_relative(Particule const&) const; //donne la position relative d'une particule par rapport au centre de courbure de l'�l�ment : X = positon - centre de courbure

};

//---------------------------------------------------------------------------------------------------------------

//prototypage des surcharges externes
ostream& operator<<(ostream& out, Courbe const&); //surcharge de l'op�rateur << permettant d'afficher un Courbe dans le terminal

//---------------------------------------------------------------------------------------------------------------

class Dipole : public Courbe
{
    public :

        //prototypage des m�thodes get
        double getchamps() const; //retourne la valeurs du champs magn�tique des dipoles

//---------------------------------------------------------------------------------------------------------------

        //prototypage des constructeurs
        Dipole(); //constructeur par d�faut
        Dipole(Vecteur3D, Vecteur3D, double, double, double); //constructeur qui prend en argument le vecteur d'entr�e, de sortie, le rayon de l'�l�ment, de courbure, et la valeurs du champs magn�tique verticale

//---------------------------------------------------------------------------------------------------------------

    protected :

        //d�finitions des attributs
        double champs;

};

//---------------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream&, Dipole const&); //surcharge de l'op�rateur << permettant d'afficher un Dipole dans le terminal

#endif
