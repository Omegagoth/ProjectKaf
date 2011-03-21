#include "Courbe.h"
#include <iostream>

using namespace std;

int main()
{
    Courbe c1;
    Vecteur3D v1(1,0,0);
    Vecteur3D v2(0,-1,0);
    Courbe c2(v1, v2, 0.1, 1);

    cout << "Courbe 1 :" << endl
    << c1 << endl;

    c1 += c2;

    cout << "Courbe 2 :" << endl
    << c2 << endl;
    cout << c1.getsuivant() << endl;

    return 0;
}
