#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino {
private:
	
protected:
	void setShapeOfTetromino(int auxShape[4][4]);
	
public:
	int shape[4][4];
	int x_pos, y_pos;
	Tetromino();
	void rotateLeft();
	void rotateRight();
	void setPosition(int x, int y);
	int getXPosition();
	int getYPosition();
	void fall();

};

#endif

