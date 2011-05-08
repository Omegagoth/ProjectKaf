#ifndef APPLICATION_H
#define APPLICATION_H
 
//Headers
#include "wxIncludes"
#include "FenetreGL.h"
#include "Telescope.h"
#include "Ciel.h"
#include "TextureManager.h"
 
class Application : public wxApp //Héritage
{
	public:
	
		void dessine();
		GLuint* getTexture(string fichier, bool mipmap=true);
	
	private:
	
		Telescope telescope;
		Ciel ciel;
		TextureManager texturemanager;
		wxTimer* timerCiel;
		
		bool OnInit(); //La fonction OnInit est appelée lors de l'initialisation de l'application.
		FenetreGL* fenetreGL; //On stocke un pointeur, voir remarque plus bas.
		bool loaded;
		void rafraichir();
		void rotationCiel(wxTimerEvent&);
};

DECLARE_APP(Application);

#endif

