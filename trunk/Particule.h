#ifndef PARTICULE_H
#define PARTICULE_H

#include "Vecteur3D.h"
#include <iostream>
#include <cmath>

using namespace std;

double const C(299792458);

class Particule
{
    public :

        /*//définition de constante importante
        static double const C(3*pow(10,8));*/

//---------------------------------------------------------------------------------------------------------------
        //prototypage des méthodes get
        Vecteur3D getposition() const;
        Vecteur3D getvitesse() const;
        double getmasse() const;
        double getcharge() const;
        double getenergie() const;
        double getgamma() const;
        Vecteur3D getforce() const;

//---------------------------------------------------------------------------------------------------------------

        //prototypage des fonctions set
        void setposition(Vecteur3D const&);
        void setvitesse(Vecteur3D const&);
        void setmasse(double const&);
        void setcharge(double const&);

//---------------------------------------------------------------------------------------------------------------

        //prototypage des constructeurs
        Particule(); //constructeur par défaut
        Particule(Vecteur3D position, Vecteur3D quantite_mouv, double masse, double charge); //construit un vecteur a partir de sa position, quantité de mouvement, masse et charge
        Particule(Vecteur3D, double, Vecteur3D, double, double); //construit un vecteur a partir de sa position, energie, direction de sa vitesse, masse et charge

//---------------------------------------------------------------------------------------------------------------

        //protoypage des méthodes
        void ajoute_forcemagn(Vecteur3D const&, double); //ajoute une force en prenant un vecteur B du champ magnétique et un intervalle de temps dt
        void bouger(double); //mets a jour la position et la vistesse de la particule pour un pas de temps donné

//---------------------------------------------------------------------------------------------------------------

    protected :

        Vecteur3D position;
        Vecteur3D vitesse;
        double masse;
        double charge;
        Vecteur3D force;
};

//---------------------------------------------------------------------------------------------------------------

ostream& operator<<(ostream&, Particule); //permet l'affichage par cout des particules


#endif
