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

    c1.setElement_suivant(c2);

    cout << "Courbe 2 :" << endl
    << c2 << endl;
    cout << *c1.getElement_suivant() << endl;
    
    Courbe c(Vecteur3D(1,1,0), Vecteur3D(1,0,0), 0.1, 1./5);
    cout << c << endl
    << c.getangle() << endl;
    cout << "Avant transformation " << c.getre()-c.getcentre() << endl
    << "Apres trsf " << (c.getre()-c.getcentre()).rotation(Vecteur3D(0,0,1), 2*c.getangle()/4) << endl;

    return 0;
}
