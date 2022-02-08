#include "Board.h"
#include <iostream>
#include <conio2.h>
#include "Tetromino.h"
#include "Straight.h"
using namespace std;

Board::Board() {
};

void Board::printBoard(){
	for(int i = 0; i < 22; i++){
		for(int j = 0; j < 12; j++){
			textcolor(colorBox(board[i][j]));
			cout << board[i][j];
		}
		cout << endl;
	}
};

int Board::colorBox(int box){
	switch(box){
	case 0: return 8; // DARKGREY
	case 1: return 7; // LIGHTGREY
	};
}

void Board::createTetromino(){
	Tetromino *tetromino = new Straight;
	tetromino->setPosition(4,4);
	
	// Imprimir Tetromino
	for(int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			board[tetromino->getYPosition() + i][tetromino->getXPosition() + j] = tetromino->shape[i][j];
		}
	}
}
