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

    return 0;
}
