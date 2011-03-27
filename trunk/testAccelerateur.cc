#include "Accelerateur.h"
#include <iostream>

using namespace std;

int main()
{
    Accelerateur a;
    Vecteur3D re(1,0,0);
    Vecteur3D rs(0,0,1);
    Courbe c(re,rs,1,2);
    Particule p;

    a.ajoute_particule(p);
    a.ajoute_element(c);

    cout << a.getelement(1) << endl
    << a.getparticule(1) << endl
    << a << endl;

    return 0;
}
