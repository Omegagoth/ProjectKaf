#include <iostream>
#include "Accelerateur.h"

using namespace std;


int main()
{
    Vecteur3D v1(3,2,0);
    Vecteur3D v2(3,1,0);
    Vecteur3D v3(3,0,0);
    Vecteur3D v4(3,-1,0);
    Vecteur3D v5(3,-2,0);
    Vecteur3D v6(2,-3,0);
    Vecteur3D v7(1,-3,0);
    Vecteur3D v8(0,-3,0);
    Vecteur3D v9(-1,-3,0);
    Vecteur3D v10(-2,-3,0);
    Vecteur3D v11(-3,-2,0);
    Vecteur3D v12(-3,-1,0);
    Vecteur3D v13(-3,0,0);
    Vecteur3D v14(-3,1,0);
    Vecteur3D v15(-3,2,0);
    Vecteur3D v16(-2,3,0);
    Vecteur3D v17(-1,3,0);
    Vecteur3D v18(0,3,0);
    Vecteur3D v19(1,3,0);
    Vecteur3D v20(2,3,0);

    Vecteur3D vP1(3.01, 0, 0);
    Vecteur3D vP2(2.99, 0, 0);
    Vecteur3D vv(0, -2.64754e+08, 0);

	Accelerateur acc;
	Fodo F1(v1, v5, 0.1, 1, 1.2);
	/*Quadrupole Q1(v1, v2, 0.1, 1.2);
	Section_droite S1(v2, v3, 0.1);
	Quadrupole Q2(v3, v4, 0.1, -1.2);
	Section_droite S2(v4, v5, 0.1);*/
	Dipole D1(v5, v6, 0.1, 1, 5.89158);
	Fodo F2(v6, v10, 0.1, 1, 1.2);
	/*Quadrupole Q3(v6, v7, 0.1, 1.2);
	Section_droite S3(v7, v8, 0.1);
	Quadrupole Q4(v8, v9, 0.1, -1.2);
	Section_droite S4(v9, v10, 0.1);*/
	Dipole D2(v10, v11, 0.1, 1, 5.89158);
	Fodo F3(v11, v15, 0.1, 1, 1.2);
	/*Quadrupole Q5(v11, v12, 0.1, 1.2);
	Section_droite S5(v12, v13, 0.1);
	Quadrupole Q6(v13, v14, 0.1, -1.2);
	Section_droite S6(v14, v15, 0.1);*/
	Dipole D3(v15, v16, 0.1, 1, 5.89158);
	Fodo F4(v16, v20, 0.1, 1, 1.2);
	/*Quadrupole Q7(v16, v17, 0.1, 1.2);
	Section_droite S7(v17, v18, 0.1);
	Quadrupole Q8(v18, v19, 0.1, -1.2);
	Section_droite S8(v19, v20, 0.1);*/
	Dipole D4(v20, v1, 0.1, 1, 5.89158);


	/*acc.ajoute_element(Q1);
	acc.ajoute_element(S1);
	acc.ajoute_element(Q2);
	acc.ajoute_element(S2);*/

	acc.ajoute_element(F1);

	cout << "coucou" << endl;

	cout << acc.getelements(1) << endl;

	acc.ajoute_element(D1);
	/*acc.ajoute_element(Q3);
	acc.ajoute_element(S3);
	acc.ajoute_element(Q4);
	acc.ajoute_element(S4);*/
	acc.ajoute_element(F2);
	acc.ajoute_element(D2);
	/*acc.ajoute_element(Q5);
	acc.ajoute_element(S5);
	acc.ajoute_element(Q6);
	acc.ajoute_element(S6);*/
	acc.ajoute_element(F3);
	acc.ajoute_element(D3);
	/*acc.ajoute_element(Q7);
	acc.ajoute_element(S7);
	acc.ajoute_element(Q8);
	acc.ajoute_element(S8);*/
	acc.ajoute_element(F4);
	acc.ajoute_element(D4);

	Particule P1(vP1, 2, vv, 0.938272, 1.60217653e-19);
	Particule P2(vP2, 2, vv, 0.938272, 1.60217653e-19);

	acc.ajoute_particule(P1);
	acc.ajoute_particule(P2);

	cout << acc << endl;

	cout << "Touche le bord "<< acc.getelements(8)->heurte_bord(P1) << endl
	<< "Sortie? " << acc.getelements(8)->passe_suivant(P1) << endl;

	acc.affecte_element();

	cout << "Avant" << endl << endl;

	for (int unsigned i(1); i <= acc.getparticules().size(); ++i)
	{
	    cout << *acc.getparticules(i) << endl
	    << *(acc.getparticules(i)->getappartient()) << endl;
	}

	for (int unsigned i(0); i < 20; ++i)
	{
		acc.evolue(1e-11);

		cout << "AprËs" << endl << endl;

		for (int unsigned i(1); i <= acc.getparticules().size(); ++i)
		{
			cout << *acc.getparticules(i) << endl
			<< *(acc.getparticules(i)->getappartient()) << endl;
		}
	}
	return 0;
}


