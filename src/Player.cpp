#include "Player.h"
int const CELL_WIDTH = 10;

Player::Player(int x, int y, int xVel, int yVel) {
	this->x = x;
	this->y = y;
	this->xVel = xVel;
	this->yVel = yVel;
	for (int i = 0; i < length; i++) {
		Coordinate coordinate;
		coordinate.x = x;
		coordinate.y = y + i;
		coordinates.push_front(coordinate);
	}
}

Player::~Player() {}

int Player::getX() { return x; }
int Player::getY() { return y; }
int Player::getXVel() { return xVel; }
int Player::getYVel() { return yVel; }
void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }
void Player::setXVel(int xVel) { this->xVel = xVel; }
void Player::setYVel(int yVel) { this->yVel = yVel; }

void Player::addBody(int x, int y) {
	Coordinate coordinate;
	coordinate.x = x;
	coordinate.y = y;
	coordinates.push_back(coordinate);
}

bool Player::collideBody(std::vector<std::vector<int>> &map) {
	return map[y][x] == 1;
}