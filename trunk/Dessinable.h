#ifndef DESSINABLE_H
#define DESSINABLE_H

class Dessinable
{
	public :

	virtual void dessine(Element const&) const = 0;   // m�thode abstraite pure : dessine un element.

};


#endif
