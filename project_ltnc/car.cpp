
#include "car.h"

car::car() {
	mCarPositionX = (SCREEN_WIDTH - CAR_WIDTH) / 2;
	mCarPositionY = (SCREEN_HEIGHT - CAR_HEIGHT) / 2;

	mCarVelocityX = 0;
	mCarVelocityY = 0;

	mCollider.w = CAR_WIDTH;
	mCollider.h = CAR_HEIGHT;
}

void car::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		if (e.key.keysym.sym == SDLK_UP) {
			mCarVelocityY -= CAR_VELOCITY;
		}
		else if (e.key.keysym.sym == SDLK_DOWN) {
			mCarVelocityY += CAR_VELOCITY;
		}
		else if (e.key.keysym.sym == SDLK_RIGHT) {
			mCarVelocityX += CAR_VELOCITY;
		}
		else if (e.key.keysym.sym == SDLK_LEFT) {
			mCarVelocityX -= CAR_VELOCITY;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		if (e.key.keysym.sym == SDLK_UP) {
			mCarVelocityY += CAR_VELOCITY;
		}
		else if (e.key.keysym.sym == SDLK_DOWN) {
			mCarVelocityY -= CAR_VELOCITY;
		}
		else if (e.key.keysym.sym == SDLK_RIGHT) {
			mCarVelocityX -= CAR_VELOCITY;
		}
		else if (e.key.keysym.sym == SDLK_LEFT) {
			mCarVelocityX += CAR_VELOCITY;
		}
	}
}

void car::move(SDL_Renderer* renderer) {
	mCarPositionX += mCarVelocityX;
	mCollider.x = mCarPositionX;
	if (mCarPositionX < ROAD_SIDE || mCarPositionX + CAR_WIDTH > SCREEN_WIDTH - ROAD_SIDE) {
		mCarPositionX -= mCarVelocityX;
		mCollider.x = mCarPositionX;
	}

	mCarPositionY += mCarVelocityY;
	mCollider.y = mCarPositionY;
	if (mCarPositionY < 0 || mCarPositionY + CAR_HEIGHT > SCREEN_HEIGHT) {
		mCarPositionY -= mCarVelocityY;
		mCollider.y = mCarPositionY;
	}
}

int car::getCarPositionX() {
	return mCarPositionX;
}

int car::getCarPositionY() {
	return mCarPositionY;
}

bool checkCollision(SDL_Rect a, SDL_Rect b) {
	int topA, topB;
	int bottomA, bottomB;
	int rightA, rightB;
	int leftA, leftB;

	topA = a.y;
	bottomA = a.y + a.h;
	leftA = a.x;
	rightA = a.x + a.w;

	topB = b.y;
	bottomB = b.y + b.h;
	leftB = b.x;
	rightB = b.x + b.w;

	if (topA >= bottomB) {
		return false;
	}

	if (bottomA <= topB) {
		return false;
	}

	if (rightA <= leftB) {
		return false;
	}

	if (leftA >= rightB) {
		return false;
	}

	return true;
}