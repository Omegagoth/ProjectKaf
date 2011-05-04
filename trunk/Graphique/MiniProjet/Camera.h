#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <cmath>
#include "wxIncludes"

using namespace std;

double const RAYON_DEFAUT(88);
double const PHI_DEFAUT(0.61);
double const THETA_DEFAUT(0.44);

class Camera
{
	public :
	
		double getRayon() const;
		double getPhi() const;
		double getTheta() const;
		
		void setRayon(double);
		void setPhi(double);
		void setTheta(double);
		void setVue();
		
		Camera(double, double, double);
	
	protected :

		double Rayon;
		double Phi;
		double Theta;
};



#endif


