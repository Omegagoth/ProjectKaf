#include "GLUtils.h"

void dessineRepere()
{
	//On met les attributs actuels sur la pile
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	
	//Active la gestion de la transparence
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2);
	
	glBegin(GL_LINES);
	
	glColor3ub(0,0,255);
	glVertex3d(0,0,0);
	glVertex3d(1,0,0);
	
	glColor3ub(255,0,0);
	glVertex3d(0,0,0);
	glVertex3d(0,1,0);
	
	glColor3ub(0,255,0);
	glVertex3d(0,0,0);
	glVertex3d(0,0,1);
	
	glEnd();
	
	glPopAttrib();
}

