#include "Telescope.h"
#include "Application.h"

double Telescope::getRotation() const
{
	return rotation;
}

double Telescope::getInclinaison() const
{
	return inclinaison;
}




void Telescope::setRotation(double r)
{
	rotation = r;
}

void Telescope::setInclinaison(double i)
{
	inclinaison = i;
}




Telescope::Telescope()
: rotation(0), inclinaison(0)
{}

Telescope::Telescope(double r, double i)
: rotation(r), inclinaison(i)
{}

Telescope::~Telescope()
{}

void Telescope::dessine()
{
	double dimensions[8][2];
	
	dimensions[0][0]=1.0;
	dimensions[0][1]=3.5;

	dimensions[1][0]=4.0;
	dimensions[1][1]=2.0;
 
	dimensions[2][0]=3.0;
	dimensions[2][1]=3.5;
	
	dimensions[3][0]=5.0;
	dimensions[3][1]=5.5;
	
	dimensions[4][0]=7.5;
	dimensions[4][1]=8.5;
	
	dimensions[5][0]=11.0;
	dimensions[5][1]=11.5;
	
	dimensions[6][0]=11;
	dimensions[6][1]=14;
	
	dimensions[7][0]=14;
	dimensions[7][1]=18;
	
	for (int i(0); i<8; ++i) dimensions[i][1]/=2.0;
		
	glPushMatrix();
	
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, *wxGetApp().getTexture("texture/metal.jpg"));
	
	GLUquadric* telesc=gluNewQuadric();
	
	gluQuadricDrawStyle(telesc, GLU_FILL);
	gluQuadricTexture(telesc, GLU_TRUE);
	
	gluCylinder(telesc, 3.5, 2.5, 16, 20, 20);
	
	double a(0);
	
	for (int i(0); i<5; i++)
	{
		a += dimensions[i][0];
	}
	
	a += dimensions[5][1]/2;
	
	glTranslated(-a, 0, 16 + dimensions[5][1]);
	glRotated(90, 0, 1, 0);
	gluDisk(telesc, 0, dimensions[0][1], 30, 1);
	
	for (int i(0); i<8; i++)
	{
		gluCylinder(telesc, dimensions[i][1], dimensions[i][1], dimensions[i][0], 20, 20);
		glTranslated(0, 0, dimensions[i][0]);
		gluDisk(telesc, 0, dimensions[i+1][1], 30, 1);
	}
	
	glTranslated(0, 0, -5);
	glRotated(180, 0, 0, 1);
	
	gluDeleteQuadric(telesc);
	
	glDisable(GL_TEXTURE_2D);
	
	GLUquadric* lentille=gluNewQuadric();
	glColor3ub(0,0,1);
	
	double plan[4]={0, 0, 1, -5};
	
	glClipPlane(GL_CLIP_PLANE0, plan);
	glEnable(GL_CLIP_PLANE0);
	
	glColor3ub(255,255,255);
	
	gluSphere(telesc, 10, 30,30);
	
	glDisable(GL_CLIP_PLANE0);
	
	gluDeleteQuadric(lentille);
	
	glPopMatrix();
}
