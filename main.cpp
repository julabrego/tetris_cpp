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
			
			if(tecla == 120){
				currentTetromino->rotateRight();
			}else if(tecla == 122){
				currentTetromino->rotateLeft();
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

