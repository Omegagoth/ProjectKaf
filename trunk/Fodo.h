#ifndef FODO_H
#define FODO_H

#include <vector>
#include "Droit.h"
#include "Section_droite.h"
#include "Quadrupole.h"

class Fodo : public Droit
{
    public :

//--------prototypage des m�thodes get---------------------------------------------------------------------------

        double getlongueur_droit() const;               //retourne la longueur des sections droites de la maille Fodo
        double getintensite() const;                    //retourne l'intensit� du champs magn�tique des quadrup�les de la maille Fodo
        vector<Element*> getmaille() const;             //retourne un tableau de pointeur vers les �l�ments composant la maille Fodo
        virtual Element* getmaille(unsigned int) const; //retourne un pointeur vers le i-1 �l�ment composant la maille Fodo
        double getlongueur_quadrupole() const;          //retourne la longueur des quadrup�les de la maille Fodo
        virtual Vecteur3D getchamps_magnetique(Particule const&) const; //retourne le champs magn�tique en fonction de la position de la particule

//--------prototypage des m�thodes set---------------------------------------------------------------------------

        void setlongueur_droit(double);            //permet de modifier la longueur des sections droites de la maille Fodo
        void setintensite(double);                 //permet de modifier l'intensit� du champ magn�tique de la maille Fodo
        virtual void setElement_suivant(Element&); //masquage de la fonctions permettant de d�signer l'�l�ment qui suit la maille Fodo

//--------prototypage des constructeurs/destructeur---------------------------------------------------------------

        Fodo();                                             //constructeur par d�faut qui initialise la maille (donc tous ses �l�ments) � 0
        Fodo(Vecteur3D, Vecteur3D, double, double, double); //constructeur qui prend en argument le vecteur d'entr�e, de sortie, le rayon, la longueur des sections droites et l'intensit� du champ magn�tique de la maille Fodo
        Fodo(Fodo const&);                                  //constructeur de copie (fait une copie profonde)
        virtual ~Fodo();                                    //destructeur

//--------prototypage des m�thodes--------------------------------------------------------------------------------

        bool heurte_bord(Particule const&) const; //masquage de la fonction qui d�termine si la particule � heurter le bord ou non
        virtual Fodo* copie() const;              //m�thode de copie polymorphique
        virtual void affiche(ostream&) const;     //m�thode polymorphique d'affichage des mailles Fodo

//--------prototypage des surcharges d'op�rateurs-----------------------------------------------------------------

        Fodo& operator=(Fodo const&); //surcharge de l'op�rateur = pour faire une copie profonde

    protected :

//--------d�finition des attributs-------------------------------------------------------------------------------

        double longueur_droit;
        double intensite;
        vector<Element*> maille;

//--------d�finition des statics---------------------------------------------------------------------------------

        static unsigned int taille;


};

//--------prototypage des surcharges externes--------------------------------------------------------------------

ostream& operator<<(ostream&, Fodo&);

#endif
