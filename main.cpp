#include<iostream>
#include "Board.h"

using namespace std;

int main (int argc, char *argv[]) {
	Board board;
	board.createTetromino();
	board.printBoard();
	return 0;
}

