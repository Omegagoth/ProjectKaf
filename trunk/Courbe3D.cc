#include "Courbe3D.h"





Courbe3D::Courbe3D()
: Courbe(Vecteur3D(1,1,0), Vecteur3D(1,0,0), 0.1, 1./5)
{}

Courbe3D::Courbe3D(Vecteur3D re, Vecteur3D rs, double R, double k)
: Courbe(re, rs, R, k)
{}

Courbe3D::~Courbe3D()
{}





void Courbe3D::dessine() const //pour l'instant c'est le même que droit car je sais pas comment faire un tore
{
	glPushMatrix();
cout << "Debut" << endl;
	Vecteur3D e1(1,0,0); cout << re << "	" << getcentre() << endl;
	Vecteur3D position(re-getcentre());
	Vecteur3D tampon(0,0,0);
	Vecteur3D corde(0,0,0);
	double angle(0);
	
	
	
	/*glTranslated((re-getcentre()).getx(), (re-getcentre()).gety(), (re-getcentre()).getz());
	
	glTranslated(getcentre().getx(), getcentre().gety(), getcentre().getz());
	
	glRotated(90-angle,0,0,1);
	glRotated(90,1,0,0);
	
	glRotated(-90,0,1,0);*/
	
	glTranslated(getcentre().getx(), getcentre().gety(), getcentre().getz());
	
	/*for (int i(1); i<5; i++)
	{cout << "				Et de " << i << endl;*/
		glPushMatrix();
		
		GLUquadric* droit_ext=gluNewQuadric();
		GLUquadric* droit_int=gluNewQuadric();
		
		gluQuadricDrawStyle(droit_ext, GLU_LINE);
		gluQuadricDrawStyle(droit_int, GLU_FILL);
		
		glTranslated(position.getx(), position.gety(), position.getz());
		
		cout << "Courbe " << getangle() << endl;
		
		tampon = position;cout << position << endl;
		position = (re-getcentre()).rotation(Vecteur3D(0,0,1), 1*getangle()/4);
		cout << position << endl;
		corde = position - tampon;
		cout << corde << endl;
		angle = corde.angle(e1)*180/M_PI;
		
		glRotated(angle,0,0,1);
		glRotated(90,1,0,0);
		
		glColor4d(1.0,0,1.0,0.5);
		gluCylinder(droit_ext, Re*10, Re, (re-rs).norme(), 20, 20);
		
		glColor4d(1.0,0,0,1.0);
		gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
		
		gluDeleteQuadric(droit_ext);
		gluDeleteQuadric(droit_int);
		
		glPopMatrix();
		
		
		/*tampon = position;
		position = (re-getcentre()).rotation(Vecteur3D(0,0,-1), i*getangle()/4);
		corde = position - tampon;
		angle = corde.angle(e1)*180/M_PI;
		cout << "				Et de " << i << endl;
		
		(*this).partie_tore(angle, position);
	}*/
	
	
	
	glPopMatrix();
}

void Courbe3D::partie_tore(double angle, Vecteur3D position) const
{
	
		GLUquadric* droit_ext=gluNewQuadric();
		GLUquadric* droit_int=gluNewQuadric();
		
		gluQuadricDrawStyle(droit_ext, GLU_LINE);
		gluQuadricDrawStyle(droit_int, GLU_FILL);
		
		glPushMatrix();
		
		glTranslated(position.getx(), position.gety(), position.getz());
		cout << "coucou" << endl;
		
		
		glRotated(90-angle,0,0,1);
		glRotated(90,1,0,0);
		
		glColor4d(1.0,0,1.0,0.5);
		gluCylinder(droit_ext, Re*10, Re, (re-rs).norme(), 20, 20);
		
		glColor4d(1.0,0,0,1.0);
		gluCylinder(droit_int, Re, Re, (re-rs).norme(), 20, 20);
		
		glPopMatrix();
		
		gluDeleteQuadric(droit_ext);
		gluDeleteQuadric(droit_int);
}

