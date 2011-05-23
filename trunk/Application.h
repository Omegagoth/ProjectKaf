#ifndef APPLICATION_H
#define APPLICATION_H
 
//Headers
#include "wxIncludes.h"
#include "FenetreGL.h"
#include "TextureManager.h"
#include "Particule3D.h"
#include "Dipole3D.h"
#include "Section_droite3D.h"
#include "Accelerateur.h"
 
class Application : public wxApp //Héritage
{
	public :
	
		void dessine();
		
		GLuint* getTexture(string fichier, bool mipmap=true);
	
	protected :
	
		Accelerateur acc;
		TextureManager texturemanager;
				
		bool OnInit(); //La fonction OnInit est appelée lors de l'initialisation de l'application.
		FenetreGL* fenetreGL; //On stocke un pointeur, voir remarque plus bas.
		bool loaded;
		void rafraichir();
};

DECLARE_APP(Application);

#endif

