#ifndef _COMMON_FUNCTION_H_
#define _COMMON_FUNCTION_H_

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

using namespace std;

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;
static TTF_Font* gFont = NULL;
static Mix_Music* gSoundCarEffect = NULL;
static Mix_Chunk* gCarCollision = NULL;
static Mix_Music* gSoundBackground = NULL;
static Mix_Music* gWinGameSound = NULL;
static Mix_Music* gLoseGameSound = NULL;

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 600;

const int PAUSE_WIDTH = 50;
const int PAUSE_HEIGHT = 50;

const int RESUME_WIDTH = 200;
const int RESUME_HEIGHT = 100;

const int QUIT_WIDTH = 200;
const int QUIT_HEIGHT = 100;

const int QUIT_YES_WIDTH = 200;
const int QUIT_YES_HEIGHT = 100;
const int QUIT_YES_TOP_POSITION = 200;

const int QUIT_NO_WIDTh = 200;
const int QUIT_NO_HEIGHT = 100;
const int QUIT_NO_TOP_POSITION = 350;

const int MUTE_OR_NOT_WIDTH = 50;
const int MUTE_OR_NOT_HEIGHT = 50;

const int OBSTACLE_WIDTH = 55;
const int OBSTACLE_HEIGHT = 10;

const int THE_FINISH_LINE_WIDTH = 360;
const int THE_FINISH_LINE_HEIGHT = 50;

const int PLAY_LEFT_POSITION = 110;
const int PLAY_RIGHT_POSITION = 225;
const int PLAY_TOP_POSITION = 395;
const int PLAY_BOTTOM_POSITION = 440;

const int EXIT_LEFT_POSITION = 275;
const int EXIT_RIGHT_POSITION = 385;
const int EXIT_TOP_POSITION = 395;
const int EXIT_BOTTOM_POSITION = 440;

const int ROAD_SIDE = 70;

#endif _COMMON_FUCNTION_H_