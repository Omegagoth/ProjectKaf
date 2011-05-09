#include "Particule3D.h"



Particule3D::Particule3D()
: Particule()
{}

Particule3D::Particule3D(Vecteur3D position, Vecteur3D quantite_mouv, double masse, double charge)
: Particule(position, quantite_mouv, masse, charge)
{}

Particule3D::Particule3D(Vecteur3D position, double energie, Vecteur3D vitesse, double masse, double charge)
: Particule(position, energie, vistesse, masse, charge)
{}

void Particule3D::dessine() const
{
	glPushMatrix();
	
	glBegin(GL_POINTS);
	
	glPointSize(10);
	
	glVertex3d(position.getx(), position.gety(), position.getz());
	
	glEnd();
	
	glPopMatrix();
}


