#include "Vecteur3D.h"
#include <iostream>

using namespace std;

int main()
{
    Vecteur3D v1(1,2,3);
    Vecteur3D v2(2,3,1);
    Vecteur3D v3;
    Vecteur3D v4(0,0,1);

    v3 = v1;

    cout << "Vecteur 1 :" << endl;
    cout << v1 << endl;
    cout << "Vecteur 2 :" << endl;
    cout << v2 << endl;
    cout << "Vecteur 3 :" << endl;
    cout << v3 << endl;

    if (v1 == v2) cout << "Egale" << endl;
    else cout << "Différent" << endl;
    if (v2 == v1) cout << "Egale" << endl;
    else cout << "Différent" << endl;
    if (v1 == v3) cout << "Egale" << endl;
    else cout << "Différent" << endl;

    Vecteur3D a;
    Vecteur3D a1;
    Vecteur3D b;
    Vecteur3D c;
    Vecteur3D c1;
    Vecteur3D d;
    double e;
    Vecteur3D f;
    double g;
    double h;
    Vecteur3D i;
    Vecteur3D j;

    a1 = v1 + v2;
    a = a1;
    a += v2;
    b = v1 - v2;
    c = 3*v1;
    c1 = v1*3;
    d = -v1;
    e = v1*v2;
    f = v1^v2;
    g = v1.norme_carre();
    h = prod_mixte(v1,v2,v3);
    i = ~v1;
    j = v1.rotation(v4,1.5);

   cout << a << endl
   << a1 << endl
   << b << endl
   << c << endl
   << c1 << endl
   << d << endl
   << e << endl
   << f << endl
   << g << endl
   << h << endl
   << i << endl
   << i.norme_carre() << endl
   << j << endl;

    return 0;
}
