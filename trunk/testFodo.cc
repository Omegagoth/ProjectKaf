#include "Fodo.h"

using namespace std;

int main()
{
    Vecteur3D re(1,0,0);
    Vecteur3D rs(0,1,0);
    double Re(1);
    double l(.5);
    double i(2);

    Fodo f(re,rs,Re,l,i);
    Fodo f2;

    cout << f << endl;
    /*cout << f.getElement_suivant() << endl
    << f.getre() << endl
    << f.getrs() << endl
    << f.getRe() << endl
    << (f.getmaille(0)) << endl
    << (f.getmaille(1)) << endl
    << (f.getmaille(2)) << endl
    << (f.getmaille(3)) << endl;

    cout << f2.getElement_suivant() << endl
    << f2.getre() << endl
    << f2.getrs() << endl
    << f2.getRe() << endl
    << f2.getmaille(0) << endl;*/
    /*<< f2.getmaille(1) << endl
    << f2.getmaille(2) << endl
    << f2.getmaille(3) << endl;*/

    return 0;
}
