#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <iostream>

using namespace std;
//Prototypage de la class vecteur3D
class Vecteur3D
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        double getx() const; // retourne x (double)
        double gety() const; // return y (double)
        double getz() const; // return z (double)

//--------prototypage des méthodes set---------------------------------------------------------------------------

        void setx(double); // remplace/affecte la valeur a à x
        void sety(double); // remplace/affecte la valeur a à y
        void setz(double); // remplace/affecte la valeur a à z

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Vecteur3D(); //constructeur par défaut qui crée un vecteur nul (0, 0, 0)
        Vecteur3D(double, double, double); //constructeur qui prends en arguments trois double a, b, c et initialise le vecteur a (a, b, c)

//--------prototypage des surcharges d'opérateurs----------------------------------------------------------------

        bool operator==(Vecteur3D const&) const; //surcharge l'opérateur de test : a == b

//--------prototypage des surcharges d'opérateurs arithmétique---------------------------------------------------

        Vecteur3D& operator+=(Vecteur3D const&); // v += v1 <=> v = v + v1
        Vecteur3D operator+(Vecteur3D const&) const; // addition 2 vecteurs :  v = v1 + v2
        Vecteur3D& operator-=(Vecteur3D const&); // v -= v1 <=> v = v - v1
        Vecteur3D operator-(Vecteur3D const&) const; // soustrait 2 vecteurs :  v = v1 - v2
        Vecteur3D operator-() const; // donne l'opposé du vecteur :  v = -v1
        double operator*(Vecteur3D const&) const; // renvoie le produit scalaire de 2 vecteurs : a = v1*v2 <=> a = v1.v2
        Vecteur3D operator^(Vecteur3D const&) const; // renvoie le produit vectoriel de 2 vecteurs : c = a.prod_vect(b); -->  "c = a X b"
        Vecteur3D operator~() const; // renvoie le vecteur unitaire associe au vecteur donné : v = ~v1 <=> v a mm sens, mm direction que v1, mais 1 norme de 1

//--------prototypage des méthodes-------------------------------------------------------------------------------

        double norme_carre() const; //renvoie le carré de la norme du vecteur : n = v.norme_carre(); <=> n = x^2+y^2+z^2
        double norme() const; //renvoie la norme du vecteur : n = v.norme(); <=> n = sqrt(x^2+y^2+z^2)
        Vecteur3D rotation(Vecteur3D, double const&) const; //renvoie le vecteur tourné d'un angle t autour de l'axe v

    protected :

//--------définition des attributs-------------------------------------------------------------------------------

        double x;
        double y;
        double z; //les 3 coordonnées du vecteur.

};

//--------prototypage des fonctions------------------------------------------------------------------------------

double prod_mixte(Vecteur3D, Vecteur3D, Vecteur3D); //renvoie le produit mixte : v = v1*(v2^v3)

//--------prototypage des surcharges externes--------------------------------------------------------------------

Vecteur3D operator*(double const&, Vecteur3D const&); //surcharge la multiplication par un scalaire a gauche
Vecteur3D operator*(Vecteur3D const&, double const&); //surcharge la multiplication par un scalaire a droite
ostream& operator<<(ostream&, Vecteur3D const&); //surcharge de l'opérateur <<

#endif
