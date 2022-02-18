#include "Board.h"
#include <iostream>
#include <conio2.h>
#include "Tetromino.h"

using namespace std;

Board::Board() {
};

void Board::printBoard(){
	const char BOX = 'O';
	
	for (int i = 0; i < 12; i++){
		for (int k = 0; k < 22; k++){
			textcolor(colorBox(board[k][i]));
			gotoxy(i + 1,k + 1);
			cout << board[k][i];
//			putchxy(2+i,2+k,board[k][i]);
//			putchxy(2+i,2+k,BOX);
		}
	}
};

int Board::colorBox(int box){
	const int BLACK = 0;
	const int DARKGREY = 8;
	const int LIGHTGREY = 7;
	switch(box){
	case 0: return BLACK; // DARKGREY
	case 1: return LIGHTGREY; // LIGHTGREY
	};
}

void Board::setCurrentTetromino(Tetromino _tetromino){
	_tetromino.setPosition(4,1);
	currentTetromino = _tetromino;
}

void Board::printTetromino(){
	// Imprimir Tetromino
	for(int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if(currentTetromino.shape[i][j] != 0){
				board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] = currentTetromino.shape[i][j];	
			}
		}
	}
}

Tetromino* Board::getCurrentTetromino(){
	return &currentTetromino;
}

void Board::clearBoard(){
	for(int i = 1; i < 21; i++){
		for(int j = 1; j < 11; j++){
			board[i][j] = emptyBoard[i][j];
		}
	}
}

void Board::currentTetrominoCollides(){
	if(currentTetromino.bottomCollides()){
		for(int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				if(currentTetromino.shape[i][j] != 0){
					board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] = 3;
					emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] = 3;	
				}
			}
		}
		
		currentTetromino.setPosition(4, 0);
	}
	
//	cout << "a: " << emptyBoard[currentTetromino.getYPosition()][currentTetromino.getXPosition()];
}

bool Board::currentTetrominoIsCollidingWithFixedPiece(){
	
	for(int i = 3; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			if(currentTetromino.shape[i][j] == 2 && emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 3){
				return true;
			}
		}
	}
	
	return false;
	
}

void Board::fixCurrentTetromino(){
	for(int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if(currentTetromino.shape[i][j] != 0){
				board[currentTetromino.getYPosition() + i - 1][currentTetromino.getXPosition() + j] = 3;
				emptyBoard[currentTetromino.getYPosition() + i - 1][currentTetromino.getXPosition() + j] = 3;	
			}
		}
	}
	
}
