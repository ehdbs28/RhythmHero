#include "Game.h"

Game* game;

int main() {
	game = new Game();

	game->Init();

	while (game->GetGameRunning()) {
		game->Update();
		game->Render();
	}

	game->Release();
}