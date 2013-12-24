/*
 * MyEngine.cpp
 *
 *  Created on: Dec 21, 2013
 *      Author: jonno
 */

#include "MyEngine.h"
#include "base/SGTexture.h"
#include "base/util/SGText.h"

namespace sge_base {

int x = 0, y = 0;



MyEngine::MyEngine() : SGEngine("Lolol", 640, 480) {
	// TODO Auto-generated constructor stub

	img = new SGTexture("image.bmp" , this->renderer );
	text = new SGText(this->renderer);
	this->text->setFont("Moon Flower.ttf");
	this->text->setText("LOOOL");
}

MyEngine::~MyEngine() {

}

void MyEngine::paint() {
	this->img->paint(x,y);
}

void MyEngine::update() {
	x++;
	y++;
}

void MyEngine::handleKey(SDL_KeyboardEvent e) {
	if (e.type == SDL_KEYUP) {
		if (e.keysym.sym == SDLK_q) {
			this->stopGame();
		}
	}
}

} /* namespace sge_base */
