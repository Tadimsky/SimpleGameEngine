/*
 * Texture.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;
namespace sge_base {


Texture::Texture(const string &file, SDL_Renderer * renderer) {
	SDL_Texture * text = IMG_LoadTexture(renderer, file.c_str());
	if (text == nullptr) {
		//logSDLError(cout, "LoadTexture");
	}
	int w, h;
	SDL_QueryTexture(text, NULL, NULL, &w, &h);
	Texture(file, renderer, 0, 0, w, h);
}
Texture::Texture(const string &file, SDL_Renderer * renderer, int x, int y) {
	SDL_Texture * text = IMG_LoadTexture(renderer, file.c_str());
	if (text == nullptr) {
		//logSDLError(cout, "LoadTexture");
	}
	int w, h;
	SDL_QueryTexture(text, NULL, NULL, &w, &h);
	Texture(file, renderer, x, y, w, h);
}
Texture::Texture(const string &file, SDL_Renderer * renderer, int x, int y, int w, int h) {
	SDL_Texture * text = IMG_LoadTexture(renderer, file.c_str());
	if (text == nullptr) {
		//logSDLError(cout, "LoadTexture");
	}

	this->texture = IMG_LoadTexture(renderer, file.c_str());
	if (this->texture == nullptr) {

	}
	this->srcRect = new SDL_Rect();
	this->srcRect->w = w;
	this->srcRect->h = h;
	this->srcRect->x = x;
	this->srcRect->y = y;
}

Texture::~Texture() {
	SDL_DestroyTexture(this->texture);
}

} /* namespace sge_base */
