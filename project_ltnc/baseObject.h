#ifndef _BASE_OBJECT_H_
#define _BASE_OBJECT_H_

#include "commonFunction.h"

class LTexture {
public:
	LTexture();

	~LTexture();

	void free();

	bool loadFromFile(string path, SDL_Renderer* gRenderer);

	bool loadFromRenderedText(SDL_Renderer* renderer, string textTexture, SDL_Color textColor, TTF_Font* font);
	
	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	int getWidth();
	int getHeight();
private:
	SDL_Texture* mTexture;

	int mWidth, mHeight;
};

#endif _BASE_OBJECT_H_