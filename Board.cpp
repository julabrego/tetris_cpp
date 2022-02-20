#include "Board.h"
#include <iostream>
#include <conio2.h>
#include "Tetromino.h"

#include <cstdlib>
#include <ctime>
using namespace std;

Board::Board() {
};

void Board::printBoard(){
	const char BOX = 'O';
	
	for (int i = 0; i < 12; i++){
		for (int k = 0; k < 22; k++){
			textcolor(colorBox(board[k][i]));
			//gotoxy(i + 1,k + 1);
			//cout << board[k][i];
			putchxy(2+i,2+k,board[k][i]);
			putchxy(2+i,2+k,BOX);
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

bool Board::currentTetrominoIsCollidingWithFixedPiece(){
	
	for(int i = 3; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			if(currentTetromino.shape[i][j] == 2 && emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 3
				||
				currentTetromino.shape[i][j] == 2 && emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 1){
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


void Board::correctPositionWhenMovementIsNotValid(string direction){
	if(direction == "right"){
		for(int i = 0; i < 4; i ++){
			for(int j = 3; j >= 0; j--){
				if(currentTetromino.shape[i][j] != 0){
					if(board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 1
						||
						board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 3){
						currentTetromino.setPosition(currentTetromino.getXPosition() - 1, currentTetromino.getYPosition());
					}
				}
			}
		}
	}else if(direction == "left"){
		for(int i = 0; i < 4; i ++){
			for(int j = 0; j < 4; j++){
				if(currentTetromino.shape[i][j] != 0){
					if(board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 1
						||
						board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 3){
						currentTetromino.setPosition(currentTetromino.getXPosition() + 1, currentTetromino.getYPosition());
					}
				}
			}
		}
	}
}

void Board::checkLines(){
	int j;

	for (int i = 20; i > 1; i--){
		j = 1;

		while(j < 11 && emptyBoard[i][j] != 0){
			j++;
			
			if(j >= 11) {
				gotoxy(14,20);
				cout << "linea";
				clearLine(i);
				j = 1;
			}
		}
	}	
}

void Board::clearLine(int linea){
	for(int i = linea; i > 1; i--){
		for(int j = 1; j < 11; j++){
//			board[i][j] = 0;
//			emptyBoard[i][j] = 0;
			
			board[i][j] = board[i - 1][j];
			emptyBoard[i][j] = emptyBoard[i -1][j];
		}
	}
	gotoxy(14,23);
	cout << " clearline";
}

bool Board::isBoardFull(){
	for(int i = 1; i < 11; i++){
		if(board[1][i] == 3) return true;
	}
	return false;
}
