#include "Board.h"
#include <iostream>
#include <conio2.h>
#include "Tetromino.h"

#include <cstdlib>
#include <ctime>
using namespace std;

int lines = 0;

Board::Board() {
};

void Board::printBoard(){
	const char BOX = 'O';
	
	for (int i = 0; i < 12; i++){
		for (int k = 0; k < 22; k++){
			textcolor(colorBox(board[k][i]));
			putchxy(2+i,2+k,board[k][i]);
			putchxy(2+i,2+k,BOX);
//			putchxy(2+i,2+k,board[k][i]);
		}
	}
};

int Board::colorBox(int box){
	const int BLACK = 0;
	const int LIGHTGREY = 7;
	const int GREEN = 2;
	const int RED = 4;
	
	switch(box){
	case 0: return BLACK; break;
	case 1: return LIGHTGREY;  break;
	case 2: return GREEN; break;
	case 3: return RED; break;
	default: return BLACK;

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
			if((currentTetromino.shape[i][j] != 0)
				&&
				(currentTetromino.getYPosition() + i < 21)){
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
			if((currentTetromino.shape[i][j] == 2 && emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 3)
				||
				(currentTetromino.shape[i][j] == 2 && emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 1)){
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

bool Board::isValidRight(){
	for (int i = 0; i < 4; i++){
		for (int j = 3; j >= 0; j--){
			if(currentTetromino.shape[i][j] == 2){
				if(board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j + 1] != 0){
					return false;
				}
			}
		}
	}
	return true;
}

bool Board::isValidLeft(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if(currentTetromino.shape[i][j] == 2){
				if(board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j - 1] != 0){
					return false;
				}
			}
		}
	}
	return true;
}

void Board::rotateTetrominoRightIfValid(){
	currentTetromino.rotateRight();
	correctPositionAfterRightRotation();
}

void Board::correctPositionAfterRightRotation(){
	for(int i = 0; i < 4; i++){
		for(int j = 3; j >= 2; j--){
			if(currentTetromino.shape[i][j] == 2){
			   if(emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] != 0){
				currentTetromino.setPosition(currentTetromino.getXPosition() - 1, currentTetromino.getYPosition());
				correctPositionAfterRightRotation();
			   }
			}
		}
	}
}

void Board::rotateTetrominoLeftIfValid(){
	currentTetromino.rotateLeft();
	correctPositionAfterLeftRotation();
}

void Board::correctPositionAfterLeftRotation(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			if(currentTetromino.shape[i][j] == 2){
				if(emptyBoard[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] != 0){
					currentTetromino.setPosition(currentTetromino.getXPosition() + 1, currentTetromino.getYPosition());
					correctPositionAfterLeftRotation();
				}
			}
		}
	}
}

void Board::correctPositionWhenMovementIsNotValid(string direction){
	if(direction != "down"){
		for(int i = 0; i < 4; i ++){
			for(int j = 0; j < 4; j++){
				if(currentTetromino.shape[i][j] != 0){
					while(board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 1
						||
						board[currentTetromino.getYPosition() + i][currentTetromino.getXPosition() + j] == 3){
						
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
				clearLine(i);
				j = 1;
			}
		}
	}	
}

void Board::clearLine(int linea){
	for(int i = linea; i > 1; i--){
		for(int j = 1; j < 11; j++){	
			board[i][j] = board[i - 1][j];
			emptyBoard[i][j] = emptyBoard[i -1][j];
		}
	}
	
	lines++;
	gotoxy(23, 2);
	cout << lines;
}

bool Board::isBoardFull(){
	for(int i = 1; i < 11; i++){
		if(board[1][i] == 3) return true;
	}
	return false;
}
