/*
 * Tester.cpp
 *
 *  Created on: Dec 20, 2013
 *      Author: jonno
 */

#include <iostream>
#include "base/SGTexture.h"
#include "base/SGEngine.h"
#include "MyEngine.h"

using namespace sge_base;
using namespace std;

int main () {
	MyEngine * g = new MyEngine();

	g->runGame();

 	cout << "LOLZ" << endl;
	return 0;
}


