#ifndef UI_H
#define UI_H
#include "Game.h"
#include <iostream>
#include <stdlib.h>

namespace UI
{
	int GetField(const Game& game);
	int GetInput();
	void PrintBoard(const Game& game);
	void PrintGame(Game& game, int& flag);
}

#endif
