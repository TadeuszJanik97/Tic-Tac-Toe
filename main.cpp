#include "UI.h"

int main()
{
	Game game = Game();
	while(true)
	{
		int flag = 0;
		UI::PrintGame(game, flag);
		if(flag == -2)
			break;
		if(flag == -3)
			game.Reset();
	}
	return 0;
}
