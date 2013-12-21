/*
 * Tester.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include <iostream>
#include "base/Texture.h"
#include "base/SGEngine.h"

using namespace sge_base;
using namespace std;

int main () {
	SGEngine * g = new SGEngine("Yolomir", 640, 480);
	SGEngine lolz = *g;
	Texture * img = new Texture("image.bmp" , (g->renderer));

	int x = 0, y = 0;
	while (true) {
		g->clearScreen();
		img->paint(x, y);
		g->renderScreen();
		x++;
		y++;
	}
 	cout << "LOLZ" << endl;
	return 0;
}


