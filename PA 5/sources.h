#pragma once

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int roll_Die(void);
void clearScreen(void);
void printRules(void);
int menu(void);
void waitFor(int secs);
void dispDice(int* die, int round, int player);
int combination(int* dice, int round, int player);
void waitingDotTranslate(char* waitingDots);
void firstRoll(int* diceRoll, int round, int player);
int endOfRound(int round, int scoreP1, int scoreP2);
void winner(int scoreP1, int scoreP2);
int comboMenu(int round, int player, int* dice);
