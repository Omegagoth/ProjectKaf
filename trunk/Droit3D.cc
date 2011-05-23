#include "Droit3D.h"




Droit3D::Droit3D()
: Element3D(), Droit(Vecteur3D(1,1,0), Vecteur3D(1,0,0), 0.1)
{}

Droit3D::Droit3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r = 255, unsigned int v = 255, unsigned int b = 255, unsigned int t = 255)
: Element3D(re,rs,R,r,v,b,t), Droit(re,rs,R)
{}

Droit3D::Droit3D(Droit3D const& d)
: Element(d), Element3D(d), Droit(d)
{}

Droit3D::~Droit3D()
{}




void Droit3D::dessine() const
{
	glPushMatrix();
	Vecteur3D e1(1,0,0);
	double angle(getdirection().angle(e1)*180/M_PI);
	
	GLUquadric* droit_ext=gluNewQuadric();
	GLUquadric* droit_int=gluNewQuadric();
	
	gluQuadricDrawStyle(droit_ext, GLU_LINE);
	gluQuadricDrawStyle(droit_int, GLU_FILL);
	
	glTranslated(re.getx(), re.gety(), re.getz());
	
	glRotated(90-angle,0,0,1);
	glRotated(90,1,0,0);
	
	glColor4d(1.0,1.0,1.0,0.5);
	//gluCylinder(droit_ext, Re*10, Re, (re-rs).norme(), 20, 20);
	
	glColor4d(1.0,0,0,1.0);
	gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
	
	gluDeleteQuadric(droit_ext);
	gluDeleteQuadric(droit_int);
	
	glPopMatrix();
}

