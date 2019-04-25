#include "SDL.h"
#include "StateManager.h"
#include "PlayState.h"
#include "MenuState.h"

int main(int argc, char *argv[]) {
	
	//Game *game = new Game("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 40, 40);
	//while (game->running()) {
	//	game->handleEvents();
	//	game->update();
	//	game->render();
	//	SDL_Delay(30);
	//}
	//
	//game->clean();

	StateManager game;
	game.init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 40, 40);
	game.changeState(MenuState::instance());
	std::cout << "Loop" << std::endl;
	while (game.running()) {
		game.handleEvents();
		game.update();
		game.render();
		SDL_Delay(100);
	}

	game.clean();
	return 0;
}