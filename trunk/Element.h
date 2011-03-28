#ifndef ELEMENT_H
#define ELEMENT_H

#include "Particule.h"
#include <iostream>

using namespace std;

class Element
{
    public :

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        Vecteur3D getentree() const; //donne l'entree de l'�l�ment
        Vecteur3D getsortie() const; //donne la sortie de l'�l�ment
        double getrayon() const; //donne le rayon de l'�l�ment
        Element* getsuivant() const; //donne l'�l�ment qui suit l'�l�ment courant

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Element(); //constructeur par d�faut qui initialise l'�l�ment a 0
        Element(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entr�e, de sortie et le rayon de l'�l�ment

//--------prototypage des surcharges d'op�rateurs----------------------------------------------------------------

        Element& operator+=(Element&); //surcharge permettant de signifier a un �l�ment l'�l�ment qui le suit par : e1 += e2 ainsi le pointeur suivant de e1 pointera sur e2

//--------prototypage des m�thodes-------------------------------------------------------------------------------

        virtual bool touche_bord(Particule const&) const = 0; //d�termine si la particule a ou non heurt� le bord de l'�l�ment
        bool passe_suivant(Particule const&) const; //d�termine si la particule � d�passer la sortie de l'�l�ment

    protected :

//--------d�finition des attributs-------------------------------------------------------------------------------

        Vecteur3D entree;
        Vecteur3D sortie;
        double rayon;
        Element* suivant;

//--------prototypage des m�thodes priv�e------------------------------------------------------------------------

        Vecteur3D getdirection() const; //donne la direction moyenne de l'�l�ment
        virtual Vecteur3D getpos_relative(Particule const&) const = 0; //donne la position relative d'une particule par rapport � l'entrer de l'�l�ment

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Element const&); //surcharge de l'op�rateur << permettant d'afficher dans le terminal un Elemant


#endif
