#pragma once
#include "stdafx.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

void TextureManager::initTexture(GLuint name, string path, GLuint quantity, GLuint target)
{
	GLuint textureID = 0;
	string file;
	SDL_Surface *ptrImage = NULL;

	glGenTextures(1, &textureID);
	glBindTexture(target, textureID);

	glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (target == GL_TEXTURE_2D_ARRAY)
	{
		if (quantity == 1)
		{
			file = path + ".png";

			ptrImage = IMG_Load(file.c_str());

			if (ptrImage != NULL)
			{
				glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA, ptrImage->w, ptrImage->h, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
				glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0, ptrImage->w, ptrImage->h, 1, GL_RGBA, GL_UNSIGNED_BYTE, ptrImage->pixels);
			}
		}

		if (quantity > 1 && quantity < 10 )
		{
			//Attack_BattonBone_1.png//
			//Attack_BattonBone_
			file = path + "1.png";

			ptrImage = IMG_Load(file.c_str());

			if (ptrImage != NULL)
				glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA, ptrImage->w, ptrImage->h, quantity, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);


			for (GLuint i = 1; i < quantity + 1; i++)
			{
				file = path + to_string(i) + ".png";

				ptrImage = IMG_Load(file.c_str());

				if (ptrImage != NULL)
					glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i - 1, ptrImage->w, ptrImage->h, 1, GL_RGBA, GL_UNSIGNED_BYTE, ptrImage->pixels);
			}
		}

		if (quantity >= 10)
		{
			//Idle_RT-55J_01.png//
			//Idle_RT-55J_
			file = path + "01.png";
			ptrImage = IMG_Load(file.c_str());

			if (ptrImage != NULL)
				glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA, ptrImage->w, ptrImage->h, quantity, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);


			for (GLuint i = 1; i < quantity + 1; i++)
			{
				if (i < 10)
				{
					file = path + "0" + to_string(i) + ".png";
				}
				else
				{
					file = path + to_string(i) + ".png";
				}

				ptrImage = IMG_Load(file.c_str());

				if (ptrImage != NULL)
					glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i - 1, ptrImage->w, ptrImage->h, 1, GL_RGBA, GL_UNSIGNED_BYTE, ptrImage->pixels);

			}
		}
		SDL_FreeSurface(ptrImage);
	}

}

