#include "Ciel.h"
#include "Application.h"

double Ciel::getVitesse() const
{
	return vitesse;
}

double Ciel::getAngle() const
{
	return angle_actuel;
}

string Ciel::getTexture() const
{
	return texture;
}


void Ciel::setVitesse(double v)
{
	vitesse = v;
}

void Ciel::setAngle(double a)
{
	angle_actuel = a;
}

void Ciel::setTexture(string t)
{
	texture = t;
}

Ciel::Ciel()
: vitesse(0), angle_actuel(0), texture("texture/IC5146.jpg")
{}

void Ciel::rotation()
{
	angle_actuel += vitesse;
}

void Ciel::dessine()
{
	glPushMatrix();
	
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture(texture));
	
	GLUquadric* ciel = gluNewQuadric();
	
	gluQuadricDrawStyle(ciel, GLU_FILL);
	gluQuadricTexture(ciel, GLU_TRUE);
	
	glRotated(angle_actuel, 0, 0, 1);
	
	gluSphere(ciel, 200, 30,30);
	
	gluDeleteQuadric(ciel);
	
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

