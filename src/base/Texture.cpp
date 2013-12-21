/*
 * Texture.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SGEngine.h"

using namespace std;
namespace sge_base {


void Texture::loadTextureInfo(int x, int y, int w, int h) {
	if (w < 0 && h < 0) {
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	}
	this->srcRect = new SDL_Rect();
	this->srcRect->w = w;
	this->srcRect->h = h;
	this->srcRect->x = x;
	this->srcRect->y = y;
}

Texture::Texture(const string &file, SDL_Renderer * renderer) {
	this->renderer = renderer;
	this->texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture == nullptr) {
		SGEngine::logSDLError(cout, "LoadTexture");
	}
	loadTextureInfo();
}
Texture::Texture(const string &file, SDL_Renderer * renderer, int x, int y) : Texture(file, renderer){
	loadTextureInfo(x, y);
}
Texture::Texture(const string &file, SDL_Renderer * renderer, int x, int y, int w, int h) : Texture(file, renderer) {
	loadTextureInfo(x, y, w, h);
}

Texture::~Texture() {
	SDL_DestroyTexture(this->texture);
}

void Texture::paint(int x, int y) {
	paint(x, y, srcRect->w, srcRect->h);
}

void Texture::paint(int x, int y, int w, int h) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(this->renderer, this->texture, NULL, &dst);
}

} /* namespace sge_base */
