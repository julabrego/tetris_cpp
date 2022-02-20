#ifndef GAME_H
#define GAME_H
#include <ctime>
#include "Tetromino.h"

class Game {
public:
	Game();
	Tetromino *generateNextTetromino();
	void spawnTetromino();
	Tetromino *currentTetromino;
	
	void isGameOver();
	
private:
	clock_t tempo = clock();
	int speed = 1;
	clock_t step = CLOCKS_PER_SEC/speed;
	
	bool playing = true;
};

#endif

	
