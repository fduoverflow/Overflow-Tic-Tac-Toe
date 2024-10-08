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
	bool MoveChecker(int row, int col, string[]);
	bool VictoryChecker();
	bool TieChecker();
	void ResetBoard();
	bool GetMark();
	string occupiedSpot[BOARD_SIZE];
	int moveCount = 0;
private:
	int GetColumn(char);
	char board[BOARD_SIZE] = {};
	bool currentMark = false;				//Used to switch player marks
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
	transform(move.begin(), move.end(), move.begin(), ::toupper);
	int column = -1, row = -1;

	// In the case where use enters a letter then a number
	if (!isdigit(move[0])) {
		column = GetColumn(move[0]);
		row = move[1] - '1';
	}
	// In cases where the user enters a number then a letter
	else if (!isdigit(move[1])) {
		
		column = GetColumn(move[1]);
		row = move[0] - '1';

	}

	// Call the MoveChecker function to check if a move is valid
	bool validMove = MoveChecker(row, column, occupiedSpot);

	// If move is valid it runs this code, otherwise MoveChecker prompts the user to go again
	if (validMove)
	{
		if (currentMark == false)
		{
			board[row * 3 + column] = 'X';
			currentMark = true;
		}
		else if (currentMark == true)
		{
			board[row * 3 + column] = 'O';
			currentMark = false;
		}
		moveCount++;

		// String array keeps track of moves that have already been played
		if (moveCount < 9)
			//Formatting move into format of A1, B1, etc...
			occupiedSpot[moveCount - 1] = to_string(row + 1) + string(1, 'A' + column);
	}
}

int Board::GetColumn(char c) {
	switch (toupper(c)) {
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	default:
		return -1;
	}
}

/*
This function will check to see if the player is making an illegal move
Checks: If there is already a mark in a spot and
if the move is out of bounds (not A,B,C or 1,2,3 for columns/rows respectively)
*/
bool Board::MoveChecker(int row, int col, string occupiedSpot[])
{
	// check that move is not out of bounds w/ row and column
	if (row < 0 || row > 2 || col < 0 || col > 2)
	{
		cout << "\nMove is out of bounds please try again\n";
		return false;
	}
	// check if move has already been played
	//Formatting move into format of A1, B1, etc...
	string formattedMove = to_string(row + 1) + string(1, 'A' + col);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (occupiedSpot[i] == formattedMove)
		{
			cout << "\nA Player has already played in this space, try again!\n";
			return false;
		}
	}
	// If everything checks out, return true
	return true;
}

/*
* This function checks state of the board for a win condition.
* Returns true if win condition found and false otherwise.
* Added by Shakir Tempelman.
*/
bool Board::VictoryChecker()
{
	//Check rows
	if ((board[0] != ' ') && (board[0] == board[1] && board[1] == board[2]))
		return true;
	else if ((board[3] != ' ') && (board[3] == board[4] && board[4] == board[5]))
		return true;
	else if ((board[6] != ' ') && (board[6] == board[7] && board[7] == board[8]))
		return true;

	//Check columns
	if ((board[0] != ' ') && (board[0] == board[3] && board[3] == board[6]))
		return true;
	else if ((board[1] != ' ') && (board[1] == board[4] && board[4] == board[7]))
		return true;
	else if ((board[2] != ' ') && (board[2] == board[5] && board[5] == board[8]))
		return true;

	//Check diagonals
	if ((board[0] != ' ') && (board[0] == board[4] && board[4] == board[8]))
		return true;
	else if ((board[2] != ' ') && (board[2] == board[4] && board[4] == board[6]))
		return true;

	return false;
}

/*
* This function checks if the board is filled and there is a tie.
* Returns true if tie is found and false otherwise.
* Added by Shakir Tempelman.
*/
bool Board::TieChecker()
{
	//Check board for empty spaces
	for (char square : board)
	{
		if (square == ' ')
			return false;
	}

	return true;
}

//This function resets the board.
void Board::ResetBoard() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i] = ' ';
		occupiedSpot[i] = "";
	}
	moveCount = 0;
	currentMark = false;
	DisplayBoard();
}

bool Board::GetMark(){
	return currentMark;
}