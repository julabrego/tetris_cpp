#include "Game.h"
#include <iostream>
#include "Board.h"
#include <conio2.h>
#include "TetrominoI.h"
#include "TetrominoL.h"
#include <ctime>
#include "TetrominoJ.h"
#include "TetrominoT.h"
#include "TetrominoZ.h"
#include "TetrominoS.h"
#include "TetrominoSquare.h"
using namespace std;

Board board;

Game::Game() {
	
	board.printBoard();

	currentTetromino = generateNextTetromino();
	board.setCurrentTetromino(*currentTetromino);
	
	while(playing){
		
		if(kbhit()) { 
			int tecla=getch();
			string directionToDetectCollision;
			if(tecla == 120 || tecla == 88){
				// X
				board.getCurrentTetromino()->rotateRight();
				directionToDetectCollision = "right";

			}else if(tecla == 122 || tecla == 90){
				// Z
				board.getCurrentTetromino()->rotateLeft();
				directionToDetectCollision = "left";
			}else if(tecla == 77){
				// move Right
				board.getCurrentTetromino()->setPosition(board.getCurrentTetromino()->getXPosition() + 1, board.getCurrentTetromino()->getYPosition());	
				directionToDetectCollision = "right";
			}else if(tecla == 75){
				// move Left
				board.getCurrentTetromino()->setPosition(board.getCurrentTetromino()->getXPosition() - 1, board.getCurrentTetromino()->getYPosition());
				directionToDetectCollision = "left";
			}else if(tecla == 80){
				// Down
				board.getCurrentTetromino()->setPosition(board.getCurrentTetromino()->getXPosition(), board.getCurrentTetromino()->getYPosition() + 1);
				directionToDetectCollision = "down";
			}
			
			board.correctPositionWhenMovementIsNotValid(directionToDetectCollision);
		}
		
		board.clearBoard();
		board.printTetromino();
		if(board.currentTetrominoIsCollidingWithFixedPiece()){
			board.fixCurrentTetromino();
			board.checkLines();
			isGameOver();
			spawnTetromino();
		}
		
		board.printBoard();
		
		if(tempo + step < clock()){
			board.getCurrentTetromino()->fall();
			tempo = clock();
		}
		
	}
	
}

Tetromino* Game::generateNextTetromino(){
	srand(time(NULL));
	
	int randomNumber = rand() % 7 + 1;
	
	Tetromino *nextTetromino;
	
	switch(randomNumber){
	case 1:
		nextTetromino = new TetrominoI();
		break;
	case 2:
		nextTetromino = new TetrominoL();
		break;
	case 3:
		nextTetromino = new TetrominoJ();
		break;
	case 4:
		nextTetromino = new TetrominoT();
		break;
	case 5:
		nextTetromino = new TetrominoZ();
		break;
	case 6:
		nextTetromino = new TetrominoS();
		break;
	case 7:
		nextTetromino = new TetrominoSquare();
		break;
	}
	
	return nextTetromino;
}

void Game::spawnTetromino(){
	currentTetromino = generateNextTetromino();
	board.setCurrentTetromino(*currentTetromino);
}

void Game::isGameOver(){
	playing = !board.isBoardFull();
}
