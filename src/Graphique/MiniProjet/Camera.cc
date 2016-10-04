#include "Camera.h"

#define RAYON_DEFAUT 88
#define PHI_DEFAUT 0.61
#define THETA_DEFAUT 0.44

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




Camera::Camera(double r, double p, double t)
: Rayon(r), Phi(p), Theta(t)
{}

Camera::Camera()
: Rayon(RAYON_DEFAUT), Phi(PHI_DEFAUT), Theta(THETA_DEFAUT)
{}

void Camera::resetVue()
{
	Rayon = RAYON_DEFAUT;
	Phi = PHI_DEFAUT;
	Theta = THETA_DEFAUT;
}


