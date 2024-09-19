#pragma once
#include <string>

using namespace std;
// This header file will include the Player class
// It will hold the player scores, the player mark, with a potential improvement of allowing players to switch marks


class Player {
public:
	Player(string name, int win);
	int GetWinCount();
	void AddWin();
private:
	int WinCount = 0;
};

Player::Player(string name, int win) {

}

int Player::GetWinCount() {
	return WinCount;
}


void Player::AddWin() {
	WinCount++;
}