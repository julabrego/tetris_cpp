#include "TetrominoL.h"

TetrominoL::TetrominoL() {
	int shape[4][4] = {
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0}
	};
	
	setShapeOfTetromino(shape);	
}

