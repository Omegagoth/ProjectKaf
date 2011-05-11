#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <cmath>
#include "wxIncludes.h"

using namespace std;

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
		Camera();
		
		void resetVue();
	
	protected :

		double Rayon;
		double Phi;
		double Theta;
};



#endif


