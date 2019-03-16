/*
	I am sorry my comments are really sparse, I didn't have a lot of time to write comments
*/

#include "sources.h"

//prints menu and returns menu selection
int menu(void) {
	int menuSelection = 0;

	while ((menuSelection < 1 || menuSelection > 3)) {
		clearScreen();
		printf(
			" __  __     ______     __  __     ______   ______     ______     ______    \n"
			"/\\ \\_\\ \\   /\\  __ \\   /\\ \\_\\ \\   /\\__  _\\ /\\___  \\   /\\  ___\\   /\\  ___\\   \n"
			"\\ \\____ \\  \\ \\  __ \\  \\ \\  __ \\  \\/_/\\ \\/ \\/_/  /__  \\ \\  __\\   \\ \\  __\\   \n"
			" \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\    \\ \\_\\   /\\_____\\  \\ \\_____\\  \\ \\_____\\ \n"
			"  \\/_____/   \\/_/\\/_/   \\/_/\\/_/     \\/_/   \\/_____/   \\/_____/   \\/_____/ \n\n\n");
		printf(
		"    ___                                     __             ____        _ __              _       __      ____             \n"
		"   /   |     ____ _____ _____ ___  ___     / /_  __  __   / __ )____ _(_/ ___  __  __   | |     / ____  / / /_  ___  _____\n"
		"  / /| |    / __ `/ __ `/ __ `__ \\/ _ \\   / __ \\/ / / /  / __  / __ `/ / / _ \\/ / / /   | | /| / / __ \\/ / __ \\/ _ \\/ ___/\ \n"
		" / ___ |   / /_/ / /_/ / / / / / /  __/  / /_/ / /_/ /  / /_/ / /_/ / / /  __/ /_/ /    | |/ |/ / /_/ / / /_/ /  __/ /    \n"
		"/_/  |_|   \\__, /\\__,_/_/ /_/ /_/\\___/  /_.___/\\__, /  /_____/\\__,_/_/_/\\___/\\__, /     |__/|__/\\____/_/_.___/\\___/_/     \n"
		"          /____/                              /____/                        /____/                                        \n\n");
		printf("1. Print game rules\n2. Start game of Yahtzee\n3. Quit\nType your selection here: ");
		scanf("%d", &menuSelection);
	}
	return menuSelection;
}

//prints rules for 30 seconds
void printRules(void) {
	
	printf("The scorecard used for Yahtzee is composed of two sections. \n"
		"A upper section and a lower section. A total of thirteen boxes or thirteen scoring \n"
		"combinations are divided amongst the sections. The upper section consists of boxes \n"
		"that are scored by summing the value of the dice matching the faces of the box. \n"
		"If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which \n"
		"is 12. Once a player has chosen to score a box, it may not be changed and the combination \n"
		"is no longer in play for future rounds. If the sum of the scores in the upper section is \n"
		"greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. \n"
		"The lower section contains a number of poker like combinations.");
	printf("\n\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"|       Name      |                               Combination                               |                 Score                |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"| Three-of-a-kind |                      Three dice with the same face                      | Sum of all face values on the 5 dice |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"|  Four-of-a-kind |                       Four dice with the same face                      | Sum of all face values on the 5 dice |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"|    Full house   |                      One pair and a three-of-a-kind                     |                  25                  |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"|  Small straight |                         A sequence of four dice                         |                  30                  |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"|  Large straight |                         A sequence of five dice                         |                  40                  |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"|     Yahtzee     |                       Five dice with the same face                      |                  50                  |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n"
		"|      Chance     | May be used for all sequence of dice; this is the catch all combination | Sum of all face values on the 5 dice |\n"
		"+-----------------+-------------------------------------------------------------------------+--------------------------------------+\n");
	
}


void waitFor(int secs) {
	int retTime = time(0) + secs;   // Get finishing time.
	while (time(0) < retTime);               // Loop until it arrives.
}

//clears the screen
void clearScreen(void){

	system("@cls||clear");
}

//randomly chooses a number on a 6 sided die returns that random number 
int roll_Die(void) {
	int die = 0;
	die = (rand() % 6) + 1;
	return die;
}

//prints dice
void dispDice(int* die, int round, int player) {

	char charArray[35];

	for (int i = 0; i < 35; i++) {
		charArray[i] = 32;
	}
	for (int i = 0; i < 5; i++) {

		int charLocation[7] = { 0, 1, 10, 11, 12, 25 ,26 };

		for (int j = 0; j < 7; j++) {
			if (charLocation[j] >= 10 && charLocation[j] <= 12) {
				charLocation[j] = charLocation[j] + 3 * i;
			}
			else {
				charLocation[j] = charLocation[j] + 2 * i;
			}
		}

		if (die[i] == 1) {
			charArray[charLocation[3]] = '*';
		}
		else if (die[i] == 2) {
			charArray[charLocation[0]] = '*';
			charArray[charLocation[6]] = '*';
		}
		else if (die[i] == 3) {
			charArray[charLocation[0]] = '*';
			charArray[charLocation[3]] = '*';
			charArray[charLocation[6]] = '*';
		}
		else if (die[i] == 4) {
			charArray[charLocation[0]] = '*';
			charArray[charLocation[1]] = '*';
			charArray[charLocation[5]] = '*';
			charArray[charLocation[6]] = '*';
		}
		else if (die[i] == 5) {
			charArray[charLocation[0]] = '*';
			charArray[charLocation[1]] = '*';
			charArray[charLocation[3]] = '*';
			charArray[charLocation[5]] = '*';
			charArray[charLocation[6]] = '*';
		}
		else if (die[i] == 6) {
			charArray[charLocation[0]] = '*';
			charArray[charLocation[1]] = '*';
			charArray[charLocation[2]] = '*';
			charArray[charLocation[4]] = '*';
			charArray[charLocation[5]] = '*';
			charArray[charLocation[6]] = '*';
		}


	}

	printf("------======| Player: %d Round: %d |======------\n", player, round);
	printf(
		"+--------+  +--------+  +--------+  +--------+  +--------+\n"
		"|  %c  %c  |  |  %c  %c  |  |  %c  %c  |  |  %c  %c  |  |  %c  %c  |\n"
		"|  %c %c%c  |  |  %c %c%c  |  |  %c %c%c  |  |  %c %c%c  |  |  %c %c%c  |\n"
		"|  %c  %c  |  |  %c  %c  |  |  %c  %c  |  |  %c  %c  |  |  %c  %c  |\n"
		"+--------+  +--------+  +--------+  +--------+  +--------+\n\n"
	, charArray[0], charArray[1], charArray[2], charArray[3], charArray[4], charArray[5], charArray[6], charArray[7], charArray[8], charArray[9], 
	charArray[10], charArray[11], charArray[12], charArray[13], charArray[14], charArray[15], charArray[16], charArray[17], charArray[18], charArray[19],
	charArray[20], charArray[21], charArray[22], charArray[23], charArray[24], charArray[25], charArray[26], charArray[27], charArray[28], charArray[29],
	charArray[30], charArray[31], charArray[32], charArray[33], charArray[34]);
}

//Asks if you would like to change a die, returns score
int combination(int* dice, int round, int player) {
	int score = 0, roll = 1;
	char continueRolling = NULL;

	while (!(continueRolling == 'n' || roll == 4)) {
		clearScreen();
		dispDice(dice, round, player);
		printf("\nRoll #%d\nWould you like to change a die? y/n: ", roll);
		scanf(" %c", &continueRolling);

		if (continueRolling == 'y') {
			roll++;
			int choice = 0;

			while (choice < 1 || choice > 5) {
				clearScreen();
				dispDice(dice, round, player);
				printf("Which die would you like to reroll (1/5)?: ");
				scanf("%d", &choice);
			}


			choice--;
			clearScreen();
			char waitingDots[3];

			for (int i = 0; i < 3; i++) {
				waitingDots[i] = '.';
			}

			for (int j = 0; j < 180; j++) {


				dice[choice] = roll_Die();
				if (j % 15 == 0) {

					waitingDotTranslate(waitingDots);
				}

				clearScreen();
				dispDice(dice, round, player);
				printf("Randomizing die %d %c%c%c\n", choice + 1, waitingDots[0], waitingDots[1], waitingDots[2]);
			}

		}


	}

	score = comboMenu(round, player, dice);
	if (score > 0) {
		printf("\n\nYou won %d points", score);
	}

	printf("\nPress any key to continue");
	getch();

	return score;
}

//Accepts an array and adds a ., when all dots are full then resets array to ' '
void waitingDotTranslate(char* waitingDots) {
	if (waitingDots[0] == '.') {
		if (waitingDots[1] == '.') {
			if (waitingDots[2] == '.') {
				for (int i = 0; i < 3; i++) {
					waitingDots[i] = ' ';
				}
			}
			else {
				waitingDots[2] = '.';
			}
		}
		else {
			waitingDots[1] = '.';
		}
	}
	else {
		waitingDots[0] = '.';
	}
}

//Conditions for first roll
void firstRoll(int* diceRoll, int round, int player) {
	clearScreen();
	char waitingDots[3];

	for (int i = 0; i < 3; i++) {
		waitingDots[i] = '.';
	}

	printf("------======| Player: %d Round: %d |======------\n", player, round);
	printf("Press any key to roll dice\n\n");
	getch();


	for (int j = 0; j < 180; j++) {

		for (int i = 0; i < 5; i++) {

			diceRoll[i] = roll_Die();

		}

		if (j % 15 == 0) {

			waitingDotTranslate(waitingDots);
		}

		clearScreen();
		dispDice(diceRoll, round, player);
		printf("Randomizing dice %c%c%c\n", waitingDots[0], waitingDots[1], waitingDots[2]);
	}
}

//end of round logic
int endOfRound(int round, int scoreP1, int scoreP2) {
	char selection = NULL;
	int returnValue = 0, retry = 1;

	while (retry == 1){
		clearScreen();
		printf("------======|       Round: %d      |======------\n", round);
		printf("+----------------------+-----------------------+\n"
			"|     Score Player 1   |   Score Player 2      |\n"
			"+----------------------------------------------+\n"
			"           %d                    %d             \n"
			"\n\n\n Would you like to continue playing y/n?: ", scoreP1, scoreP2);
		scanf(" %c", &selection);

		if (selection == 'y') {
			returnValue = 1;
			retry = 0;
		}

		else if (selection == 'n') {
			returnValue = 0;
			retry = 0;
		}

		else{
		}
	}

	return returnValue;
}

//prints out the winner
void winner(int scoreP1, int scoreP2) {
	clearScreen();
	if (!(scoreP1 == scoreP2)) {
		printf("  ___________\n"
			" '._==_==_=_.'\n"
			" .-\\:      /-.\n"
			"| (|:.     |) |\n"
			" '-|:.     |-'\n"
			"   \\::.    /\n"
			"    '::. .'\n"
			"      ) (\n"
			"    _.' '._\n\n\n");
	}


	if (scoreP1 > scoreP2) {
		printf(""
		 " ____  _                         _            _           _ \n"
		 "|  _ \\| | __ _ _   _  ___ _ __  / | __      _(_)_ __  ___| |\n"
		 "| |_) | |/ _` | | | |/ _ \\ '__| | | \\ \\ /\\ / / | '_ \\/ __| |\n"
		 "|  __/| | (_| | |_| |  __/ |    | |  \\ \V  \V /| | | | \\__ \\_|\n"
		 "|_|   |_|\\__,_|\\__, |\\___|_|    |_|   \\_/\\_/ |_|_| |_|___(_)\n"
		 "               |___/                                        \n"	);
	}else if (scoreP1 < scoreP2) {
		printf(""	
		" ____  _                         ____             _           _ \n"
		"|  _ \\| | __ _ _   _  ___ _ __  |___ \\  __      _(_)_ __  ___| |\n"
		"| |_) | |/ _` | | | |/ _ \\ '__|   __) | \\ \\ /\\ / / | '_ \\/ __| |\n"
		"|  __/| | (_| | |_| |  __/ |     / __/   \\ \V  \V /| | | | \\__ \\_|\n"	
		"|_|   |_|\\__,_|\\__, |\\___|_|    |_____|   \\_/\\_/ |_|_| |_|___(_)\n"
		"               |___/  \n"		);
	}
	else {
		printf(""		
 " _____ _      \n"
 "|_   _(_) ___ \n"
 "  | | | |/ _ \\\n"
 "  | | | |  __/\n"
 "  |_| |_|\___|\n"
		);
	}
	
	printf("\n\nPress any key to continue");
	getch();
}

//All of the combination logic, This is honestly so trash and i feel like there is a much better way to do this, sorry dana
int comboMenu(int round, int player, int* dice) {

	int score = 0, menuContinue = 0, tries = 0;

	while (menuContinue == 0) {
		int menuSelection = 0;
		int contains[6];

		for (int i = 0; i < 6; i++) {
			contains[i] = 0;
		}

		while ((menuSelection < 1 || menuSelection > 13)) {
			tries++;

			clearScreen();
			dispDice(dice, round, player);

			if (tries >= 4) {
				printRules();
			}

			printf("\n1. Sum of 1's        7. Three-of-a-kind\n"
				"2. Sum of 2's        8. Four-of-a-kind\n"
				"3. Sum of 3's        9. Full house\n"
				"4. Sum of 4's        10. Small straight\n"
				"5. Sum of 5's        11. Large straight\n"
				"6. Sum of 6's        12. Yahtzee\n"
				"           13. Chance\n"
				"\nPlease make a selection: ");
			scanf("%d", &menuSelection);

		}

		if (menuSelection == 1) {

			for (int i = 0; i < 5; i++) {
				if (dice[i] == 1) {
					contains[0]++;
				}

			}

			if (contains[0] >= 1) {
				score = 1 * contains[0];
				menuContinue = 1;
			}
			else {
				printf("Doesnt contain any, choose another choice");
			}
		}

		else if (menuSelection == 2) {

			for (int i = 0; i < 5; i++) {
				if (dice[i] == 2) {
					contains[0]++;
				}

			}

			if (contains[0] >= 1) {
				score = 2 * contains[0];
				menuContinue = 1;
			}
			else {
				printf("Doesnt contain any, choose another choice");
			}

		}

		else if (menuSelection == 3) {

			for (int i = 0; i < 5; i++) {
				if (dice[i] == 3) {
					contains[0]++;
				}

			}

			if (contains[0] >= 1) {
				score = 3 * contains[0];
				menuContinue = 1;
			}
			else {
				printf("Doesnt contain any, choose another choice");
			}

		}

		else if (menuSelection == 4) {

			for (int i = 0; i < 5; i++) {
				if (dice[i] == 4) {
					contains[0]++;
				}

			}

			if (contains[0] >= 1) {
				score = 4 * contains[0];
				menuContinue = 1;
			}
			else {
				printf("Doesnt contain any, choose another choice");
			}

		}

		else if (menuSelection == 5) {

			for (int i = 0; i < 5; i++) {
				if (dice[i] == 5) {
					contains[0]++;
				}

			}

			if (contains[0] >= 1) {
				score = 5 * contains[0];
				menuContinue = 1;
			}
			else {
				printf("Doesnt contain any, choose another choice");
			}

		}

		else if (menuSelection == 6) {

			for (int i = 0; i < 5; i++) {
				if (dice[i] == 6) {
					contains[0]++;
				}

			}

			if (contains[0] >= 1) {
				score = 6 * contains[0];
				menuContinue = 1;
			}
			else {
				printf("Doesnt contain any, choose another choice");
			}

		}

		else if (menuSelection == 7) {

			for (int i = 0; i < 5; i++) {
				contains[dice[i]]++;

			}

			int flag = 0;

			for (int i = 0; i < 7; i++) {
				if (contains[i] >= 3) {
					flag = 1;
					menuContinue = 1;

					score = i * contains[i];
				}
			}

			if (flag == 0) {
				printf("Doesnt contain any, choose another choice");
			}


		}

		else if (menuSelection == 8) {

			for (int i = 0; i < 5; i++) {
				contains[dice[i]]++;

			}

			int flag = 0;

			for (int i = 0; i < 7; i++) {
				if (contains[i] >= 4) {
					flag = 1;
					menuContinue = 1;

					score = i * contains[i];
				}
			}

			if (flag = 0) {
				printf("Doesnt contain any, choose another choice");
			}
		}

		else if (menuSelection == 9) {

			for (int i = 0; i < 5; i++) {
				contains[dice[i]]++;

			}

			int flag = 0;

			for (int i = 0; i < 7; i++) {

				if (contains[i] == 3) {

					flag++;

				}
				else if (contains[i] == 2) {

					flag++;

				}
			}

			if (flag == 2) {

				menuContinue = 1;
				score = 25;

			}
			else {

				printf("Doesnt contain any, choose another choice");

			}


		}

		else if (menuSelection == 10) {

			for (int i = 0; i < 5; i++) {
				contains[dice[i]]++;

			}


			int flag = 0;
			for (int i = 0; i < 3; i++) {
				flag = 0;

				for (int j = 0; j < 5; j++) {
					if (contains[j + i] > 0) {
						flag++;
					}
					else {
						j = 9;
					}
				}
			}

			if (flag == 4) {

				menuContinue = 1;
				score = 30;

			}
			else {
				printf("Doesnt contain any, choose another choice");
			}

		}

		else if (menuSelection == 11) {

			for (int i = 0; i < 5; i++) {
				contains[dice[i]]++;

			}


			int flag = 0;
			for (int i = 0; i < 2; i++) {
				flag = 0;

				for (int j = 0; j < 6; j++) {
					if (contains[j + i] > 0) {
						flag++;
					}
					else {
						j = 9;
					}
				}
			}

			if (flag == 5) {

				menuContinue = 1;
				score = 30;

			}
			else {
				printf("Doesnt contain any, choose another choice");
			}
		}

		else if (menuSelection == 12) {
			int flag = 0;

			for (int i = 0; i < 5; i++) {
				int diceValue = dice[i];
				contains[diceValue]++;
			}

			for (int i = 0; i < 7; i++) {
				if (contains[i] == 5) {
					flag++;
				}
			}

			if (flag == 1) {
				score = 50;
				menuContinue = 1;
			}
			else {
				printf("Doesnt contain any, choose another choice");
			}
		}

		else if (menuSelection == 13) {
			for (int i = 0; i < 5; i++) {
				score = score + dice[i];
			}
			menuContinue = 1;
		}


	}

	return score;
}