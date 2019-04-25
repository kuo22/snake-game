#ifndef FOOD_H
#define FOOD_H

#include "Player.h"
#include <stdlib.h>
#include <time.h> 
#include <vector>

class Food {
public:
	Food(int maxX, int maxY, std::vector<std::vector<int>> &map);
	~Food();

	void spawn();

	int x;
	int y;
	int maxX;
	int maxY;
	std::vector<std::vector<int>> *map;
private:
};
#endif // !FOOD_H
