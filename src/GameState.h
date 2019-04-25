#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "StateManager.h"
class StateManager;

class GameState {
public:
	virtual void init(StateManager* game) = 0;
	virtual void clean() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents(StateManager* game) = 0;
	virtual void update(StateManager* game) = 0;
	virtual void render(StateManager* game) = 0;

	void changeState(StateManager* game, GameState* state) {
		game->changeState(state);
	}

protected:
	GameState() { }

};
#endif // !GAMESTATE_H
