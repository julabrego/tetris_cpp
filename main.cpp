#include<iostream>
#include "Board.h"
#include <conio2.h>
#include <ctime>
#include "Tetromino.h"
#include "TetrominoI.h"
using namespace std;

int main (int argc, char *argv[]) {
	Board board;
	
	TetrominoI tetromino;
	board.setCurrentTetromino(tetromino);
	Tetromino* currentTetromino = board.getCurrentTetromino();
	
	clock_t tempo = clock();
	int velocidad = 1;
	clock_t paso = CLOCKS_PER_SEC/velocidad;
	
	while(true){
		
		if(kbhit()) { 
			int tecla=getch();
//			cout << tecla;
			if(tecla == 120){
				// X
				currentTetromino->rotateRight();
			}else if(tecla == 122){
				// Z
				currentTetromino->rotateLeft();
			}else if(tecla == 77){
				// Right
				currentTetromino->setPosition(currentTetromino->getXPosition() + 1, currentTetromino->getYPosition());
			}else if(tecla == 75){
				// Left
				currentTetromino->setPosition(currentTetromino->getXPosition() - 1, currentTetromino->getYPosition());
			}
			
		}
		
		board.clearBoard();
		board.printTetromino();
		board.printBoard();
		
		if(tempo + paso < clock()){
			currentTetromino->fall();
			tempo = clock();
		}
		
	}
	
	return 0;
}

