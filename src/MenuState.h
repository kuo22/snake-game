#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "StateManager.h"
#include "GameState.h"
#include "SDL_ttf.h"

class MenuState : public GameState {
public:
	void init(StateManager* game);
	void clean();

	void handleEvents(StateManager* game);
	void update(StateManager* game);
	void render(StateManager* game);

	void pause() { }
	void resume() { }

	static MenuState* instance() {
		return &menuState;
	}

	static MenuState menuState;

	TTF_Font* font;
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Texture* texture2;
};
#endif // !MENUSTATE_H
