#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include "Vecteur3D.h"
#include "Particule.h"
using namespace std;

class Element
{
	protected :
	
	Vecteur3D re;					// position d'entrée.
	Vecteur3D rs;					// postition de sortie.
	double Re;						// Rayon de la chambre à vide.
	Element* Element_suivant;		// pointeur qui envoie sur l'element suivant.
	Vecteur3D getdirection() const;	// renvoie la direction d'un element
	static Vecteur3D e3;			// vecteur vertical unitaire
	
	
	Vecteur3D getpos_relative(Particule const&) const;  // fonction utile
	
	public :
	
	Element ();											// constructeur par défault sans arguments.
	Element (Vecteur3D, Vecteur3D, double);				// constructeur avec arguments.
	~Element();											// destructeur.
	
//---------------------------------------------------------------------------------------------------------
	
	Vecteur3D getre() const;					// méthodes get.
	Vecteur3D getrs() const;
	double getRe() const;
	Element* getElement_suivant() const;
	
	double getlongueur() const;					// renvoie la longueur de l'element droit
	
//---------------------------------------------------------------------------------------------------------
	
	void setre(Vecteur3D const&);				// méthodes set.
	void setrs(Vecteur3D const&);
	void setRe(double const&);
	void setElement_suivant(Element&);
	
//---------------------------------------------------------------------------------------------------------
	
	
	bool passe_suivant(Particule const&);		// revoie true si une particule passe à l'element suivant.

	virtual bool heurte_bord(Particule const&) const = 0; // méthode abstraite pure pour heurt_bord
	
};



//-------------------------------------------------------------------------------------------------------


class Droit : public Element 
{
	
	public :
	
	Droit();								// constructeur par défault sans argument
	Droit(Vecteur3D, Vecteur3D, double);	// constructeur avec arguments
	Droit(const Droit &);					// constructeur de copie
	~Droit();								// destructeur
	
	
//-------------------------------------------------------------------------------------------------------
	
	double getlongueur() const;
	
	virtual bool heurte_bord(Particule const&);  // renvoie true si une particule heurte un bord de l'element.
	
	
	
	
};



//-------------------------------------------------------------------------------------------------------



class Courbe : public Element 
{
	
	protected :
	
	
	Vecteur3D centre_courbure;		// centre de courbure
	double courbure;				// k : inverse du rayon de courbure
	
	
//---------------------------------------------------------------------------------------------------------

	
	public :

	
	Courbe();														// constructeur par défault sans arguments
	Courbe(Vecteur3D, Vecteur3D, double, double);					// constructeur avec arguments
	Courbe(const Courbe &);											// constructeur de copie
	~Courbe();														// destructeur
	
	
	
//---------------------------------------------------------------------------------------------------------

	
	Vecteur3D getcentre_courbure() const;			// méthodes get.
	double getcourbure() const;
	
	
//---------------------------------------------------------------------------------------------------------


	void setcourbure(double const&);				// méthode set

	
//---------------------------------------------------------------------------------------------------------

	
	virtual bool heurte_bord(Particule const&);  // renvoie true si une particule heurte un bord de l'element.
	
	
};

//---------------------------------------------------------------------------------------------------------

class Dessinable
{
	public :
	
	virtual void dessine(Element const&) const = 0;   // méthode abstraite pure : dessine un element.
	
};



#endif
