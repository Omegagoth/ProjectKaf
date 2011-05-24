#include "Particule3D.h"



Particule3D::Particule3D()
: Particule()
{}

Particule3D::Particule3D(Vecteur3D position, Vecteur3D quantite_mouv, double masse, double charge)
: Particule(position, quantite_mouv, masse, charge)
{}

Particule3D::Particule3D(Vecteur3D position, double energie, Vecteur3D vitesse, double masse, double charge)
: Particule(position, energie, vitesse, masse, charge)
{}

Particule3D::Particule3D(Particule3D const& p)
: Particule(p)
{}

Particule3D::~Particule3D()
{}

void Particule3D::dessine() const
{
	glPushMatrix();
	
	GLUquadric* particule = gluNewQuadric();
	
	glTranslated(position.getx(), position.gety(), position.getz());
	
	gluQuadricDrawStyle(particule, GLU_FILL);
	
	gluSphere(particule, .05, 5,5);
	
	gluDeleteQuadric(particule);
	
	glPopMatrix();
}


