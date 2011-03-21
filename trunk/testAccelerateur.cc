#include "Accelerateur.h"
#include <iostream>

using namespace std;

int main()
{
    Accelerateur a;
    Element e;
    Particule p;

    a.ajoute_particule(p);
    a.ajoute_element(e);

    cout << a.getelement(1) << endl
    << a.getparticule(1) << endl
    << a << endl;

    return 0;
}
