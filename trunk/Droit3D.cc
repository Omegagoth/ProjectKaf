#include "Droit3D.h"



Droit3D::Droit3D()
: Droit()
{}

Droit3D::Droit3D(Vecteur3D entree, Vecteur3D sortie, double rayon)
: Droit(entree, sortie, rayon)
{}




void Droit3D::dessine() const
{
	glPushMatrix();
	
	GLUquadric* droit_ext=gluNewQuadric();
	GLUquadric* droit_int=gluNewQuadric();
	
	gluQuadricDrawStyle(droit_ext, GLU_FILL);
	gluQuadricDrawStyle(droit_int, GLU_FILL);
	
	glTranslated(re.getx(), re.gety(), re.getz());
	
	glRotated(90, (Vecteur3D(0,0,1)^getdirection()).getx(), (Vecteur3D(0,0,1)^getdirection()).gety(), (Vecteur3D(0,0,1)^getdirection()).getz());
	
	gluCylinder(droit_ext, rayon*100, 0, (re-rs).norme(), 20, 20);
	gluCylinder(droit_ext, rayon, 0, (re-rs).norme(), 20, 20);
	
	gluDeleteQuadric(droit_ext);
	gluDeleteQuadric(droit_int);
	
	glPopMatrix();
}

