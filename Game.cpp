#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;
void IntroMessage();

int main() {

	IntroMessage();
}

void IntroMessage()
{
	cout << "Welcome to Overflow's Tic Tac Toe game!\n";
	cout << "Here are the rules/reminders:\n";
	cout << "-------------------------------\n\n";
	cout << "A Player must get 3 marks in a row to win. They can be vertical, horizontal, or diagonal.\n";
	cout << "The Player who is 'x' will go first. The Player who is 'o' goes second.\n";
	cout << "A win counter will be displayed at the end of each game.\n";
	cout << "Resetting the board will not reset the win counter, restarting the program will however.\n\n";

	Board gameBoard;
	gameBoard.DisplayBoard();
}