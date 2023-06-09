#pragma once
#include "stdafx.h"

Entity::Entity()
{
	active = true;
	name = "Entity";
	mechanics = Mechanics();		
};

Entity::~Entity()
{

}

Entity::Entity(const Entity &e)
{
	active = e.active;
	name = e.name;
	mechanics = e.mechanics;
	sprite = e.sprite;	
	healthPoints = e.healthPoints;
	attackDamage = e.attackDamage;
	weakness = e.weakness;
	tracks = e.tracks;
	
}

const Entity& Entity::operator=(const Entity &e)
{
	if (&e != this)
	{
		active = e.active;
		name = e.name;
		mechanics = e.mechanics;
		sprite = e.sprite;
		healthPoints = e.healthPoints;
		attackDamage = e.attackDamage;
		weakness = e.weakness;	
		tracks = e.tracks;
	}
	return *this;
}
bool Entity::operator==(const Entity &e) const
{
	if (
		active == e.active &&
		name == e.name &&
		mechanics == e.mechanics &&
		sprite == e.sprite &&		
		healthPoints == e.healthPoints &&
		attackDamage == e.attackDamage &&
		weakness == e.weakness &&
		tracks == e.tracks
		)
		return true;
	else
		return false;
}
bool Entity::operator<(const Entity &e) const
{
	if (sprite.size() < e.sprite.size())
		return true;
	else
		return false;
}
bool Entity::operator>(const Entity &e) const
{
	if (sprite.size() > e.sprite.size())
		return true;
	else
		return false;
}

void Entity::update()
{
	
}

void Entity::print() const
{
	mechanics.print();

	if (sprite.size() > 0)
	{
		for (uint i = 0; i<sprite.size() - 1; i++)		
		{			
			if (sprite[i] != NULL)
			{
				cout << "Sprite [" << i << "]" << endl;
				sprite[i]->print();
			}
		}
		cout << "-----------------------------" << endl;
	}
	else
	{
		cout << "Sprite is empty" << endl;
		cout << "-----------------------------" << endl;
	}
}