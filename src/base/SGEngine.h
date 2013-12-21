/*
 * SGEngine.h
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#ifndef SGENGINE_H_
#define SGENGINE_H_


#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>

using namespace std;
namespace sge_base {

class SGEngine {
private:

	SDL_Window * window;

public:
	SGEngine(const string &wndtext, int width = 640, int height = 480);

	SDL_Renderer * renderer;

	virtual ~SGEngine();

	SDL_Renderer * getRenderer();

	void clearScreen();

	void renderScreen();

	static void logSDLError(ostream &os, const string &msg);
};

} /* namespace sge_base */

#endif /* SGENGINE_H_ */
