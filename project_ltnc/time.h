#ifndef _TIME_H_
#define _TIME_H_

#include "commonFunction.h"
#include "baseObject.h"

class LTimer : public LTexture
{
public:
	LTimer();

	void start();
	void stop();
	void pause();
	void unpause();

	int getTicks();

	bool isStarted();
	bool isPaused();

	int getPositionX();
	int getPositionY();
private:
	int timePositionRenderedX;
	int timePositionRenderedY;

	int mStartTicks;
	int mPauseTicks;

	bool mStarted;
	bool mPaused;
};

#endif _TIME_H_