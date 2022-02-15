#include "TetrominoL.h"

TetrominoL::TetrominoL() {
	int shapeL[4][4] = {
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0}
	};
	
	setShapeOfTetromino(shapeL);	
}

