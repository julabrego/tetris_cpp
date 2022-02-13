#include "TetrominoI.h"

TetrominoI::TetrominoI() {
	int shapeI[4][4] = {
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 0, 0}
	};
	
	setShapeOfTetromino(shapeI);
}

