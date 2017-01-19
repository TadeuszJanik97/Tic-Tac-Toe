#include "Game.h"

Game::Game()
{
	fields_ = new FieldState[9];
	for(int i=0; i<9; i++)
	{
		*(fields_ + i) = kEmpty;
	}
	current_state_ = kOMove;
	current_player_ = O;
	moves_number_ = 0;
}


bool Game::Win(const PlayerState& current_player, const int& field) const
{
	int column = field%3, row = field/3;
	if(current_player == X)
	{
		bool temp_win = true;
		for(int x=row*3; x<3+row*3; x++)
		{
			if(*(fields_ + x) != kPlayerX)
			{
				temp_win = false; break;
			}
		}
		if(temp_win)
			return true;
		temp_win = !temp_win;
		for(int y=column*3; y<9; y+=3)
		{
			if(*(fields_ + y) != kPlayerX)
			{
				temp_win = false; break;
			}
		}
		if(temp_win)
			return true;
		if((row+column)%2==0)
		{
			if(*fields_ == kPlayerX && *(fields_+4) == kPlayerX && *(fields_+8) == kPlayerX)
				return true;
			if(*(fields_+2) == kPlayerX && *(fields_+4) == kPlayerX && *(fields_+6) == kPlayerX)
				return true;
		}
		return false;
	}
	else
	{
		bool temp_win = true;
		for(int x=row*3; x<3+row*3; x++)
		{
			if(*(fields_ + x) != kPlayerO)
			{
				temp_win = false; break;
			}
		}
		if(temp_win)
			return true;
		temp_win = !temp_win;
		for(int y=column*3; y<9; y+=3)
		{
			if(*(fields_ + y) != kPlayerO)
			{
				temp_win = false; break;
			}
		}
		if(temp_win)
			return true;
		if((row+column)%2==0)
		{
			if(*fields_ == kPlayerO && *(fields_+4) == kPlayerO && *(fields_+8) == kPlayerO)
				return true;
			if(*(fields_+2) == kPlayerO && *(fields_+4) == kPlayerO && *(fields_+6) == kPlayerO)
				return true;
		}
		return false;
	}
}

void Game::Update(const int& field)
{
	if(field<0) {}
	else if(*(fields_ + field) == kEmpty && (current_state_ == kXMove || current_state_ == kOMove))
	{
		if(current_player_ == X)
			*(fields_ + field) = kPlayerX;
		else
			*(fields_ + field) = kPlayerO;
		moves_number_++;
		bool win = Win(current_player_, field);
		if(win)
		{
			if(current_player_ == X)
				current_state_ = kXWin;
			else
				current_state_ = kOWin;
		}
		else if(moves_number_ == 9)
			current_state_ = kDraw;
		else
		{
			if(current_player_ == X)
			{
				current_player_ = O;
				current_state_ = kOMove;
			}
			else
			{
				current_player_ = X;
				current_state_ = kXMove;
			}
		}
	}
}

void Game::Reset()
{
	delete fields_;
	fields_ = new FieldState[9];
	for(int i=0; i<9; i++)
	{
		*(fields_ + i) = kEmpty;
	}
	current_state_ = kOMove;
	current_player_ = O;
	moves_number_ = 0;
}
