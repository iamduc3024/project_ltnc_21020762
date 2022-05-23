#ifndef _ITEM_H_
#define _ITEM_H_

#include "commonFunction.h"
#include "baseObject.h"

class pause : public LTexture
{
public:
	bool handlePauseEvent(SDL_Event* e, SDL_Renderer* renderer);
};


class resume : public LTexture
{
public:
	bool handleResumeEvent(SDL_Event* e, SDL_Renderer* renderer);
};


class quit : public LTexture
{
public:
	bool handleQuitEvent(SDL_Event* e, SDL_Renderer* renderer);
};


class quitYes : public LTexture
{
public:
	bool handleQuitYesEvent(SDL_Event* e, SDL_Renderer* renderer);
};


class quitNo : public LTexture
{
public:
	bool handleQuitNoEvent(SDL_Event* e, SDL_Renderer* renderer);
};

class muteOrNot : public LTexture
{
public:
	bool handleMuteOrNot(SDL_Event* e, SDL_Renderer* renderer);
};

#endif _ITEM_H_