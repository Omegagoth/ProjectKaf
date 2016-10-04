#include "Droit.h"

using namespace std;

int main()
{
    Droit d1;
    Vecteur3D v1(1,0,0);
    Vecteur3D v2(0,-1,0);
    Droit d2(v1, v2, 0.1);

    d1 += d2;

    cout << "Droit 1 : " << endl
    << d1 << endl
    << "Droit 2 :" << endl
    << d2 << endl;

    cout << d1.getsuivant() << endl;


    return 0;
}
