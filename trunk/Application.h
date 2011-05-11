#ifndef APPLICATION_H
#define APPLICATOIN_H

#include "wxIncludes.h"
#include "FenetreGL.h"
#include "Particule3D.h"
#include "Droit3D.h"

using namespace std;

class Application : public wxApp
{
	public :
	
		void dessine() const;
	
	protected :
	
		FenetreGl* fenetreGL;
		Droit3D droit;
		Particule3D particule;
		
		bool OnInit();
		void rafraichir() const;
};

DECLARE_APP(Application);



#endif

