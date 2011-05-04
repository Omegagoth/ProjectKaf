#include "Camera.h"

double Camera::getRayon() const
{
	return Rayon;
}

double Camera::getPhi() const
{
	return Phi;
}

double Camera::getTheta() const
{
	return Theta;
}




void Camera::setRayon(double r)
{
	Rayon = r;
}

void Camera::setPhi(double p)
{
	Phi = p;
}

void Camera::setTheta(double t)
{
	Theta = t;
}

void Camera::setVue()
{
	gluLookAt(Rayon*sin(Theta)*sin(Phi), Rayon*sin(Theta)*cos(Phi), Rayon*cos(Theta), 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}




Camera::Camera(double r, double p = PHI_DEFAUT, double t = THETA_DEFAUT)
: Rayon(r), Phi(p), Theta(t)
{}



