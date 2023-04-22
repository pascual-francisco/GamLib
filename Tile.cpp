#pragma once
#include "stdafx.h"

Tile::Tile(GLuint palette, Gluint page, GLuint tilex, GLuint tiley, GLuint tilewidth, GLuint tileheight, GLuint lastframe, GLuint frametime)
{
    init(palette, page, tilex, tiley, tilewidth, tileheight, lastframe, frametime)
}

Tile::Tile(const Tile &object)
{
    if (&object != this)
	{
        active = object.active;
        texturePalette = object.texturePalette;
        palettePage = object.palettePage;
        tileSeparation = object.tileSeparation;
        tileCell.x = object.tileCell.x;
        tileCell.y = object.tileCell.y;
        tileDimension.x = object.tileDimension.x;
        tileDimension.y = object.tileDimension.y;
        pageDimension.x = object.pageDimension.x;
        pageDimension.y = object.pageDimension.y;
        transformation = object.transformation;
        vertexColor[0] = object.vertexColor[0];
        vertexColor[1] = object.vertexColor[1];
        vertexColor[2] = object.vertexColor[2];
        vertexColor[3] = object.vertexColor[3];
        collisionData = object.collisionData;
        firstFrame = object.firstFrame;
        lastFrame = object.lastFrame;
        actualFrame = object.actualFrame;
        frameCounter = object.frameCounter;
        frameTime = object.frameTime;
	}
}

Tile::~Tile()
{

}

const Tile & Tile::operator=(const Tile &object)
{
    if (&object != this)
	{
        active = object.active;
        texturePalette = object.texturePalette;
        palettePage = object.palettePage;
        tileSeparation = object.tileSeparation;
        tileCell.x = object.tileCell.x;
        tileCell.y = object.tileCell.y;
        tileDimension.x = object.tileDimension.x;
        tileDimension.y = object.tileDimension.y;
        pageDimension.x = object.pageDimension.x;
        pageDimension.y = object.pageDimension.y;
        transformation = object.transformation;
        vertexColor[0] = object.vertexColor[0];
        vertexColor[1] = object.vertexColor[1];
        vertexColor[2] = object.vertexColor[2];
        vertexColor[3] = object.vertexColor[3];
        collisionData = object.collisionData;
        firstFrame = object.firstFrame;
        lastFrame = object.lastFrame;
        actualFrame = object.actualFrame;
        frameCounter = object.frameCounter;
        frameTime = object.frameTime;
	}
}

bool Tile::operator==(const Tile &object) const
{
   if (&object != this)
	{
		if (
		active == object.active &&
		texturePalette == object.texturePalette &&
		palettePage == object.palettePage &&
		tileSeparation == object.tileSeparation &&
		tileCell.x == object.tileCell.x &&
		tileCell.y == object.tileCell.y &&
		tileDimension.x == object.tileDimension.x &&
		tileDimension.y == object.tileDimension.y &&
		pageDimension.x == object.pageDimension.x &&
		pageDimension.y == object.pageDimension.y &&
		transformation == object.transformation &&
		vertexColor[0] == object.vertexColor[0] &&
		vertexColor[1] == object.vertexColor[1] &&
		vertexColor[2] == object.vertexColor[2] &&
		vertexColor[3] == object.vertexColor[3] &&
		collisionData == object.collisionData &&
        firstFrame == object.firstFrame &&
        lastFrame == object.lastFrame &&
        actualFrame == object.actualFrame &&
        frameCounter == object.frameCounter &&
        frameTime == object.frameTime
		)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Tile::operator<(const Tile &object) const
{
    if(lastFrame < object.lastFrame)
        return true;
        else
            return false;
}

bool Tile::operator>(const Tile &object) const
{
    if(lastFrame < object.lastFrame)
        return true;
        else
            return false;
}

bool Tile::operator*(const Tile &object) const
{
    SDL_Rect a, b;
	a.x = tileCell.x;
	a.y = tileCell.y;
	a.w = tileDimension.x;
	a.h = tileDimension.x;
	b.x = object.tileCell.x;
	b.y = object.tileCell.y;
	b.w = object.tileDimension.x;
	b.h = object.tileDimension.x;

	if(SDL_HasIntersection(a, b)
		return true;
		else
			return false;
}

void Tile::init(GLuint palette, GLuint page, GLuint tilex, GLuint tiley, GLuint tilewidth, GLuint tileheight, GLuint lastframe, GLuint frametime)
{
	texturePalette = palette;
	palettePage = page;

	firstFrame = firstframe;
	lastFrame = lastframe ;
	actualFrame = 0;
	frameCounter = 0;
	frameTime = frametime;

	tileDimension.x = tilewidth;
	tileDimension.y = tileheight;
	tileCell.x = tilex;
	tileCell.y = tiley;

	GLint w, h, = 0;
	glBindTexture(GL_TEXTURE_2D_ARRAY, texturePalette);
	glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_WIDTH, &w);
	glGetTexLevelParameteriv(GL_TEXTURE_2D_ARRAY, 0, GL_TEXTURE_HEIGHT, &h);
	glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
	pageDimension.x = float(w);
	pageDimension.y = float(h);
}

void Tile::update()
{
    if (lastFrame > firstFrame)
	{
		if (animationState == AnimationStates::FORWARD)
		{
			if (frameCounter < frameTime)
			{
				frameCounter++;
			}
			else
			{
				if (actualFrame < lastFrame)
				{
					actualFrame++;
				}
				frameCounter = 0;
			}
		}

		if (animationState == AnimationStates::BACKWARD)
		{
			if (frameCounter < frameTime)
			{
				frameCounter++;
			}
			else
			{
				if (actualFrame > firstFrame)
				{
					actualFrame--;
				}
				frameCounter = 0;
			}
		}

		if (animationState == AnimationStates::LOOP_FORWARD)
		{
			if (frameCounter < frameTime)
			{
				frameCounter++;
			}
			else
			{
				if (actualFrame < lastFrame)
				{
					actualFrame++;
				}
				else
				{
					actualFrame = firstFrame;
					loopCounter++;
				}
				frameCounter = 0;
			}
		}

		if (animationState == AnimationStates::LOOP_BACKWARD)
		{
			if (frameCounter < frameTime)
			{
				frameCounter++;
			}
			else
			{
				if (actualFrame > firstFrame)
				{
					actualFrame--;
				}
				else
				{
					actualFrame = lastFrame;
					loopCounter++;
				}
				frameCounter = 0;
			}
		}

		if (animationState == AnimationStates::PAUSE)
		{

		}

		if (animationState == AnimationStates::STOP)
		{
            frameCounter = 0;
            actualFrame = firstFrame;
		}
	}
}

void Tile::print() const
{
    GraphicElement.print();
    cout << "Position Offset = [ " << positionOffset.x << " , " << positionOffset.y << " ]" <<endl;
}
