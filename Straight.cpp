#include "Straight.h"

Straight::Straight() {
	int straightShape[4][4] = {
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 0, 0}
	};
	
	setShapeOfTetromino(straightShape);
}

