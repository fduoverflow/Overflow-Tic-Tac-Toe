#include <iostream>
#include <algorithm>
#include "Board.h"
#include "Player.h"

using namespace std;
void IntroMessage();
void PlayGame();

int main() {

	IntroMessage();
	PlayGame();
}

void IntroMessage()
{
	cout << "\nWelcome to Overflow's Tic Tac Toe game!\n";
	cout << "Here are the rules/reminders:\n";
	cout << "-------------------------------\n\n";
	cout << "A Player must get 3 marks in a row to win. They can be vertical, horizontal, or diagonal.\n";
	cout << "The Player who is 'x' will go first. The Player who is 'o' goes second.\n";
	cout << "A win counter will be displayed at the end of each game.\n";
	cout << "You can reset the board after a game is complete.\n";
	cout << "Resetting the board will not reset the win counter, restarting the program will however.\n\n";
}

void PlayGame()
{
	/*
	* Victory checking added by Shakir Tempelman.
	*/
	Board gameBoard;
	Player player1("Player 1", 0);
	Player player2("Player 2", 0);
	string replayChoice;
	bool winFound;
	bool tieFound;
	bool isPlayingAgain = false;


	gameBoard.DisplayBoard();
	while (true) {
		//Check for win or tie
		winFound = gameBoard.VictoryChecker();
		tieFound = gameBoard.TieChecker();

		//Play or reset based on winFound
		if (winFound != true && tieFound != true)
		{
			gameBoard.MakeMove();
			gameBoard.DisplayBoard();
		}

		else if (winFound == true)
		{
			if (gameBoard.GetMark()) {
				player1.AddWin();
				cout << "Congrats to Player 1 on winning!\n";
			}
			else {
				player2.AddWin();
				cout << "Congrats to Player 2 on winning!\n";
			}

			cout << "Player 1 Wins: " << player1.GetWinCount() << "\nPlayer 2 Wins: " << player2.GetWinCount() << "\n";

			//Replay prompt and evaluation


			isPlayingAgain = false;

			while (!isPlayingAgain)
			{
				cout << "Would you like to play again? Enter Y to replay and N to exit. Enter R for see the rules again: ";
				cin >> replayChoice;
				transform(replayChoice.begin(), replayChoice.end(), replayChoice.begin(), ::toupper);

				if (replayChoice == "Y")
				{
					isPlayingAgain = true;
					winFound = false;
					tieFound = false;
					gameBoard.ResetBoard();
				}
				else if (replayChoice == "N")
				{
					//End program
					exit(0);
				}
				else if (replayChoice == "R")
				{
					IntroMessage();
				}
				else
				{
					cout << "Please enter Y or N!\n";

					//Clear any extra characters
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
		}
		else if (tieFound == true)
		{
			cout << "It was a tie!\n";
			cout << "Player 1 Wins: " << player1.GetWinCount() << "\nPlayer 2 Wins: " << player2.GetWinCount() << "\n";
			
			//Replay prompt and evaluation
			isPlayingAgain = false;

		
			while (!isPlayingAgain)
			{
				cout << "Would you like to play again? Enter Y to replay and N to exit. Enter R for see the rules again: ";
				cin >> replayChoice;
				transform(replayChoice.begin(), replayChoice.end(), replayChoice.begin(), ::toupper);

				if (replayChoice == "Y")
				{
					winFound = false;
					tieFound = false;
					gameBoard.ResetBoard();
					isPlayingAgain = true;
				}
				else if (replayChoice == "N")
				{
					//End program
					exit(0);
				}
				else if (replayChoice == "R")
				{
					IntroMessage();
				}
				else
				{
					cout << "Please enter Y or N!\n";

					//Clear any extra characters
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
		}
	}
}