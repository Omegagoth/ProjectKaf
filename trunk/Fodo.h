#ifndef FODO_H
#define FODO_H

#include "Section_droite.h"
#include "Quadrupole.h"

class Fodo
{
    public :

        Fodo();
        Fodo(Vecteur3D, Vecteur3D, double, double, double);
        Fodo(Fodo const&);
        virtual ~Fodo();

    protected :

        double longueur;
        double intensite;

}



#endif
