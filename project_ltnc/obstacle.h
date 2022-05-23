#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "commonFunction.h"
#include "baseObject.h"

class obstacle {
public:
	obstacle();

	void setPosition();

	int getObstaclePositionX();
	int getObstaclePositionY();

	void setRandomX();
	void setStartY(int i);
	void setZeroY();
	void setNextY();
private:
	int obstaclePositionX, obstaclePositionY;
};

#endif _OBSTACLE_H_