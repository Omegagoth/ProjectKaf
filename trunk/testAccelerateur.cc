#include "Accelerateur.h"
#include <iostream>

using namespace std;

int main()
{
    Accelerateur a;
    Vecteur3D re(1,0,0);
    Vecteur3D rs(0,0,1);
    Dipole c(re,rs,1,2,2);
    Particule p;

    a.ajoute_particule(p);
    a.ajoute_element(c);

    cout << *a.getelements(1) << endl
    << *a.getparticules(1) << endl
    << a << endl;

    return 0;
}
