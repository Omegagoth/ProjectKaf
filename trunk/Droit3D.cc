#include "Droit3D.h"



Droit3D::Droit3D()
: Droit(Vecteur3D(0,10,0), Vecteur3D(0,0,1), 0.1)
{}

Droit3D::Droit3D(Vecteur3D entree, Vecteur3D sortie, double rayon)
: Droit(entree, sortie, rayon)
{}




void Droit3D::dessine() const
{
	glPushMatrix();
	
	GLUquadric* droit_ext=gluNewQuadric();
	GLUquadric* droit_int=gluNewQuadric();
	
	gluQuadricDrawStyle(droit_ext, GLU_LINE);
	gluQuadricDrawStyle(droit_int, GLU_FILL);
	
	glTranslated(10, re.gety(), re.getz());
	
	glRotated(90, (Vecteur3D(0,0,1)^getdirection()).getx(), (Vecteur3D(0,0,1)^getdirection()).gety(), (Vecteur3D(0,0,1)^getdirection()).getz());
	
	glColor4d(1.0,0,1.0,0.5);
	gluCylinder(droit_ext, Re*10, Re*10, (re-rs).norme(), 20, 20);
	
	glColor3i(255,0,0);
	gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
	
	gluDeleteQuadric(droit_ext);
	gluDeleteQuadric(droit_int);
	
	glPopMatrix();
}

