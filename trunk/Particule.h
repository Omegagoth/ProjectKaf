#ifndef PARTICULE_H
#define PARTICULE_H

#include "Vecteur3D.h"
#include <iostream>
#include <cmath>

using namespace std;

double const C(299792458);

class Element;

class Particule
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        Vecteur3D getposition() const;  //methode retournant le vecteur position de la particule
        Vecteur3D getvitesse() const;   //methode retournant le vecteur vitesse de la particule
        double getmasse() const;        //methode retournant la masse de la particule
        double getcharge() const;       //methode retournant la charge electrique de la particule
        double getenergie() const;      //methode retournant l'energie de la particule en GeV
        double getgamma() const;        //methode retournant le gamma de la particule (= 1/sqrt(1-v^2/C^2) )
        Vecteur3D getforce() const;     //methode retournant le vecteur somme des forces applique a la particule
		Element* getappartient() const; //methode retournant un pointeur vers l'element dans lequel ce situe la particule (0 si n'appartient a aucun element)

//--------prototypage des méthodes set---------------------------------------------------------------------------

        void setposition(Vecteur3D const&); //permet de modifier le vecteur position de la particule
        void setvitesse(Vecteur3D const&);  //permet de modifier le vecteur vitesse de la particule
        void setmasse(double const&);       //permet de modifier la masse de la particule
        void setcharge(double const&);      //permet de modifier la charge de la particule
		void setappartient(Element&);       //permet de modifier le pointeur indiquant l'element dans lequel ce trouve la particule

//--------prototypage des constructeurs--------------------------------------------------------------------------

        Particule();                                                                         //constructeur par défaut
        Particule(Vecteur3D position, Vecteur3D quantite_mouv, double masse, double charge); //construit un vecteur a partir de sa position, quantité de mouvement, masse et charge
        Particule(Vecteur3D, double, Vecteur3D, double, double);                             //construit un vecteur a partir de sa position, energie, direction de sa vitesse, masse et charge

//--------prototypage des méthodes-------------------------------------------------------------------------------

        Particule& ajoute_forcemagn(Vecteur3D const&, double); //ajoute une force en prenant un vecteur B du champ magnétique et un intervalle de temps dt
		Particule& ajoute_forceinter(Particule const&);		   //ajoute la force inter-particules
        Particule& bouger(double);                             //mets a jour la position et la vistesse de la particule pour un pas de temps donné



    protected :

//--------définition des attributs-------------------------------------------------------------------------------

        Vecteur3D position;  //vecteur position de la particule
        Vecteur3D vitesse;   //vecteur vistesse de la particule
        double masse;        //masse de la particule
        double charge;       //charge de la particule
        Vecteur3D force;     //vecteur de la somme des force appliquees de la particule
		Element* appartient; //pointeur vers l'element dans lequel ce trouve la particule
};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Particule); //permet l'affichage par cout des particules


#endif
