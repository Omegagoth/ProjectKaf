#include <iostream>
#include "Faccelerateur.h"

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
	
	Faccelerateur acc;
	Fodo3D F1(v1, v5, 0.1, 1, 1.2);
	Dipole3D D1(v5, v6, 0.1, 1, 5.89158);
	Fodo3D F2(v6, v10, 0.1, 1, 1.2);
	Dipole3D D2(v10, v11, 0.1, 1, 5.89158);
	Fodo3D F3(v11, v15, 0.1, 1, 1.2);
	Dipole3D D3(v15, v16, 0.1, 1, 5.89158);
	Fodo3D F4(v16, v20, 0.1, 1, 1.2);
	Dipole3D D4(v20, v1, 0.1, 1, 5.89158);
	
	
	acc.ajoute_element(F1);
	acc.ajoute_element(D1);
	acc.ajoute_element(F2);
	acc.ajoute_element(D2);
	acc.ajoute_element(F3);
	acc.ajoute_element(D3);
	acc.ajoute_element(F4);
	acc.ajoute_element(D4);
	
	
	Particule3D P1(vP1, 2, vv, 0.938272, 1.60217653e-19);
	Particule3D P2(vP2, 2, vv, 0.938272, 1.60217653e-19);
	
	
	acc.ajoute_faisceau(50, P1, 1);
	acc.ajoute_faisceau(60, P2, 1);
	
	
	acc.affecte_element();
	
	cout << acc.getfaisceaux()[0]->getVpart().size() << endl;
	cout << "Avant" << endl << endl;
	
	for (int unsigned i(0); i < acc.getfaisceaux().size(); ++i)
	{
	    cout << *acc.getfaisceaux()[i] << endl
	    << *(acc.getfaisceaux()[i]->getVpart()[0]->getappartient()) << endl;
	}
	
	cout << "apres : " << endl << endl << endl;
	
	int n(0);
	int nb(0);
	
	for (int i(0); i<50; i++)
	{
		for (int j(0); j<200; j++)
		{
			acc.evolue(1e-11);
			n++;
			
		}												// fait tourner les particules
		
		do
		{
			n +=1;
			acc.evolue(1e-11);
		}
		while ((acc.getfaisceaux()[0]->getVpart().size() != 0 && (acc.getfaisceaux()[0]->getVpart()[0]->getposition().getx() < 0 || acc.getfaisceaux()[0]->getVpart()[0]->getposition().gety() > 0
			   || acc.getfaisceaux()[0]->getVpart()[0]->getposition().gety() < -0.1))
			   && (acc.getfaisceaux()[1]->getVpart().size() != 0 && (acc.getfaisceaux()[1]->getVpart()[0]->getposition().getx() < 0 || acc.getfaisceaux()[1]->getVpart()[0]->getposition().gety() > 0
			   || acc.getfaisceaux()[1]->getVpart()[0]->getposition().gety() < -0.1)));
		
		nb++;
	}
	cout << "salut" << endl;
	cout << "Nombre d'iteration " << n << endl
	<< "Nombre de tour " << nb << endl << endl << endl;
	
	cout << "AprËs" << endl << endl;
	
	cout << *(acc.getfaisceaux()[0]);		// affiche le faisceau apres la simulation
	cout << *(acc.getfaisceaux()[1]);

	return 0;
}




