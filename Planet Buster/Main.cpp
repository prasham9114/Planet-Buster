#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	// Initialize random seed
	srand(static_cast<unsigned>(time(0)));

	//Initialize Game Object
	Game game;

	// Game Loop
	while (game.running())
	{
		// Rendering the game
		game.render();

		// Updating the game
		game.update();
	}

	// End Application
	return 0;
}
