#include "Particule.h"
#include <iostream>

int main()
{
    Vecteur3D x2(3.00984, -0.391837, 0);
    Vecteur3D x3(2.99016, -0.391837, 0);
    Vecteur3D d(0,0,0);
    Vecteur3D p(1,0,0);
    Vecteur3D B(0,0,7);
    double dt(1e-11);

    Particule p1;
    Particule p2(x2, 2, d, 0.938272, 1.60217653e-19);
    Particule p3(x3, 2, d, 0.938272, 1.60217653e-19);
    p3.ajoute_forcemagn(B,dt);

    cout << p1 << endl
    << p2 << endl
    << p3 << endl;

    p3.bouger(1e-11);

    cout << p3 ;

    return 0;
}
