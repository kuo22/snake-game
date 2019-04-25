#include "SDL_ttf.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>
MenuState MenuState::menuState;

void MenuState::init(StateManager* game) {
	font = TTF_OpenFont("arial.ttf", 25);
	SDL_Color color = { 255, 255, 255 };
	surface = TTF_RenderText_Solid(font, "Snake Game", color);
	texture = SDL_CreateTextureFromSurface(game->renderer, surface);
	surface = TTF_RenderText_Solid(font, "Press space to start", color);
	texture2 = SDL_CreateTextureFromSurface(game->renderer, surface);
}

void MenuState::clean() {
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(texture2);
	SDL_FreeSurface(surface);
}

void MenuState::handleEvents(StateManager* game) {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		game->quit();
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_SPACE:
			game->changeState(PlayState::instance());
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void MenuState::update(StateManager* game) {

}

void MenuState::render(StateManager* game) {
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->renderer);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	int x = game->w * CELL_WIDTH / 2 - texW / 2;
	int y = game->h * CELL_WIDTH / 3;
	SDL_Rect dstrect = { x, y, texW, texH };

	int texW2 = 0;
	int texH2 = 0;
	SDL_QueryTexture(texture2, NULL, NULL, &texW2, &texH2);
	int x2 = game->w * CELL_WIDTH / 2 - texW2 / 2;
	int y2 = game->h * CELL_WIDTH / 3 * 2;
	SDL_Rect dstrect2 = { x2, y2, texW2, texH2 };
	SDL_RenderCopy(game->renderer, texture, NULL, &dstrect);
	SDL_RenderCopy(game->renderer, texture2, NULL, &dstrect2);
	SDL_RenderPresent(game->renderer);
}