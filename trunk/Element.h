#ifndef ELEMENT_H
#define ELEMENT_H

#include "Particule.h"
#include <iostream>

using namespace std;

class Element
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        Vecteur3D getentree() const; //donne l'entree de l'élément
        Vecteur3D getsortie() const; //donne la sortie de l'élément
        double getrayon() const; //donne le rayon de l'élément
        Element* getsuivant() const; //donne l'élément qui suit l'élément courant

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Element(); //constructeur par défaut qui initialise l'élément a 0
        Element(Vecteur3D, Vecteur3D, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie et le rayon de l'élément

//--------prototypage des surcharges d'opérateurs----------------------------------------------------------------

        Element& operator+=(Element&); //surcharge permettant de signifier a un élément l'élément qui le suit par : e1 += e2 ainsi le pointeur suivant de e1 pointera sur e2

//--------prototypage des méthodes-------------------------------------------------------------------------------

        virtual bool touche_bord(Particule const&) const = 0; //détermine si la particule a ou non heurté le bord de l'élément
        bool passe_suivant(Particule const&) const; //détermine si la particule à dépasser la sortie de l'élément

    protected :

//--------définition des attributs-------------------------------------------------------------------------------

        Vecteur3D entree;
        Vecteur3D sortie;
        double rayon;
        Element* suivant;

//--------prototypage des méthodes privée------------------------------------------------------------------------

        Vecteur3D getdirection() const; //donne la direction moyenne de l'élément
        virtual Vecteur3D getpos_relative(Particule const&) const = 0; //donne la position relative d'une particule par rapport à l'entrer de l'élément

};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Element const&); //surcharge de l'opérateur << permettant d'afficher dans le terminal un Elemant


#endif
