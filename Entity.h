#pragma once
#include "stdafx.h"

#ifndef ENTITY_H
#define ENTITY_H

class Entity: public GameObject
{
	public:
	Mechanics			 mechanics;					
	stack < FSMState * > brain;	
	vector<Track *>		tracks;
	vector<Sprite *>	sprite;	
	static uint			maxInstances;
	static uint			instances;
	

	__declspec(dllexport) Entity();
	__declspec(dllexport) Entity(const Entity &);
	__declspec(dllexport) ~Entity();

	__declspec(dllexport) virtual const Entity &operator=(const Entity &);
	__declspec(dllexport) virtual bool operator==(const Entity &) const;
	__declspec(dllexport) virtual bool operator<(const Entity &) const;
	__declspec(dllexport) virtual bool operator>(const Entity &) const;	
	__declspec(dllexport) virtual void update();
	__declspec(dllexport) virtual void print() const;
};
#endif



