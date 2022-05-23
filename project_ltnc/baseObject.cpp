#include "baseObject.h"

LTexture::LTexture() {
	mTexture = NULL;

	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture() {
	free();
}

void LTexture::free() {
	if (mTexture == NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;

		mWidth = 0;
		mHeight = 0;
	}
}

bool LTexture::loadFromFile(string path, SDL_Renderer* renderer) {
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		cout << "Can not load surface: " << path << ". Error: " << IMG_GetError() << endl;
	}
	else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 255, 255));
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) {
			cout << "Can not load texture: " << path << ". Error: " << SDL_GetError() << endl;
		}
		else {
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;

			SDL_FreeSurface(loadedSurface);
		}
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(SDL_Renderer* renderer, string textTexture, SDL_Color textColor, TTF_Font* font) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textTexture.c_str(), textColor);
	if (textSurface == NULL) {
		cout << "Can not render text surface! Error: " << TTF_GetError() << endl;
	}
	else {
		mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (mTexture == NULL) {
			cout << "Can not render text texture! Error: " << SDL_GetError() << endl;
		}
		else {
			mWidth = textSurface->w;
			mHeight = textSurface->h;

			SDL_FreeSurface(textSurface);
		}
	}
	return mTexture != NULL;
}

void LTexture::render(SDL_Renderer* renderer,int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderSquad = { x, y, mWidth, mHeight };
	if (clip != NULL) {
		renderSquad.w = clip->w;
		renderSquad.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, mTexture, clip, &renderSquad, angle, center, flip);
}

int LTexture::getWidth() {
	return mWidth;
}

int LTexture::getHeight() {
	return mHeight;
}