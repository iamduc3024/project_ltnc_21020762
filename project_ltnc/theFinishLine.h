#ifndef _THE_FINISH_LINE_H_
#define _THE_FINISH_LINE_H_

#include "commonFunction.h"
#include "baseObject.h"

class theFinishLine {
public:
	theFinishLine();

	void setPosition();

	int getFinishLinePositionX();
	int getFinishLinePositionY();

	void setNextY();
private:
	int theFinishLinePositionX, theFinishLinePositionY;
};

#endif _THE_FINISH_LINE_H_