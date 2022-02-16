#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino {
private:
	int x_pos, y_pos;
protected:
	void setShapeOfTetromino(int auxShape[4][4]);
	
public:
	Tetromino();
	int shape[4][4];
	void rotateLeft();
	void rotateRight();
	void setPosition(int x, int y);
	int getXPosition();
	int getYPosition();
	void fall();

};

#endif

