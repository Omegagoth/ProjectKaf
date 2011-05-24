#include "Droit3D.h"




Droit3D::Droit3D()
: Element(), Element3D(), Droit()
{}

Droit3D::Droit3D(Vecteur3D re, Vecteur3D rs, double R, unsigned int r, unsigned int v, unsigned int b, unsigned int t)
: Element(), Element3D(re,rs,R,r,v,b,t), Droit(re,rs,R)
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
	
	gluQuadricDrawStyle(droit_ext, GLU_LINE);
	
	glTranslated(re.getx(), re.gety(), re.getz());
	
	glRotated(90-angle,0,0,1);
	glRotated(90,1,0,0);

	
	glColor4ub(couleurs.getrouge(), couleurs.getvert(), couleurs.getbleu(), couleurs.gettransparence());
	gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
	
	gluDeleteQuadric(droit_ext);
	
	glPopMatrix();
}

