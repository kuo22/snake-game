#include "SDL.h"
#include "GameState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "Coordinate.h"
#include <iostream>

PlayState PlayState::playState;

void PlayState::init(StateManager* game) {
	std::cout << game->h << std::endl;
	for (int i = 0; i < game->h; i++) {
		std::vector<int> row;
		for (int j = 0; j < game->w; j++) {
			row.push_back(0);
		}
		map.push_back(row);
	}
	player = new Player(game->w / 2, game->h / 2, 0, -1);
	for (int i = 0; i < player->coordinates.size(); i++) {
		map[player->coordinates[i].y][player->coordinates[i].x] = 1;
	}
	food = new Food(game->w, game->h, map);

}

void PlayState::clean() { }
void PlayState::pause() { }
void PlayState::resume() { }

void PlayState::handleEvents(StateManager* game) {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		game->quit();
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_DOWN:
			if (!downPressed && player->yVel != -1) {
				std::cout << "Down" << std::endl;
				player->setXVel(0);
				player->setYVel(1);
				downPressed = true;
			}
			break;
		case SDLK_UP:
			if (!upPressed && player->yVel != 1) {
				std::cout << "Up" << std::endl;
				player->setXVel(0);
				player->setYVel(-1);
				upPressed = true;
			}
			break;
		case SDLK_LEFT:
			if (!leftPressed && player->xVel != 1) {
				std::cout << "Left" << std::endl;
				player->setXVel(-1);
				player->setYVel(0);
				leftPressed = true;
			}
			break;
		case SDLK_RIGHT:
			if (!rightPressed && player->xVel != -1) {
				std::cout << "Right" << std::endl;
				player->setXVel(1);
				player->setYVel(0);
				rightPressed = true;
			}
			break;
		case SDLK_p:
			game->pushState(PauseState::instance());
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_DOWN:
			downPressed = false;
			break;
		case SDLK_UP:
			upPressed = false;
			break;
		case SDLK_LEFT:
			leftPressed = false;
			break;
		case SDLK_RIGHT:
			rightPressed = false;
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void PlayState::update(StateManager* game) {
	player->setX(player->x + player->xVel);
	player->setY(player->getY() + player->getYVel());
	if (player->x < 0 || player->x >= game->w || player->y < 0 || player->y >= game->h || player->collideBody(map)) {
		std::cout << "RESET" << std::endl;
		reset(game);
		return;
	}

	map[player->y][player->x] = 1;
	Coordinate c = player->coordinates.front();
	map[c.y][c.x] = 0;
	if (player->justAte) {
		player->justAte = false;
	}
	else {
		player->coordinates.pop_front();
	}

	player->addBody(player->x, player->y);

	if (player->x == food->x && player->y == food->y) {
		food->spawn();
		player->justAte = true;
		player->length += 1;
	}
}

void PlayState::render(StateManager* game) {
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->renderer);
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
	for (int i = 0; i < player->coordinates.size(); i++) {
		SDL_Rect r;
		r.x = player->coordinates[i].x * CELL_WIDTH;
		r.y = player->coordinates[i].y * CELL_WIDTH;
		r.w = CELL_WIDTH;
		r.h = CELL_WIDTH;
		SDL_RenderDrawRect(game->renderer, &r);
	}
	SDL_Rect f;
	f.x = food->x * CELL_WIDTH;
	f.y = food->y * CELL_WIDTH;
	f.w = CELL_WIDTH;
	f.h = CELL_WIDTH;
	SDL_RenderDrawRect(game->renderer, &f);
	SDL_RenderPresent(game->renderer);
}

void PlayState::reset(StateManager* game) {
	delete player;
	delete food;
	player = new Player(game->w / 2, game->h / 2, 0, -1);
	for (int i = 0; i < map.size(); i++) {
	std:fill(map[i].begin(), map[i].end(), 0);
	}
	for (int i = 0; i < player->coordinates.size(); i++) {
		map[player->coordinates[i].y][player->coordinates[i].x] = 1;
	}
	food = new Food(game->w, game->h, map);
}