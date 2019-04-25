#include "StateManager.h"
#include "GameState.h"
#include <iostream>
#include "SDL_ttf.h"	

void StateManager::init(const char* title, int x, int y, int w, int h) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Error" << std::endl;
		isRunning = false;
	}
	TTF_Init();
	this->w = w;
	this->h = h;

	window = SDL_CreateWindow(title, x, y, w * CELL_WIDTH, h * CELL_WIDTH, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	isRunning = true;
}

void StateManager::clean() {
	while (!states.empty()) {
		states.back()->clean();
		states.pop_back();
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Cleaned" << std::endl;
}

void StateManager::changeState(GameState* state) {
	if (!states.empty()) {
		states.back()->clean();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->init(this);
}

void StateManager::pushState(GameState* state) {
	if (!states.empty()) {
		states.back()->pause();
	}

	states.push_back(state);
	states.back()->init(this);
}

void StateManager::popState() {
	if (!states.empty()) {
		states.back()->clean();
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->resume();
	}
}

void StateManager::handleEvents() {
	states.back()->handleEvents(this);
}

void StateManager::update() {
	states.back()->update(this);
}

void StateManager::render() {
	states.back()->render(this);
}