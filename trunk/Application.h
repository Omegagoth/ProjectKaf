#ifndef APPLICATION_H
#define APPLICATION_H
 
//Headers
#include "wxIncludes.h"
#include "FenetreGL.h"
#include "TextureManager.h"
#include "Particule3D.h"
#include "Dipole3D.h"
#include "Fodo3D.h"
#include "Accelerateur.h"
 
class Application : public wxApp //Héritage
{
	public :
	
		void dessine();
		
		GLuint* getTexture(string fichier, bool mipmap=true);
	
	protected :
	
		Accelerateur acc;
		TextureManager texturemanager;
		FenetreGL* fenetreGL; //On stocke un pointeur, voir remarque plus bas.
		wxTimer* simulation_timer; //timer de l'évolution de l'accélérateur
		bool loaded;
				
		bool OnInit(); //La fonction OnInit est appelée lors de l'initialisation de l'application.
		
		
		void rafraichir();
		void evolue(wxTimerEvent&); //fonction qui fait évoluer l'accélérateur à chaque événement du timer
};

DECLARE_APP(Application);

#endif

