#include "Droit3D.h"



Droit3D::Droit3D()
: Droit(Vecteur3D(-3,1,0), Vecteur3D(-3,2,0), 0.1)
{}

Droit3D::Droit3D(Vecteur3D entree, Vecteur3D sortie, double rayon)
: Droit(entree, sortie, rayon)
{}




void Droit3D::dessine() const
{
	glPushMatrix();
	
	Vecteur3D e1(1,0,0);
	double angle(acos(getdirection()*e1)*180/M_PI);
	
	GLUquadric* droit_ext=gluNewQuadric();
	GLUquadric* droit_int=gluNewQuadric();
	
	gluQuadricDrawStyle(droit_ext, GLU_LINE);
	gluQuadricDrawStyle(droit_int, GLU_FILL);
	
	glTranslated(re.getx(), re.gety(), re.getz());
	
	//cout << -getdirection().gety()/abs(getdirection().gety()) << endl;
	
	glRotated(90-angle, 0,0,-getdirection().gety()/abs(getdirection().gety())*1);
	glRotated(90, -getdirection().gety()/abs(getdirection().gety())*1,0,0);
	
	glColor4d(1.0,0,1.0,0.5);
	gluCylinder(droit_ext, Re*10, Re*10, (re-rs).norme(), 20, 20);
	
	glColor4d(1.0,0,0,1.0);
	gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
	
	gluDeleteQuadric(droit_ext);
	gluDeleteQuadric(droit_int);
	
	glPopMatrix();
}

