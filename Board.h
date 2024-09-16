#pragma once
#include <string>

using namespace std;

// This Header File will include the Board class
// It will have the board states, check for illegal moves, reset the board, and check for victory conditions

const int BOARD_SIZE = 9;
class Board {
public:
	Board();
	void DisplayBoard();
	void MakeMove();
	bool MoveChecker(int row, int col, string, string[]);
	string occupiedSpot[BOARD_SIZE];
	int moveCount = 0;
private:
	char board[BOARD_SIZE] = {};
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
	default:
		column = -1;
		break;
	}

	row = move[1] - '1';

	// Call the MoveChecker function to check if a move is valid
	bool validMove = MoveChecker(row, column, move, occupiedSpot);

	// If move is valid it runs this code, otherwise MoveChecker prompts the user to go again
	if (validMove)
	{
		board[row * 3 + column] = 'X';
		moveCount++;

		// String array keeps track of moves that have already been played
		occupiedSpot[moveCount] = move;
	}
}

/*
This function will check to see if the player is making an illegal move
Checks: If there is already a mark in a spot and
if the move is out of bounds (not A,B,C or 1,2,3 for columns/rows respectively)
*/
bool Board::MoveChecker(int row, int col, string move, string occupiedSpot[])
{
	// check that move is not out of bounds w/ row and column
	if (row < 0 || row > 2 || col < 0 || col > 2)
	{
		cout << "\nMove is out of bounds please try again\n";
		return false;
	}
	// check if move has already been played
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (occupiedSpot[i] == move)
		{
			cout << "\nA Player has already played in this space, try again!\n";
			return false;
		}
	}
	// If everything checks out, return true
	return true;
}