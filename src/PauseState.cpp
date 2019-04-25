#include "PauseState.h"

PauseState PauseState::pauseState;

void PauseState::handleEvents(StateManager* game) {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		game->quit();
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_SPACE:
			game->popState();
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void PauseState::update(StateManager* game) {

}

void PauseState::render(StateManager* game) {
	SDL_SetRenderDrawColor(game->renderer, 45, 0, 45, 255);
	SDL_RenderClear(game->renderer);
	SDL_RenderPresent(game->renderer);
}