#include "Tetromino.h"

Tetromino::Tetromino() {
	
}

void Tetromino::setPosition(int x, int y){
	x_pos = x;
	y_pos = y;
}

int Tetromino::getXPosition(){
	return x_pos;
}

int Tetromino::getYPosition(){
	return y_pos;
}
