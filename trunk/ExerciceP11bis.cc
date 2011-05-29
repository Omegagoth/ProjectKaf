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
    Vecteur3D vv(0, -2.64754e+08, 0);		// initialisation des vecteurs

	Accelerateur acc;
	Fodo F1(v1, v5, 0.1, 1, 1.2);
	Dipole D1(v5, v6, 0.1, 1, 5.89158);
	Fodo F2(v6, v10, 0.1, 1, 1.2);
	Dipole D2(v10, v11, 0.1, 1, 5.89158);
	Fodo F3(v11, v15, 0.1, 1, 1.2);
	Dipole D3(v15, v16, 0.1, 1, 5.89158);
	Fodo F4(v16, v20, 0.1, 1, 1.2);
	Dipole D4(v20, v1, 0.1, 1, 5.89158);	//initialise les elements


	acc.ajoute_element(F1);					
	acc.ajoute_element(D1);
	acc.ajoute_element(F2);
	acc.ajoute_element(D2);
	acc.ajoute_element(F3);
	acc.ajoute_element(D3);
	acc.ajoute_element(F4);
	acc.ajoute_element(D4);					// ajoute les elements a l'accelerateur

	Particule P1(vP1, 2, vv, 0.938272, 1.60217653e-19);
	Particule P2(vP2, 2, vv, 0.938272, 1.60217653e-19);		//initialise les particules

	acc.ajoute_particule(P1);
	acc.ajoute_particule(P2);				// ajoute les particules dans l'accelerateur
	

	cout << acc << endl;					// affiche l'accelerateur avant la simulation


	acc.affecte_element();					// affecte chaque particule a un element

	cout << "Avant" << endl << endl;

	for (int unsigned i(1); i <= acc.getparticules().size(); ++i)
	{
	    cout << *acc.getparticules(i) << endl
	    << *(acc.getparticules(i)->getappartient()) << endl;		// affiche chaque particule a quel element elle appartient
	}
	int n(0);
	int nb(0);
	for (int i(0); i<75; i++)
	{
		for (int j(0); j<752; j++)
		{
			acc.evolue(1e-11);
			n++;
		}									// fait tourner les particules

 
		do
		{
			n +=1;
			acc.evolue(1e-11);
		}
		while (acc.getparticules(1)->getposition().getx() < 0 || acc.getparticules(1)->getposition().gety() > 0
		|| acc.getparticules(1)->getposition().gety() < -0.1);
		
		nb++;
	}

	cout << "Nombre d'iteration " << n << endl
	<< "Nombre de tour " << nb << endl << endl << endl;

	cout << "Apres" << endl << endl;

	for (int unsigned i(1); i <= acc.getparticules().size(); ++i)
	{
		cout << *acc.getparticules(i) << endl
		<< *(acc.getparticules(i)->getappartient()) << endl;		
    }					
	return 0;								// affiche chaque particule a quel element elle appartient
}


