#ifndef _CAR_H_
#define _CAR_H_

#include "commonFunction.h"
#include "baseObject.h"

class car : public LTexture
{
public:
	static const int CAR_WIDTH = 60;
	static const int CAR_HEIGHT = 120;

	int CAR_VELOCITY = 10;

	car();

	void handleEvent(SDL_Event& e);

	void move(SDL_Renderer* renderer);

	int getCarPositionX();
	int getCarPositionY();
private:
	int mCarPositionX, mCarPositionY;

	int mCarVelocityX, mCarVelocityY;

	SDL_Rect mCollider;
};

bool checkCollision(SDL_Rect a, SDL_Rect b);

#endif _CAR_H_