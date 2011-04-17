#ifndef FODO_H
#define FODO_H

#include <vector>
#include "Droit.h"
#include "Section_droite.h"
#include "Quadrupole.h"

class Fodo : public Droit
{
    public :

//--------prototypage des méthodes get---------------------------------------------------------------------------

        double getlongueur_droit() const;               //retourne la longueur des sections droites de la maille Fodo
        double getintensite() const;                    //retourne l'intensité du champs magnétique des quadrupôles de la maille Fodo
        vector<Element*> getmaille() const;             //retourne un tableau de pointeur vers les éléments composant la maille Fodo
        virtual Element* getmaille(unsigned int) const; //retourne un pointeur vers le i-1 élément composant la maille Fodo
        double getlongueur_quadrupole() const;          //retourne la longueur des quadrupôles de la maille Fodo
        virtual Vecteur3D getchamps_magnetique(Particule const&) const; //retourne le champs magnétique en fonction de la position de la particule

//--------prototypage des méthodes set---------------------------------------------------------------------------

        void setlongueur_droit(double);            //permet de modifier la longueur des sections droites de la maille Fodo
        void setintensite(double);                 //permet de modifier l'intensité du champ magnétique de la maille Fodo
        virtual void setElement_suivant(Element&); //masquage de la fonctions permettant de désigner l'élément qui suit la maille Fodo

//--------prototypage des constructeurs/destructeur---------------------------------------------------------------

        Fodo();                                             //constructeur par défaut qui initialise la maille (donc tous ses éléments) à 0
        Fodo(Vecteur3D, Vecteur3D, double, double, double); //constructeur qui prend en argument le vecteur d'entrée, de sortie, le rayon, la longueur des sections droites et l'intensité du champ magnétique de la maille Fodo
        Fodo(Fodo const&);                                  //constructeur de copie (fait une copie profonde)
        virtual ~Fodo();                                    //destructeur

//--------prototypage des méthodes--------------------------------------------------------------------------------

        bool heurte_bord(Particule const&) const; //masquage de la fonction qui détermine si la particule à heurter le bord ou non
        virtual Fodo* copie() const;              //méthode de copie polymorphique
        virtual void affiche(ostream&) const;     //méthode polymorphique d'affichage des mailles Fodo

//--------prototypage des surcharges d'opérateurs-----------------------------------------------------------------

        Fodo& operator=(Fodo const&); //surcharge de l'opérateur = pour faire une copie profonde

    protected :

//--------définition des attributs-------------------------------------------------------------------------------

        double longueur_droit;
        double intensite;
        vector<Element*> maille;

//--------définition des statics---------------------------------------------------------------------------------

        static unsigned int taille;


};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Fodo&);

#endif
