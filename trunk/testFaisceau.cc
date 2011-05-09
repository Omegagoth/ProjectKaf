#include <iostream>
#include "Faisceau.h"

using namespace std;



int main()
{
	Vecteur3D vP1(3.01, 0, 0);
    Vecteur3D vP2(2.99, 0, 0);
    Vecteur3D vv(0, -2.64754e+08, 0);
	
	Particule P1(vP1, 2, vv, 0.938272, 1.60217653e-19);
	Particule P2(vP2, 2, vv, 0.938272, 1.60217653e-19);
	
	Faisceau fa(P1, 2);
	
	fa.ajoute_Vpart(P1);
	fa.ajoute_Vpart(P2);
	cout << "reference : " << fa.getreference() << endl;
	cout << "nombre de particules : " << fa.getnb_particule() << endl;
	cout << "lambda : " << fa.getlambda() << endl;
	cout << "energie moyenne : " << fa.getenergie_moy() << endl;
	cout << "emittance verticale : " << fa.getemittancevert() << endl;
	
	
	return 0;
}


