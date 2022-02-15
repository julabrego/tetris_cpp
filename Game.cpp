#include "Game.h"
#include <iostream>
#include "Board.h"
#include <conio2.h>
using namespace std;

Game::Game() {
	Board board;
	board.printBoard();
	
	playing = true;

	Tetromino tetromino;
//	board.insertTetromino();
	board.setCurrentTetromino(tetromino);
	Tetromino *currentTetromino = board.getCurrentTetromino();
	
	while(playing){
		
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
		
		if(tempo + step < clock()){
			currentTetromino->fall();
			tempo = clock();
		}
		
	}
	
}

