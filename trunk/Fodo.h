#ifndef FODO_H
#define FODO_H

#include "Droit.h"
#include "Section_droite.h"
#include "Quadrupole.h"

class Fodo : public Droit
{
    public :

        double getlongueur_droit() const;
        double getintensite() const;

        void setlongueur_droit(double);
        void setintensite(double);
        virtual void setElement_suivant(Element&);

        Fodo();
        Fodo(Vecteur3D, Vecteur3D, double, double, double);
        Fodo(Fodo const&);
        virtual ~Fodo();

        bool heurte_bord(Particule const&) const;

    protected :

        double longueur_droit;
        double intensite;
        Element* maille[4];

        double getlongueur() const;

};



#endif
