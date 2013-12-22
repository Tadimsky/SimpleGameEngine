/*
 * MyEngine.h
 *
 *  Created on: Dec 21, 2013
 *      Author: jonno
 */

#ifndef MYENGINE_H_
#define MYENGINE_H_

#include "base/SGEngine.h"
#include "base/SGTexture.h"

namespace sge_base {

class MyEngine: public SGEngine {

private:
	SGTexture * img;

public:
	MyEngine();
	virtual ~MyEngine();
	virtual void update();
	virtual void paint();

	virtual void handleKey(SDL_KeyboardEvent e);
};

} /* namespace sge_base */

#endif /* MYENGINE_H_ */
