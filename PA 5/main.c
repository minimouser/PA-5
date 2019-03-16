/*
	Name: Bailey Wolber
	Email: bailey.wolber@wsu.edu
	Date: 3/15/2019
	Description: computer implementation of the game craps
*/

#include "sources.h"

int main(void) {

	int gameContinue = 1;
	srand(time(NULL));

	//main game loop
	while (gameContinue == 1) {

		//main menu loop
		int menuSelection = 0;
		menuSelection = menu();

		//quit game condition
		if (menuSelection == 3) {
			gameContinue = 0;
		}
		else {

			//prints game rules
			if (menuSelection == 1) {

				clearScreen();
				printRules();
				printf("\n\nPress any key to continue(put console in full screen)");
				getch();

			}
			else {

				//play game loop
				int rolls = 0, scoreP1 = 0, scoreP2 = 0, waitingDotsState = 0, gameContinue = 1, round = 0, player = 1;
				int dice[5];

				while (gameContinue == 1) {
					round++;

					player = 1;
					firstRoll(&dice, round, player);
					scoreP1 += combination(&dice, round, player);

					player = 2;
					firstRoll(&dice, round, player);
					scoreP2 += combination(&dice, round, player);


					if (round == 14) {
						gameContinue = 0;
					}
					else {
						gameContinue = endOfRound(round, scoreP1, scoreP2);
					}

				}

				winner(scoreP1, scoreP2);

			}

		}

	}

	clearScreen();
	printf("Thanks for playing!");
	return 0; //indicates success
}