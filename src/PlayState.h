#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include "Food.h"
#include "Coordinate.h"
#include "Player.h"


class PlayState : public GameState {
public:
	void init(StateManager* game);
	void clean();

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void render(StateManager* game);

	void pause();
	void resume();
	void reset(StateManager* game);

	static PlayState* instance() {
		return &playState;
	}

	static PlayState playState;
private:
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	std::vector<std::vector<int>> map;
	Player *player;
	Food *food;
};

#endif // !PLAYSTATE_H
