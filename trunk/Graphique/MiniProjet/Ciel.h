#ifndef CIEL_H
#define CIEL_H

#include "wxIncludes"
#include "TextureManager.h"
#include <string>

using namespace std;

class Ciel
{
	public:
	
		double getVitesse() const;
		double getAngle() const;
		string getTexture() const;
		
		void setVitesse(double);
		void setAngle(double);
		void setTexture(string);
		
		Ciel();
		
		void rotation();
		void dessine();
	
	protected:
	
		double vitesse;
		double angle_actuel;
		string texture;
	
};


#endif

