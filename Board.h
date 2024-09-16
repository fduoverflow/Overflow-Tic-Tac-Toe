#pragma once
#include <string>

using namespace std;

// This Header File will include the Board class
// It will have the board states, check for illegal moves, reset the board, and check for victory conditions

class Board {
public:
	Board();
	void DisplayBoard();
	void MakeMove();
	bool MoveChecker(int row, int col, string move, char board[]);
private:
	char board[9] = {};
};

Board::Board() {
	for (char& space : board) {
		space = ' ';
	}
}

void Board::DisplayBoard() {
	cout << "    A   B   C" << endl;
	cout << "   ----------- " << endl;
	for (int r = 0; r < 3; r++) {
		cout << r + 1;
		for (int c = 0; c < 3; c++) {
			cout << " | " << board[3 * r + c];
		}
		cout << " |" << endl;
	}
}

void Board::MakeMove() {
	string move;
	cout << "Enter space where you want your move: ";
	cin >> move;

	int column, row;

	switch (move[0]) {
	case 'A':
		column = 0;
		break;
	case 'B':
		column = 1;
		break;
	case 'C':
		column = 2;
		break;
	}

	row = move[1] - '1';

	// ADD ILLEGAL MOVE LOGIC HERE


	board[row * 3 + column] = 'X';
}

/*
This function will check to see if the player is making an illegal move
Checks: If there is already a mark in a spot and
if the move is out of bounds (not A,B,C or 1,2,3 for columns/rows respectively)
*/
bool Board::MoveChecker(int row, int col, string move, char board[])
{
	// check that move is not out of bounds w/ row and column
	if (row < 1 || row > 3 || col < 1 || col > 3)
	{
		return false;
	}
	// check if move has already been played

	return true;
}