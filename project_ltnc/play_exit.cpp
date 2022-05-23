#include "play_exit.h"

bool handlePlay(SDL_Event* e, SDL_Renderer* renderer) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insidePlay = true;
		if (x < PLAY_LEFT_POSITION) {
			insidePlay = false;
		}
		else if (x > PLAY_RIGHT_POSITION) {
			insidePlay = false;
		}
		else if (y < PLAY_TOP_POSITION) {
			insidePlay = false;
		}
		else if (y > PLAY_BOTTOM_POSITION) {
			insidePlay = false;
		}

		return insidePlay;
	}
}

bool handleExit(SDL_Event* e, SDL_Renderer* renderer)
{
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insideExit = true;
		if (x < EXIT_LEFT_POSITION) {
			insideExit = false;
		}
		else if (x > EXIT_RIGHT_POSITION) {
			insideExit = false;
		}
		else if (y < EXIT_TOP_POSITION) {
			insideExit = false;
		}
		else if (y > EXIT_BOTTOM_POSITION) {
			insideExit = false;
		}

		return insideExit;
	}
}
