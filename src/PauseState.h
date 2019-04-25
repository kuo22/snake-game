#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "StateManager.h"
#include "GameState.h"

class PauseState : public GameState {
public:
	void init(StateManager* game) { }
	void clean() {}

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void render(StateManager* game);

	void pause() { }
	void resume() { }

	static PauseState* instance() {
		return &pauseState;
	}

	static PauseState pauseState;


};

#endif // !

