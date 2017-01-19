#ifndef GAME_H
#define GAME_H

enum GameState {kXMove, kOMove, kXWin, kOWin, kDraw};
enum FieldState {kEmpty, kPlayerX, kPlayerO};
enum PlayerState {X, O};

class Game
{
public:
	Game();
	bool Win(const PlayerState& current_player, const int& field) const;
	void Update(const int& field);
	void Reset();
	inline FieldState* fields() const {return fields_;}
	inline GameState current_state() const {return current_state_;}
	~Game() { delete fields_; }
private:
	FieldState* fields_;
	GameState current_state_;
	PlayerState current_player_;
	int moves_number_;
};

#endif
