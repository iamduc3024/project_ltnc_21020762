#include "theFinishLine.h"

theFinishLine::theFinishLine() {
	theFinishLinePositionX = (SCREEN_WIDTH - THE_FINISH_LINE_WIDTH) / 2;
	theFinishLinePositionY = 0;
}

void theFinishLine::setPosition() {
	theFinishLinePositionX = (SCREEN_WIDTH - THE_FINISH_LINE_WIDTH) / 2;
	theFinishLinePositionY = 0;
}

int theFinishLine::getFinishLinePositionX() {
	return theFinishLinePositionX;
}

int theFinishLine::getFinishLinePositionY() {
	return theFinishLinePositionY;
}

void theFinishLine::setNextY()
{
	theFinishLinePositionY += 3;
}