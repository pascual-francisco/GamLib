#include "stdafx.h"

	#ifndef TRACKDELEGATE_H
	#define TRACKDELEGATE_H

	class TrackDelegate
	{
		public:
		__declspec(dllexport) TrackDelegate();
		__declspec(dllexport) virtual ~TrackDelegate();
		__declspec(dllexport) virtual void onHeadPositionChangedForward( int);				
		__declspec(dllexport) virtual void onHeadPositionChangedBackward( int);				
		__declspec(dllexport) virtual void onHeadPositionChanged( int);				
		__declspec(dllexport) virtual void onValueChanged(float);
		__declspec(dllexport) virtual void onValueChangedToZero();
		__declspec(dllexport) virtual void onValueChangedToOne();		
		__declspec(dllexport) virtual void onFirstFrame();
		__declspec(dllexport) virtual void onLastFrame();
		__declspec(dllexport) virtual void onForward();
		__declspec(dllexport) virtual void onBackward();
		__declspec(dllexport) virtual void onLoopForward();
		__declspec(dllexport) virtual void onLoopBackward();
		__declspec(dllexport) virtual void onStop();
		__declspec(dllexport) virtual void onPause();
		__declspec(dllexport) virtual void onDirectionChanged( int);
		__declspec(dllexport) virtual void onStateChanged( int);
		__declspec(dllexport) virtual void onKeyFrame( int);		
	};
	#endif
