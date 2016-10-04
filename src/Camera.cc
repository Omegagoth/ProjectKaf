#include "Camera.h"
#include "Application.h"

#define RAYON_DEFAUT 8
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

Vecteur3D Camera::getPosition() const
{
	return position;
}

Vecteur3D Camera::getdirection() const
{
	return Vecteur3D(sin(Theta)*sin(Phi), sin(Theta)*cos(Phi), cos(Theta));
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

void Camera::setPosition(Vecteur3D p)
{
	position = p;
}




Camera::Camera(double r, double p, double t, Vecteur3D v)
: Rayon(r), Phi(p), Theta(t), position(v)
{}

Camera::Camera()
: Rayon(RAYON_DEFAUT), Phi(PHI_DEFAUT), Theta(THETA_DEFAUT), position(Vecteur3D(0,0,0))
{}

Camera::~Camera()
{}



void Camera::setVue()
{
	gluLookAt(position.getx() + Rayon*sin(Theta)*sin(Phi), position.gety() + Rayon*sin(Theta)*cos(Phi),
			  position.getz() + Rayon*cos(Theta), position.getx(), position.gety(), position.getz(), 0.0, 0.0, 1.0);
}

void Camera::resetVue()
{
	Rayon = RAYON_DEFAUT;
	Phi = PHI_DEFAUT;
	Theta = THETA_DEFAUT;
	position = Vecteur3D(0,0,0);
}

Camera* Camera::copie() const
{
	return new Camera(*this);
}






CameraSuivre::CameraSuivre()
: Camera(0,0,0,Vecteur3D(0,0,0)), suivre(1)
{
	resetVue();
}

CameraSuivre::CameraSuivre(unsigned int i)
: Camera(0,0,0,Vecteur3D(0,0,0)), suivre(i), Phi_mouvement(0), Theta_mouvement(0)
{
	resetVue();
}

CameraSuivre::~CameraSuivre()
{}



void CameraSuivre::setVue()
{
	if(wxGetApp().getaccelerateur()->getparticules().size() >= suivre)
	{
		position = wxGetApp().getaccelerateur()->getparticules(suivre)->getposition();
		calcule_camera();
	}
	else
	{
		Camera::resetVue();
	}
	Camera::setVue();
	
}

void CameraSuivre::resetVue()
{
	if(wxGetApp().getaccelerateur()->getparticules().size() >= suivre)
	{
		Rayon = wxGetApp().getaccelerateur()->getparticules(suivre)->getappartient()->getRe();
		
		calcule_camera();
	}
	else
	{
		Camera::resetVue();
	}
	Camera::setVue();
}

CameraSuivre* CameraSuivre::copie() const
{
	return new CameraSuivre(*this);
}

void CameraSuivre::calcule_camera()
{
	Theta -= Theta_mouvement;
	Phi -= Phi_mouvement;
	
	Vecteur3D a(~(wxGetApp().getaccelerateur()->getparticules(suivre)->getvitesse()));
	
	position = wxGetApp().getaccelerateur()->getparticules(suivre)->getposition()
				- wxGetApp().getaccelerateur()->getparticules(suivre)->getappartient()->getRe()*a;
	
	Theta_mouvement = acos(a.getz()/Rayon);
	Phi_mouvement = acos(a.getx()/sqrt(a.getx()*a.getx()+a.gety()*a.gety()));
	if(a.gety() > 0)
	{
		Phi_mouvement *= -1;
	}
	Phi_mouvement -= M_PI/2;
	
	Phi += Phi_mouvement;
	Theta += Theta_mouvement;
}


