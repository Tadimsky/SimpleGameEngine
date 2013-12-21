/*
 * SGEngine.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include "SGEngine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace sge_base {

SGEngine::SGEngine(const string& wndtext, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			SGEngine::logSDLError(cout, "SDL_Init");
			return;
	}
	this->window = SDL_CreateWindow(wndtext.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);
		if (this->window == nullptr) {
			logSDLError(cout, "CreateWindow");
		return;
	}

	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		logSDLError(cout, "CreateRenderer");
		return;
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
		logSDLError(cout, "IMG_Init");
		return;
	}
}

SGEngine::~SGEngine() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
}

void SGEngine::clearScreen() {
	SDL_RenderClear(this->renderer);
}

void SGEngine::renderScreen() {
	SDL_RenderPresent(this->renderer);
}

void SGEngine::logSDLError(ostream &os, const string &msg) {
	os << msg << " : " << SDL_GetError() << endl;
}

} /* namespace sge_base */
