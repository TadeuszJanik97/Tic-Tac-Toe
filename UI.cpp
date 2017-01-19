#include "UI.h"

int UI::GetInput()
{
	char c = '0';
	std::cout << "Start a new game? (r to restart, q to quit): ";
	std::cin >> c;
	if(c == 'q' || c == 'Q')
		return -2;
	else if(c == 'r' || c == 'R')
		return -3;
	else
		return -1;
}

int UI::GetField(const Game& game)
{
	std::string s = "0";
	if(game.current_state() == kOMove)
		std::cout << "O, what's your next move?\nMy move is ";
	else
		std::cout << "X, what's your next move?\nMy move is ";
	std::cin >> s;
	if(s.length()>1)
		return -1;
	char c = s[0];
	if(c > '0' && c <= '9')
		return c-'0'-1;
	else if(c == 'q' || c == 'Q')
		return -2;
	else if(c == 'r' || c == 'R')
		return -3;
	else
		return -1;
}

void UI::PrintBoard(const Game& game)
{
	std::cout << "\n\n\n";
	for(int i=0; i<31; i++)
		std::cout << "-";
	std::cout << "\n";
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<2; j++)
		{
			std::cout << "|";
			for(int k=0; k<3; k++)
			{
				for(int temp=0; temp<9; temp++)
				{
					std::cout << " ";
				}
				std::cout << "|";
			}
			std::cout << "\n";
		}
		std::cout << "|";
		for(int k=0; k<3; k++)
		{
			for(int temp=0; temp<4; temp++)
			{
				std::cout << " ";
			}
			switch (*(game.fields()+3*i+k))
			{
				case kEmpty:
				std::cout << 3*i+k+1;
				break;
				case kPlayerX:
				std::cout << 'X';
				break;
				case kPlayerO:
				std::cout << 'O';
				break;
			}
			for(int temp=0; temp<4; temp++)
			{
				std::cout << " ";
			}
			std::cout << "|";
		}
		std::cout << "\n";
		for(int j=0; j<2; j++)
		{
			std::cout << "|";
			for(int k=0; k<3; k++)
			{
				for(int temp=0; temp<9; temp++)
				{
					std::cout << " ";
				}
				std::cout << "|";
			}
			std::cout << "\n";
		}
		for(int i=0; i<31; i++)
			std::cout << "-";
		std::cout << "\n";
	}
	std::cout << "\n\nr to restart, q to quit\n";
}

void UI::PrintGame(Game& game, int& flag)
{
	system("cls");
	PrintBoard(game);
	switch(game.current_state())
	{
		case kXWin:
		std::cout << "Congratulations X, you win!\n";
		flag = UI::GetInput();
		break;
		case kOWin:
		std::cout << "Congratulations O, you win!\n";
		flag = UI::GetInput();
		break;
		case kDraw:
		std::cout << "Ooops, it's a draw!\n";
		flag = UI::GetInput();
		break;
		default:
		flag = UI::GetField(game);
		game.Update(flag);
		break;
	}
}
