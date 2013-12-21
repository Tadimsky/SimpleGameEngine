/*
 * Texture.h
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

namespace sge_base {

class Texture {
private:
	SDL_Texture * texture;
	SDL_Rect * srcRect;
	SDL_Renderer * renderer;

	void loadTextureInfo(int x = 0, int y = 0, int w = -1, int h = -1);
public:
	Texture(const string &file, SDL_Renderer * renderer);
	Texture(const string &file, SDL_Renderer * renderer, int x, int y);
	Texture(const string &file, SDL_Renderer * renderer, int x, int y, int w, int h);
	virtual ~Texture();
	void paint(int x, int y);
	void paint(int x, int y, int w, int h);
};

} /* namespace sge_base */

#endif /* TEXTURE_H_ */
