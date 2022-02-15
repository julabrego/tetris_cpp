#include "Game.h"
#include <iostream>
#include "Board.h"
#include <conio2.h>
#include "TetrominoI.h"
#include "TetrominoL.h"
using namespace std;

Game::Game() {
	Board board;
	board.printBoard();
	
	playing = true;

	//Tetromino tetromino;
	
	Tetromino *currentTetromino = generateNextTetromino();
	board.setCurrentTetromino(*currentTetromino);
	
	while(playing){
		
		if(kbhit()) { 
			int tecla=getch();
//			cout << tecla;
			if(tecla == 120){
				// X
				board.getCurrentTetromino()->rotateRight();
			}else if(tecla == 122){
				// Z
				board.getCurrentTetromino()->rotateLeft();
			}else if(tecla == 77){
				// Right
				board.getCurrentTetromino()->setPosition(board.getCurrentTetromino()->getXPosition() + 1, board.getCurrentTetromino()->getYPosition());
			}else if(tecla == 75){
				// Left
				board.getCurrentTetromino()->setPosition(board.getCurrentTetromino()->getXPosition() - 1, board.getCurrentTetromino()->getYPosition());
			}
			
		}
		
		board.clearBoard();
		board.printTetromino();
		board.printBoard();
		
		if(tempo + step < clock()){
			board.getCurrentTetromino()->fall();
			tempo = clock();
		}
		
	}
	
}

Tetromino* Game::generateNextTetromino(){
//	Tetromino *tetrominoI = new TetrominoI();
	Tetromino *tetrominoI = new TetrominoL();
	return tetrominoI;
}

