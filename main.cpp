#include<iostream>
#include "Board.h"
#include <conio2.h>
#include <ctime>
#include "Tetromino.h"
#include "Straight.h"
using namespace std;

int main (int argc, char *argv[]) {
	Board board;
	
	Straight tetromino;
	board.setCurrentTetromino(tetromino);
	Tetromino currentTetromino = board.getCurrentTetromino();
	
	while(true){
		
		board.printTetromino();
		board.printBoard();
		
		if(kbhit()) { 
			int tecla=getch();
			
			if(tecla == 120){
				currentTetromino.rotateRight();
				board.setCurrentTetromino(currentTetromino);
				board.printTetromino();
				
			}else if(tecla == 122){
				currentTetromino.rotateLeft();
				board.setCurrentTetromino(currentTetromino);
				board.printTetromino();
			}
			
		}
		
	}
	
	return 0;
}

