#include "TetrominoSquare.h"

TetrominoSquare::TetrominoSquare() {
	int shape[4][4] = {
		{0, 0, 0, 0},
		{0, 2, 2, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0}
	};
	
	setShapeOfTetromino(shape);
}

