/*
 * SGTimer.cpp
 *
 *  Created on: Dec 21, 2013
 *      Author: jonno
 */

#include "SGTimer.h"
#include <SDL2/SDL.h>

namespace sge_base {

SGTimer::SGTimer() {
	isStarted = false;
	isRunning = false;
	startTime = SDL_GetTicks();
}

SGTimer::~SGTimer() {
}

void SGTimer::start() {
	if (!isStarted) {
		startTime =  SDL_GetTicks();
		isStarted = true;
		isRunning =  true;
	}
}

void SGTimer::restart() {
	stop();
	start();
}

void SGTimer::stop() {
	if (isStarted) {
		isStarted = false;
		isRunning = false;
	}
}

Uint32 SGTimer::getTime() {
	if (isStarted && isRunning) {
		return SDL_GetTicks() - startTime;
	}
	return 0;
}

} /* namespace sge_base */
