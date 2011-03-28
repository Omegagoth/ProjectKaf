#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <iostream>

using namespace std;
//Prototypage de la class vecteur3D
class Vecteur3D
{
    public :

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        double getx() const; // retourne x (double)
        double gety() const; // return y (double)
        double getz() const; // return z (double)

//--------prototypage des m�thodes set---------------------------------------------------------------------------

        void setx(double); // remplace/affecte la valeur a � x
        void sety(double); // remplace/affecte la valeur a � y
        void setz(double); // remplace/affecte la valeur a � z

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Vecteur3D(); //constructeur par d�faut qui cr�e un vecteur nul (0, 0, 0)
        Vecteur3D(double, double, double); //constructeur qui prends en arguments trois double a, b, c et initialise le vecteur a (a, b, c)

//--------prototypage des surcharges d'op�rateurs----------------------------------------------------------------

        bool operator==(Vecteur3D const&) const; //surcharge l'op�rateur de test : a == b

//--------prototypage des surcharges d'op�rateurs arithm�tique---------------------------------------------------

        Vecteur3D& operator+=(Vecteur3D const&); // v += v1 <=> v = v + v1
        Vecteur3D operator+(Vecteur3D const&) const; // addition 2 vecteurs :  v = v1 + v2
        Vecteur3D& operator-=(Vecteur3D const&); // v -= v1 <=> v = v - v1
        Vecteur3D operator-(Vecteur3D const&) const; // soustrait 2 vecteurs :  v = v1 - v2
        Vecteur3D operator-() const; // donne l'oppos� du vecteur :  v = -v1
        double operator*(Vecteur3D const&) const; // renvoie le produit scalaire de 2 vecteurs : a = v1*v2 <=> a = v1.v2
        Vecteur3D operator^(Vecteur3D const&) const; // renvoie le produit vectoriel de 2 vecteurs : c = a.prod_vect(b); -->  "c = a X b"
        Vecteur3D operator~() const; // renvoie le vecteur unitaire associe au vecteur donn� : v = ~v1 <=> v a mm sens, mm direction que v1, mais 1 norme de 1

//--------prototypage des m�thodes-------------------------------------------------------------------------------

        double norme_carre() const; //renvoie le carr� de la norme du vecteur : n = v.norme_carre(); <=> n = x^2+y^2+z^2
        double norme() const; //renvoie la norme du vecteur : n = v.norme(); <=> n = sqrt(x^2+y^2+z^2)
        Vecteur3D rotation(Vecteur3D, double const&) const; //renvoie le vecteur tourn� d'un angle t autour de l'axe v

    protected :

//--------d�finition des attributs-------------------------------------------------------------------------------

        double x;
        double y;
        double z; //les 3 coordonn�es du vecteur.

};

//--------prototypage des fonctions------------------------------------------------------------------------------

double prod_mixte(Vecteur3D, Vecteur3D, Vecteur3D); //renvoie le produit mixte : v = v1*(v2^v3)

//--------prototypage des surcharges externes--------------------------------------------------------------------

Vecteur3D operator*(double const&, Vecteur3D const&); //surcharge la multiplication par un scalaire a gauche
Vecteur3D operator*(Vecteur3D const&, double const&); //surcharge la multiplication par un scalaire a droite
ostream& operator<<(ostream&, Vecteur3D const&); //surcharge de l'op�rateur <<

#endif
