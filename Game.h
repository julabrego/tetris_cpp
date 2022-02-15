#ifndef GAME_H
#define GAME_H
#include <ctime>

class Game {
public:
	Game();
	
private:
	clock_t tempo = clock();
	int speed = 1;
	clock_t step = CLOCKS_PER_SEC/speed;
	
	bool playing;
};

#endif

	
