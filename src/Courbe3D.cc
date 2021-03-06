#include "Courbe3D.h"





unsigned int Courbe3D::getprecision() const
{
	return precision;
}




void Courbe3D::setprecision(unsigned int p)
{
	precision = p;
}



Courbe3D::Courbe3D()
: Element(), Element3D(), Courbe(), precision(0)
{}

Courbe3D::Courbe3D(Vecteur3D re, Vecteur3D rs, double R, double k, unsigned int p, unsigned int r,
					unsigned int v, unsigned int b, unsigned int t)
: Element(re,rs,R), Element3D(re,rs,R,r,v,b,t), Courbe(re, rs, R, k), precision(p)
{}

Courbe3D::Courbe3D(Courbe3D const& c)
: Element(c), Element3D(c), Courbe(c), precision(c.getprecision())
{}

Courbe3D::~Courbe3D()
{}





void Courbe3D::dessine() const //pour l'instant c'est le même que droit car je sais pas comment faire un tore
{
	Vecteur3D e1(1,0,0);
	
	glPushMatrix();//On stocker la matrice courante
	
	vector<Vecteur3D> positions;
	//On initialise le vector stockant les positions successives
	for (int unsigned i(0); i< precision+1; i++)
	{
		positions.push_back((re-getcentre()).rotation(Vecteur3D(0,0,1), i*getangle()/precision));
	}
	
	//On crée la quadrique associer au dipole
	GLUquadric* droit_ext=gluNewQuadric();
	
	gluQuadricDrawStyle(droit_ext, GLU_LINE);
	
	//On ce translate au centre de courbure de notre dipole
	glTranslated(getcentre().getx(), getcentre().gety(), getcentre().getz());
	
	
	
	
	//On trace le premier cylindre du tore
	glPushMatrix();
	
	Vecteur3D normale_plan;
	double plan[4];
	//On calcule l'équation du plan de coupure empêchant de dépasser sur l'élément précedent
	normale_plan = getdirection();
	plan = {normale_plan.getx(), normale_plan.gety(), normale_plan.getz(),
			-normale_plan.getx()*positions[0].getx()
			- normale_plan.gety()*	positions[0].gety()
			- normale_plan.getz()*positions[0].getz()	};
	
	glClipPlane(GL_CLIP_PLANE1, plan);
	glEnable(GL_CLIP_PLANE1);
	
	//On calcule l'équation du plan de coupure empêchant de dépasser sur le cylindre suivant
	normale_plan = positions[1] - positions[2];
	plan = {normale_plan.getx(), normale_plan.gety(), normale_plan.getz(),
			-normale_plan.getx()*positions[1].getx()
			- normale_plan.gety()*	positions[1].gety()
			- normale_plan.getz()*positions[1].getz()	};
	
	glClipPlane(GL_CLIP_PLANE0, plan);
	glEnable(GL_CLIP_PLANE0);
	
	//On ce translate à l'entrée de l'élément
	glTranslated(positions[0].getx(), positions[0].gety(), positions[0].getz());

	//On calcule l'angle de rotation nécessaire pour tracer le cylindre à la corde du cercle
	Vecteur3D corde(positions[1] - positions[0]);
	double angle(corde.angle(e1)*180/M_PI);
	
	//On fait la rotation
	glRotated(90-angle,0,0,1);
	glRotated(90,1,0,0);
	
	//On trace le cylindre
	glColor4ub(couleurs.getrouge(), couleurs.getvert(), couleurs.getbleu(), couleurs.gettransparence());
	gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
	
	//On trace un autre cylindre en sens inverse pour éviter d'avoir "un trou"
	glRotated(180,0,1,0);
	gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
	
	
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
	
	
	
	
	
	//On trace manière itérative les autres cylindres du tore sauf le dernier
	for (int n(1); n<precision-1; n++)
	{
		glPushMatrix();
		
		//calcul de l'équation du plan de coupure enpêchant de dépasser sur le cylindre suivant
		normale_plan = positions[n+1] - positions[n+2];
		plan = {normale_plan.getx(), normale_plan.gety(), normale_plan.getz(),
				-normale_plan.getx()*positions[n+1].getx()
				- normale_plan.gety()*positions[n+1].gety()
				- normale_plan.getz()*positions[n+1].getz()	};
		
		glClipPlane(GL_CLIP_PLANE0, plan);
		glEnable(GL_CLIP_PLANE0);
		
		//translation vers le point du cercle souhaiter
		glTranslated(positions[n].getx(), positions[n].gety(), positions[n].getz());
		
		//calcul de l'angle de rotation
		corde = positions[n+1] - positions[n];
		angle = corde.angle(e1)*180/M_PI;
		
		//rotation
		glRotated(90-angle,0,0,1);
		glRotated(90,1,0,0);
		
		gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
		
		
		glDisable(GL_CLIP_PLANE0);
		glPopMatrix();
	}
	
	
	
	
	
	//On trace le dernier cylindre du tore
	glPushMatrix();
	
	//calcul de l'équation du plan de coupure empêchant de depasser sur l'élément suivant
	normale_plan = -getdirection();
	plan = {normale_plan.getx(), normale_plan.gety(), normale_plan.getz(),
			-normale_plan.getx()*positions[precision].getx()
			- normale_plan.gety()*positions[precision].gety()
			- normale_plan.getz()*positions[precision].getz()	};
	
	glClipPlane(GL_CLIP_PLANE0, plan);
	glEnable(GL_CLIP_PLANE0);
	
	//translation vers le point du cercle souhaiter
	glTranslated(positions[precision-1].getx(), positions[precision-1].gety(), positions[precision-1].getz());
	
	//calcul de l'angle de rotation
	corde = positions[precision] - positions[precision-1];
	angle = corde.angle(e1)*180/M_PI;
	
	//rotation
	glRotated(90-angle,0,0,1);
	glRotated(90,1,0,0);
	
	//tracé du cylindre
	gluCylinder(droit_ext, Re, Re, (re-rs).norme(), 20, 20);
	
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();
	
	
	
	
	gluDeleteQuadric(droit_ext);
	
	glPopMatrix();
}

