/*
 * EPFL
 * CAESV3
 * Guide wxWidgets et OpenGL
 */

#include "TextureManager.h"
#include <dirent.h>
#include <iterator>

TextureManager::TextureManager()
{
}
TextureManager::~TextureManager()
{
	//On libère les textures
	for (std::map<std::string,GLuint>::iterator it=textures.begin(); it != textures.end(); ++it) glDeleteTextures(1, &it->second);
}

void TextureManager::chargerTexture(std::string fichier, bool mipmap)
{
	wxImageHandler* jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	
	glGenTextures(1, &textures[fichier]);
	glBindTexture(GL_TEXTURE_2D, textures[fichier]);
	
	std::string imagepath=fichier;
	
	wxImage* img=new wxImage(wxString::From8BitData(imagepath.c_str()), wxBITMAP_TYPE_JPEG);
	GLubyte* imagedata=img->GetData();
	
	if (mipmap)
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img->GetWidth(), img->GetHeight(), GL_RGB, GL_UNSIGNED_BYTE, imagedata);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, 3, img->GetWidth(), img->GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, imagedata);
	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	free(img);
	free(imagedata);
}
GLuint* TextureManager::getTexture(std::string fichier, bool mipmap)
{
	if (textures.find(fichier)==textures.end()) chargerTexture(fichier, mipmap);
	return &textures[fichier];
}
