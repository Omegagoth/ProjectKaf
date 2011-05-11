/*
 * EPFL
 * CAESV3
 * Guide wxWidgets et OpenGL
 */

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "wxIncludes.h"
#include <map>

class TextureManager
{
	public:
		TextureManager();
		~TextureManager();
		void chargerTexture(std::string fichier, bool mipmap=false);
		GLuint* getTexture(std::string fichier, bool mipmap=false);
	private:
		std::map<std::string, GLuint> textures;
};

#endif
