#ifndef APPLICATION_H
#define APPLICATION_H
 
//Headers
#include "wxIncludes.h"
#include "FenetreGL.h"
#include "TextureManager.h"
#include "Particule3D.h"
#include "Droit3D.h"
#include "Courbe3D.h"
 
class Application : public wxApp //Héritage
{
	public :
	
		void dessine();
		
		GLuint* getTexture(string fichier, bool mipmap=true);
	
	protected :
	
		Particule3D particule;
		Droit3D droit;
		Courbe3D courbe;
		TextureManager texturemanager;
				
		bool OnInit(); //La fonction OnInit est appelée lors de l'initialisation de l'application.
		FenetreGL* fenetreGL; //On stocke un pointeur, voir remarque plus bas.
		bool loaded;
		void rafraichir();
};

DECLARE_APP(Application);

#endif

