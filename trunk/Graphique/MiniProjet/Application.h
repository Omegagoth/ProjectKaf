#ifndef APPLICATION_H
#define APPLICATION_H
 
//Headers
#include "wxIncludes"
#include "FenetreGL.h"
 
class Application : public wxApp //Héritage
{
	private:
		
		bool OnInit(); //La fonction OnInit est appelée lors de l'initialisation de l'application.
		FenetreGL* fenetreGL; //On stocke un pointeur, voir remarque plus bas.
};
#endif

