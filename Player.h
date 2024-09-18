#pragma once
#include <string>
#include "Board.h"

using namespace std;
// This header file will include the Player class
// It will hold the player scores, the player mark, with a potential improvement of allowing players to switch marks

Board board;

class Player {
public:
	Player(string name, int win, int loss);
	string GetPlayer();
	int GetWinCount();
	int GetLossCount();
	void AddWin();
	void AddLoss();
private:
	string PlayerName = "";
	int WinCount = 0;
	int LossCount = 0;
};

string Player::GetPlayer() {
	return PlayerName;
}

int Player::GetWinCount() {
	return WinCount;
}

int Player::GetLossCount() {
	return LossCount;
}

void Player::AddWin() {
	WinCount++;
}

void Player::AddLoss() {
	LossCount++;
}