#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H

#include <iostream>
#include <vector>
#include "Particule.h"
#include "Element.h"

using namespace std;

class Accelerateur
{
    public :

        //prototypage des m�thodes get
        vector<Particule> getparticules() const; //donne l'ensemble des particules de l'acc�l�rateur sous forme de vector
        Particule getparticule(unsigned int) const; //donne la i�me particule de l'acc�l�rateur
        vector<Element> getelements() const; //donne l'ensemble des �l�ments de l'acc�l�rateur sous forme de vector
        Element getelement(unsigned int) const; //donne le i�me �l�ment de l'acc�l�rateur

//---------------------------------------------------------------------------------------------------------------

        //prototypage des constructeurs
        Accelerateur(); //constructeur par d�faut qui initialise � vide

//---------------------------------------------------------------------------------------------------------------

        //prototypage des m�thodes
        void ajoute_particule(Particule const&); //m�thode permettant de rajouter une particule � l'acc�l�rateur
        void ajoute_element(Element const&); //m�thode permettant de rajouter un �l�ment � l'acc�l�rateur
        Accelerateur& clear_particules(); //m�thode permettant de supprimer toutes les particules de l'acc�l�rateur
        Accelerateur& clear_elements(); //m�thode permettant de supprimer tout les �lements de l'acc�l�rateur

//---------------------------------------------------------------------------------------------------------------

    protected :

        //d�finition des attributs
        vector<Particule> particules; //stockage des diff�rentes particules dans un tableau a taille variable
        vector<Element> elements; //stockage des diff�rents �lements de l'acc�lerateur dans un tableau a taille variable

//---------------------------------------------------------------------------------------------------------------

        //prototypage des constructeurs/surcharges priv�e
        Accelerateur(Accelerateur const&); //constructeur de copie qui ne fait rien
        Accelerateur& operator=(Accelerateur const&); //surcharge de l'op�rateur = qui ne fait rien

};

//---------------------------------------------------------------------------------------------------------------

//surcharge externe
ostream& operator<<(ostream&, Accelerateur const&); //surcharge de l'op�rateur << permettant l'affichage dans le terminale





#endif
