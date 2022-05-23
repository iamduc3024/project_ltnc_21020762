#include "time.h"


LTimer::LTimer() {
	timePositionRenderedX = (SCREEN_WIDTH - getWidth()) / 2;
	timePositionRenderedY = 0;

	mStartTicks = 0;
	mPauseTicks = 0;

	mStarted = false;
	mPaused = false;
}

void LTimer::start() {
	mStarted = true;
	mPaused = false;

	mStartTicks = SDL_GetTicks();
	mPauseTicks = 0;
}

void LTimer::stop() {
	mStarted = false;
	mPaused = true;

	mStartTicks = 0;
	mPauseTicks = 0;
}

void LTimer::pause() {
	if (mStarted == true && mPaused == false) {
		mPaused = true;

		mPauseTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void LTimer::unpause() {
	if (mStarted == true && mPaused == true) {
		mPaused = false;

		mStartTicks = SDL_GetTicks() - mPauseTicks;
		mPauseTicks = 0;
	}
}

int LTimer::getTicks() {
	int time = 0;

	if (mStarted == true) {
		if (mPaused == true) {
			time = mPauseTicks;
		}
		else {
			time = SDL_GetTicks() - mStartTicks;
		}
	}
	return time;
}

bool LTimer::isStarted() {
	return mStarted;
}

bool LTimer::isPaused() {
	return mPaused;
}

int LTimer::getPositionX() {
	return timePositionRenderedX;
}

int LTimer::getPositionY() {
	return timePositionRenderedY;
}