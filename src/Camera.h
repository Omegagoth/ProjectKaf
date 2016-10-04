#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <cmath>
#include "wxIncludes.h"
#include "Vecteur3D.h"

enum Vue {Libre, Suivre};

using namespace std;

class Camera
{
	public :
	
		double getRayon() const;
		double getPhi() const;
		double getTheta() const;
		Vecteur3D getPosition() const;
		Vecteur3D getdirection() const;
		
		void setRayon(double);
		void setPhi(double);
		void setTheta(double);
		void setPosition(Vecteur3D);
		
		Camera(double, double, double, Vecteur3D v = Vecteur3D(0,0,0));
		Camera();
		virtual ~Camera();
		
		virtual void setVue();
		virtual void resetVue();
		virtual Camera* copie() const;
	
	protected :

		double Rayon;
		double Phi;
		double Theta;
		Vecteur3D position;
};



class CameraSuivre : public Camera
{
	public :
	
		unsigned int getsuivre() const;
		void setsuivre(unsigned int);
	
		CameraSuivre();
		CameraSuivre(unsigned int);
		virtual ~CameraSuivre();
		
		virtual void setVue();
		virtual void resetVue();
		virtual CameraSuivre* copie() const;
		void calcule_camera();
		
	protected :
		
		unsigned int suivre;
		double Phi_mouvement;
		double Theta_mouvement;
		
};




#endif


