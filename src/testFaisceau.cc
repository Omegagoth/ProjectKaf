#include <iostream>
#include "Faisceau.h"
#include "Quadrupole.h"
#include "Particule.h"

using namespace std;



int main()
{
	Vecteur3D vP1(3.01, 0, 0);
    Vecteur3D vP2(2.99, 0, 0);
    Vecteur3D vv(0, -2.64754e+08, 0);
	Vecteur3D v1(3,2,0);
    Vecteur3D v2(3,1,0);

	
	Quadrupole Q1(v1, v2, 0.1, 1.2);
	
	Particule P1(vP1, 2, vv, 0.938272, 1.60217653e-19);
	Particule P2(vP2, 2, vv, 0.938272, 1.60217653e-19);
	
	P1.setappartient(Q1);
	P2.setappartient(Q1);
	
	Faisceau fa(P1, 2);
	
	fa.ajoute_Vpart(P1);
	fa.ajoute_Vpart(P2);
	cout << "reference : " << fa.getreference() << endl;
	cout << "nombre de particules : " << fa.getnb_particule() << endl;
	cout << "lambda : " << fa.getlambda() << endl;
	cout << "energie moyenne : " << fa.getenergie_moy() << endl;
	cout << "emittance verticale : " << fa.getemittancevert() << endl;
	cout << "emittance horizontale : " << fa.getemittancehori() << endl;
	cout << "A11 vertical : " << fa.getA11vert() << endl;
	cout << "A12 vertical : " << fa.getA12vert() << endl;
	cout << "A22 vertical : " << fa.getA22vert() << endl;
	cout << "A11 horizontal : " << fa.getA11hori() << endl;
	cout << "A12 horizontal : " << fa.getA12hori() << endl;
	cout << "A22 horizontal : " << fa.getA22hori() << endl;
	
	
	
	return 0;
}


