#include "Element.h"
#include <iostream>

using namespace std;

int main()
{
    Element e1;
    Vecteur3D v1(1,0,0);
    Vecteur3D v2(0,-1,0);
    Element e2(v1, v2, 0.1);

    cout << "Elément 1 :" << endl
    << e1 << endl;

    cout << "Elément 2 :" << endl
    << e2 << endl;

    return 0;
}
