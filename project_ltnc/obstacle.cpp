#include "obstacle.h"

obstacle::obstacle() {
	obstaclePositionX = 0;
	obstaclePositionY = 0;
}

void obstacle::setPosition() {
	obstaclePositionX = rand() % ((SCREEN_WIDTH - ROAD_SIDE - OBSTACLE_WIDTH) - (ROAD_SIDE) + 1) + ROAD_SIDE;
	obstaclePositionY = 0;
}

int obstacle::getObstaclePositionX() {
	return obstaclePositionX;
}

int obstacle::getObstaclePositionY() {
	return obstaclePositionY;
}

void obstacle::setRandomX()
{
	obstaclePositionX = rand() % ((SCREEN_WIDTH - ROAD_SIDE - OBSTACLE_WIDTH) - (ROAD_SIDE)+1) + ROAD_SIDE;
}

void obstacle::setStartY(int i)
{
	obstaclePositionY = i;
}

void obstacle::setZeroY()
{
	obstaclePositionY = 0;
}

void obstacle::setNextY()
{
	obstaclePositionY += 3;
}