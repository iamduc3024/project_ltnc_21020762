#include "item.h"

bool pause::handlePauseEvent(SDL_Event* e, SDL_Renderer* renderer) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insidePause = true;
		if (x < 0) {
			insidePause = false;
		}
		else if (x > PAUSE_WIDTH) {
			insidePause = false;
		}
		else if (y < 0) {
			insidePause = false;
		}
		else if (y > PAUSE_HEIGHT) {
			insidePause = false;
		}
		
		return insidePause;
	}
}

bool resume::handleResumeEvent(SDL_Event* e, SDL_Renderer* renderer) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insideResume = true;
		if (x < (SCREEN_WIDTH - RESUME_WIDTH) / 2) {
			insideResume = false;
		}
		else if (x > (SCREEN_WIDTH - RESUME_WIDTH) / 2 + RESUME_WIDTH) {
			insideResume = false;
		}
		else if (y < (SCREEN_HEIGHT - RESUME_HEIGHT) / 2) {
			insideResume = false;
		}
		else if (y > (SCREEN_HEIGHT - RESUME_HEIGHT) / 2 + RESUME_HEIGHT) {
			insideResume = false;
		}

		return insideResume;
	}
}


bool quit::handleQuitEvent(SDL_Event* e, SDL_Renderer* renderer) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insideQuit = true;
		if (x < (SCREEN_WIDTH - QUIT_WIDTH) / 2) {
			insideQuit = false;
		}
		else if (x > (SCREEN_WIDTH - QUIT_WIDTH) / 2 + QUIT_WIDTH) {
			insideQuit = false;
		}
		else if (y < SCREEN_HEIGHT - 2 * QUIT_HEIGHT) {
			insideQuit = false;
		}
		else if (y > SCREEN_HEIGHT - QUIT_HEIGHT) {
			insideQuit = false;
		}

		return insideQuit;
	}
}

bool quitYes::handleQuitYesEvent(SDL_Event* e, SDL_Renderer* renderer) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insideQuitYes = true;
		if (x < (SCREEN_WIDTH - QUIT_YES_WIDTH) / 2) {
			insideQuitYes = false;
		}
		else if (x > (SCREEN_WIDTH - QUIT_YES_WIDTH) / 2 + QUIT_YES_WIDTH) {
			insideQuitYes = false;
		}
		else if (y < QUIT_YES_TOP_POSITION) {
			insideQuitYes = false;
		}
		else if (y > QUIT_YES_TOP_POSITION + QUIT_YES_HEIGHT) {
			insideQuitYes = false;
		}

		return insideQuitYes;
	}
}

bool quitNo::handleQuitNoEvent(SDL_Event* e, SDL_Renderer* renderer)
{
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insideQuitNo = true;
		if (x < (SCREEN_WIDTH - QUIT_NO_WIDTh) / 2) {
			insideQuitNo = false;
		}
		else if (x > (SCREEN_WIDTH - QUIT_NO_WIDTh) / 2 + QUIT_NO_WIDTh) {
			insideQuitNo = false;
		}
		else if (y < QUIT_NO_TOP_POSITION) {
			insideQuitNo = false;
		}
		else if (y > QUIT_NO_TOP_POSITION + QUIT_NO_HEIGHT) {
			insideQuitNo = false;
		}

		return insideQuitNo;
	}
}

bool muteOrNot::handleMuteOrNot(SDL_Event* e, SDL_Renderer* renderer) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool insideMuteOrNot = true;
		if (x < SCREEN_WIDTH - MUTE_OR_NOT_WIDTH) {
			insideMuteOrNot = false;
		}
		else if (x > SCREEN_WIDTH) {
			insideMuteOrNot = false;
		}
		else if (y < 0) {
			insideMuteOrNot = false;
		}
		else if (y > MUTE_OR_NOT_HEIGHT) {
			insideMuteOrNot = false;
		}

		return insideMuteOrNot;
	}
}