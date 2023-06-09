#pragma once
#include "stdafx.h"

#ifndef FSMSTATE_H
#define	FSMSTATE_H

class FSMState
{
	public:
	string name;
	GLfloat time;
	GLfloat counter;

	__declspec(dllexport) FSMState() 
	{
		name = "";
		time = 0.0f;
		counter = 0.0f;
	};
	__declspec(dllexport) ~FSMState() {};

	__declspec(dllexport) virtual void enter() = 0;
	__declspec(dllexport) virtual void exit() = 0;
	__declspec(dllexport) virtual void update() = 0;

	__declspec(dllexport) void print() const
	{
		cout << "State Name = " << name << endl;
		cout << "State Time = " << time << endl;
		cout << "State Counter = " << counter << endl;
	};
};
#endif // !STATE_H
