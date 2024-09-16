#pragma once
#include <string>

using namespace std;

// This Header File will include the Board class
// It will have the board states, check for illegal moves, reset the board, and check for victory conditions

class Board {
public:
	Board();
	void DisplayBoard();
private:
	char board[9];
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