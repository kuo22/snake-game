#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "SDL.h"
#include <vector>

const int CELL_WIDTH = 10;
class GameState;

class StateManager {
public:
	void init(const char* title, int x, int y, int w, int h);
	void clean();
	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState();
	bool running() { return isRunning; }
	void quit() { isRunning = false; }

	void handleEvents();
	void update();
	void render();

	SDL_Window* window;
	SDL_Renderer* renderer;
	int w;
	int h;

private:
	std::vector<GameState*> states;
	bool isRunning;
};

#endif // !STATEMANAGER_H

