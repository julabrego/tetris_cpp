#include "Tetromino.h"
#include <iostream>
#include <conio2.h>
using namespace std;

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

void Tetromino::fall(){
	y_pos++;
}

void Tetromino::moveRight(){
	x_pos++;
}

void Tetromino::moveLeft(){
	x_pos--;
}

void Tetromino::rotateRight(){
	
		int auxShape[4][4];

		for (int i = 3; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				auxShape[i][j] = shape[3 - j][i];
			}
		}
		
		setShapeOfTetromino(auxShape);
}

void Tetromino::rotateLeft(){
	int auxShape[4][4];
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			auxShape[i][j] = shape[j][3-i];
		}
	}
	
	setShapeOfTetromino(auxShape);
}

void Tetromino::setShapeOfTetromino(int auxShape[4][4]){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			shape[i][j] = auxShape[i][j];
		}
	}
}

bool Tetromino::bottomCollides(){
	int bottomLimit = 0;
	for(int i = 3; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			if(shape[i][j] == 2 && i > bottomLimit){
				bottomLimit = i;
			}
		}
	}
	
	if(y_pos + bottomLimit + 1 >= 21){
		return true;
	}
	
	return false;
}
