#include "Food.h"


Food::Food(int maxX, int maxY, std::vector<std::vector<int>> &map) {
	this->maxX = maxX;
	this->maxY = maxY;
	this->map = &map;
	spawn();
}
Food::~Food() {}

void Food::spawn() {
	int randX;
	int randY;
	srand(time(0));
	do {
		randX = rand() % maxY;
		randY = rand() % maxX;
		if (map->operator[](randY).operator[](randX) == 0) {
			x = randX;
			y = randY;
			map->operator[](randY).operator[](randX) = 2;
		}
	} while (map->operator[](randY).operator[](randX) == 0);
}