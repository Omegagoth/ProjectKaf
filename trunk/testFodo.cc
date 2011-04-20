#include "Fodo.h"

using namespace std;

int main()
{
    Vecteur3D re(1,0,0);
    Vecteur3D rs(-1,0,0);
    Vecteur3D p;
    double Re(.1);
    double l(.5);
    double i(2);

    Particule p1(p, Vecteur3D(2e8,0,0), 12, 1e-9);

    Fodo f(re,rs,Re,l,i);
    Fodo f2;

    p1.setappartient(f);

    cout << f << endl
    << f2 << endl;

    cout << "Touche? " << p1.getappartient()->heurte_bord(p1) << endl
    << "Passe? " << p1.getappartient()->passe_suivant(p1) << endl;

    cout << p1.getappartient() << endl;

    Fodo f3(f);

    cout << f3 << endl;

    return 0;
}
