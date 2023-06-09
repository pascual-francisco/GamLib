#include "stdafx.h"

	KeyFrame:: KeyFrame(int keyTime, float keyValue,  int easingF,  int easingR, bool actionActive,  int actionState,  int fireDirection,  int time,  int key)	
	{
		reset();
		this->time = keyTime;
		value = keyValue;
		easingForward = easingF;
		easingReverse = easingR;
		action = TrackAction(actionActive,actionState, fireDirection, time,key); 		
	}

	KeyFrame::KeyFrame(const KeyFrame& key)
	{
		if(&key!=this)
		{
			time = key.time;
			value = key.value;
			easingForward = key.easingForward;
			easingReverse = key.easingReverse;
			action = key.action;
			keyDelegate = key.keyDelegate;
		}
	}

	KeyFrame::~KeyFrame()
	{
		keyDelegate.clear();
	}

	void KeyFrame::reset()
	{
		time = 0;
		value =0.0f;
		easingForward = LINEAR;
		easingReverse = LINEAR;
		action.active = false;
		action.actualState = TrackAction::FORWARD;
		action.pauseTime = 0;
		action.pauseCounter = 0;		
	}

	const KeyFrame& KeyFrame::operator=(const KeyFrame& key)
	{
		if(&key!=this)
		{
			easingForward = key.easingForward;
			easingReverse = key.easingReverse;
			time = key.time;
			value = key.value;
			action = key.action;
			keyDelegate = key.keyDelegate;
		}
		return *this;
	}

	bool KeyFrame::operator==(const KeyFrame& key) const
	{
		if(time == key.time && 
			value == key.value &&
			easingForward == key.easingForward &&
			easingReverse == key.easingReverse &&
			action == key.action && 
			keyDelegate == key.keyDelegate
			)
		{
			return true;	
		}
		else
		{
			return false;
		}
	}

	bool KeyFrame::operator<(const KeyFrame& key) const
	{	
		if(time < key.time)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool KeyFrame::operator>(const KeyFrame& key) const
	{	
		if(time > key.time)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
