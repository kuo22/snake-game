#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include "Coordinate.h"
#include <iostream>
#include <vector>

class Player {
public:
	Player(int x, int y, int xVel, int yVel);
	~Player();
	void setX(int x);
	void setY(int y);
	void setXVel(int xVel);
	void setYVel(int yVel);
	int getX();
	int getY();
	int getXVel();
	int getYVel();
	void addBody(int x, int y);
	bool collideBody(std::vector<std::vector<int>> &map);

	bool justAte;
	int length = 3;
	int x;
	int y;
	int xVel;
	int yVel;
	std::deque<Coordinate> coordinates;
};

#endif // !
