#ifndef APPLICATION_H
#define APPLICATION_H
 
//Headers
#include "wxIncludes"
#include "FenetreGL.h"
#include "Telescope.h"
 
class Application : public wxApp //Héritage
{
	public:
	
		void dessine();
	
	private:
	
		Telescope telescope;
		
		bool OnInit(); //La fonction OnInit est appelée lors de l'initialisation de l'application.
		FenetreGL* fenetreGL; //On stocke un pointeur, voir remarque plus bas.
		bool loaded;
		void rafraichir();
};

DECLARE_APP(Application);

#endif

