#include "commonFunction.h"
#include "baseObject.h"
#include "time.h"
#include "car.h"
#include "item.h"
#include "obstacle.h"
#include "play_exit.h"
#include "theFinishLine.h"

LTexture gGameMenuTexture;

LTexture gBGTexture;

LTexture gCarTexture;
car _car;

LTexture gTimeTexture;
LTimer time_;
LTexture gTimeBackgroundTexture;

LTexture gPauseTexture;
pause _pause;
LTexture gPauseGameTexture;

resume _resume;

quit _quit;
LTexture gQuitYesTexture;
quitYes _quitYes;
quitNo _quitNo;

LTexture gObstacle[10];
obstacle _obstacle[10];
SDL_Rect obstacleRect[10];

LTexture gMuteTexture;
LTexture gUnmuteTexture;
muteOrNot _muteOrNot;

LTexture gFinishLine;
theFinishLine theFinishLine_;

LTexture gWinGame;
LTexture gLoseGame;

bool isTrueCollision[10];
int timeLimit = 180;

bool init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Can not initialize SDL! Error: " << SDL_GetError() << endl;
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("INT2215_1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cout << "Can not create window! Error: " << SDL_GetError() << endl;
			success = false;
		}
		else {
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				cout << "Can not create renderer! Error: " << SDL_GetError() << endl;
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
				if (!IMG_Init(IMG_INIT_PNG)) {
					cout << "Can not initialize IMG! Error: " << IMG_GetError() << endl;
					success = false;
				}

				if (TTF_Init() < 0) {
					cout << "Can not initialize TTF! Error: " << TTF_GetError() << endl;
					success = false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
					cout << "Can not initialize MIXER! Error: " << Mix_GetError() << endl;
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true;
	if (gGameMenuTexture.loadFromFile("project_media/gameMenu.png", gRenderer) == false) {
		cout << "Can not load game menu!" << endl;
		success = false;
	}

	if (gBGTexture.loadFromFile("project_media/background.png", gRenderer) == false) {
		cout << "Can not load background!" << endl;
		success = false;
	}

	if (gCarTexture.loadFromFile("project_media/redcar.png", gRenderer) == false) {
		cout << "Can not load car!" << endl;
		success = false;
	}

	if (gTimeBackgroundTexture.loadFromFile("project_media/timeBackground.png", gRenderer) == false) {
		cout << "Can not load time background!" << endl;
		success = false;
	}

	gFont = TTF_OpenFont("project_media/font.ttf", 28);
	if (gFont == NULL) {
		cout << "Can not load font! Error: " << TTF_GetError() << endl;
		success = false;
	}

	if (gPauseTexture.loadFromFile("project_media/pause.png", gRenderer) == false) {
		cout << "Can not load pause!" << endl;
		success = false;
	}

	if (gPauseGameTexture.loadFromFile("project_media/pausedGameBackground.png", gRenderer) == false) {
		cout << "Can not load pause game!" << endl;
		success = false;
	}

	if (gQuitYesTexture.loadFromFile("project_media/quitOrNot.png", gRenderer) == false) {
		cout << "Can not load quit or not!" << endl;
		success = false;
	}

	for (int i = 0; i < 10; i++)
	{
		if (gObstacle[i].loadFromFile("project_media/obstacle.png", gRenderer) == false) {
			cout << "Can not load obstacle!" << endl;
			success = false;
		}

	}

	gSoundCarEffect = Mix_LoadMUS("project_media/soundCarEffect.wav");
	if (gSoundCarEffect == NULL) {
		cout << "Can not load sound effect!" << endl;
		success = false;
	}

	gCarCollision = Mix_LoadWAV("project_media/carCollision.wav");
	if (gCarCollision == NULL) {
		cout << "Can not load car collision effect!" << endl;
		success = false;
	}

	gSoundBackground = Mix_LoadMUS("project_media/soundBackground.wav");
	if (gSoundBackground == NULL) {
		cout << "Can not load sound background!" << endl;
		success = false;
	}
	
	if (gUnmuteTexture.loadFromFile("project_media/unmute.png", gRenderer) == false) {
		cout << "Can not load unmute!" << endl;
		success = false;
	}

	if (gMuteTexture.loadFromFile("project_media/mute.png", gRenderer) == false) {
		cout << "Can not load mute!" << endl;
		success = false;
	}

	if (gFinishLine.loadFromFile("project_media/theFinishLine.png", gRenderer) == false) {
		cout << "Can not load the finish line!" << endl;
		success = false;
	}

	if (gWinGame.loadFromFile("project_media/win.png", gRenderer) == false) {
		cout << "Can not load win game!" << endl;
		success = false;
	}

	gWinGameSound = Mix_LoadMUS("project_media/winGame.wav");
	if (gWinGameSound == NULL) {
		cout << "Can not load win game sound!" << endl;
		success = false;
	}

	if (gLoseGame.loadFromFile("project_media/lose.png", gRenderer) == false) {
		cout << "Can not load lose game!" << endl;
		success = false;
	}

	gLoseGameSound = Mix_LoadMUS("project_media/loseGame.wav");
	if (gLoseGameSound == NULL) {
		cout << "Can not load lose game sound!" << endl;
		success = false;
	}
	
	return success;
}

void close() {
	gGameMenuTexture.free();
	gCarTexture.free();
	gBGTexture.free();
	gTimeTexture.free();
	gTimeBackgroundTexture.free();
	gPauseTexture.free();

	for (int i = 0; i < 10; i++) {
		gObstacle[i].free();
	}
	Mix_FreeMusic(gSoundCarEffect);
	gSoundCarEffect = NULL;

	Mix_FreeMusic(gSoundBackground);
	gSoundBackground = NULL;

	Mix_FreeChunk(gCarCollision);
	gCarCollision = NULL;

	Mix_FreeMusic(gWinGameSound);
	gWinGameSound = NULL;

	Mix_FreeMusic(gLoseGameSound);
	gLoseGameSound = NULL;

	gUnmuteTexture.free();
	gMuteTexture.free();

	gFinishLine.free();

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main (int argc, char* argv[]) {
	if (!init()) {
		cout << "Can not initialize!" << endl;
	}
	else {
		if (!loadMedia()) {
			cout << "Can not load media!" << endl;
		}
		else {
			Mix_PlayMusic(gSoundBackground, -1);
			bool quitMenu = false;
			SDL_Event e;
			while (!quitMenu) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quitMenu = true;
					}
					else if (handleExit(&e, gRenderer) == true) {
						return 0;
					}
					else if (handlePlay(&e, gRenderer) == true) {
						time_.start();

						bool quit = false;

						SDL_Event e;

						int scroll = 0;

						SDL_Color textColor = { 0, 0, 0, 255 };
						stringstream timeText;

						Mix_PlayMusic(gSoundCarEffect, -1);
						for (int i = 0; i < 4; i++)
						{
							_obstacle[i].setStartY(i * -(SCREEN_HEIGHT / 4));
							_obstacle[i].setRandomX();
						}

						while (!quit) {
							while (SDL_PollEvent(&e) != 0) {
								if (e.type == SDL_QUIT) {
									quit = true;
									Mix_HaltMusic();
									return 0;
								}
								if (_muteOrNot.handleMuteOrNot(&e, gRenderer) == true) {
									if (Mix_PausedMusic() == true) {
										Mix_ResumeMusic();
									}
									else {
										Mix_PauseMusic();
									}
								}
								_car.handleEvent(e);
							}

							timeText.str("");
							if (timeLimit - (time_.getTicks() / 1000) < 0) {
								timeText << 0;
							}
							else {
								timeText << timeLimit - (time_.getTicks() / 1000);
							}

							gTimeTexture.loadFromRenderedText(gRenderer, timeText.str(), textColor, gFont);

							SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
							SDL_RenderClear(gRenderer);

							scroll += 3;
							if (scroll > gBGTexture.getHeight()) {
								scroll = 0;
							}

							gBGTexture.render(gRenderer, 0, scroll);
							gBGTexture.render(gRenderer, 0, scroll - gBGTexture.getHeight());

							for (int i = 0; i < 4; i++)
							{
								if (_obstacle[i].getObstaclePositionY() == 600)
								{
									_obstacle[i].setZeroY();
									_obstacle[i].setRandomX();
									isTrueCollision[i] = false;
								}
							}

							SDL_Rect carRect;
							carRect.x = _car.getCarPositionX();
							carRect.y = _car.getCarPositionY();
							carRect.w = _car.CAR_WIDTH;
							carRect.h = _car.CAR_HEIGHT;

							for (int i = 0; i < 4; i++)
							{
								_obstacle[i].setNextY();
								gObstacle[i].render(gRenderer, _obstacle[i].getObstaclePositionX(), _obstacle[i].getObstaclePositionY());
								obstacleRect[i].x = _obstacle[i].getObstaclePositionX();
								obstacleRect[i].y = _obstacle[i].getObstaclePositionY();
								obstacleRect[i].w = 55;
								obstacleRect[i].h = 10;
								
								if (checkCollision(carRect, obstacleRect[i])) {
									if (isTrueCollision[i] == true)
									{

									}
									else {
										timeLimit -= 3;
										Mix_PlayChannel(-1, gCarCollision, 0);
										isTrueCollision[i] = true;
									}

								}
								else
								{
									isTrueCollision[i] = false;
								}

							}

							if (timeLimit - time_.getTicks() / 1000 <= 0) {
								bool isLoseGame = false;
								while (!isLoseGame) {
									while (SDL_PollEvent(&e)) {
										SDL_RenderClear(gRenderer);
										gLoseGame.render(gRenderer, 0, 0);
										SDL_RenderPresent(gRenderer);
										Mix_PlayMusic(gLoseGameSound, 1);
										if (e.type == SDL_QUIT) {
											isLoseGame = true;
											return 0;
										}
									}
								}
							}

							if (time_.getTicks() / 1000 >= 170) {
								gFinishLine.render(gRenderer, theFinishLine_.getFinishLinePositionX(), theFinishLine_.getFinishLinePositionY());
								theFinishLine_.setNextY();
								SDL_Rect finishLineRect;
								finishLineRect.x = theFinishLine_.getFinishLinePositionX();
								finishLineRect.y = theFinishLine_.getFinishLinePositionY();
								finishLineRect.w = THE_FINISH_LINE_WIDTH;
								finishLineRect.h = THE_FINISH_LINE_HEIGHT;

								if (checkCollision(carRect, finishLineRect) && timeLimit > 0) {
									bool isCollisionWithFinishLine = false;
									while (!isCollisionWithFinishLine) {
										while (SDL_PollEvent(&e)) {
											SDL_RenderClear(gRenderer);
											gWinGame.render(gRenderer, 0, 0);
											SDL_RenderPresent(gRenderer);
											Mix_PlayMusic(gWinGameSound, 1);
											if (e.type == SDL_QUIT) {
												return 0;
											}
										}
									}
								}
							}

							gCarTexture.render(gRenderer, _car.getCarPositionX(), _car.getCarPositionY());

							_car.move(gRenderer);

							gTimeBackgroundTexture.render(gRenderer, (SCREEN_WIDTH - gTimeBackgroundTexture.getWidth()) / 2, 0);

							gTimeTexture.render(gRenderer, (SCREEN_WIDTH - gTimeTexture.getWidth()) / 2, 0);

							gPauseTexture.render(gRenderer, 0, 0);

							gUnmuteTexture.render(gRenderer, SCREEN_WIDTH - MUTE_OR_NOT_WIDTH, 0);

							if (_pause.handlePauseEvent(&e, gRenderer) == true) {
								if (Mix_PlayingMusic() == 1) {
									Mix_PauseMusic();
								}
								
								time_.pause();
								bool isQuit = false;
								while (!isQuit)
								{
									while (SDL_PollEvent(&e))
									{
										if (_resume.handleResumeEvent(&e, gRenderer) == true) {
											
											if (Mix_PausedMusic() == 1) {
												Mix_PauseMusic();
											}
											else {
												Mix_ResumeMusic();
											}
											time_.unpause();
											isQuit = true;
										}
										else if (_quit.handleQuitEvent(&e, gRenderer) == true) {
											bool isQuitMenu = false;
											while (!isQuitMenu) {
												while (SDL_PollEvent(&e)) {
													if (_quitYes.handleQuitYesEvent(&e, gRenderer) == true) {
														close();
														return 0;
													}
													else if (_quitNo.handleQuitNoEvent(&e, gRenderer) == true) {
														isQuitMenu = true;
													}
												}
												SDL_RenderClear(gRenderer);
												gQuitYesTexture.render(gRenderer, 0, 0);
												SDL_RenderPresent(gRenderer);
											}
										}
									}

									SDL_RenderClear(gRenderer);
									gPauseGameTexture.render(gRenderer, 0, 0);
									SDL_RenderPresent(gRenderer);

								}
							}

							SDL_RenderPresent(gRenderer);
						}
					}
					SDL_RenderClear(gRenderer);
					gGameMenuTexture.render(gRenderer, 0, 0);
					SDL_RenderPresent(gRenderer);
				}
			}
		}
	}
	close();
	return 0;
}