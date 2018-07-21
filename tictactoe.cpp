﻿#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <thread>
/*
	Programmed by Nguyen Minh Nhan :D.
						dd/mm/yyyy
	Hello , my birth day is 09/03/2005.
	This Game is open source on Github.
*/
using namespace std;
/* Multiply */

char square[2][10] = {
	{ '0','1','2','3','4','5','6','7','8','9' },
{ '0'
,'1','2','3',
'4','5','6',
'7','8','9' }
}
;
char copy_square[10] = { '0','1','2','3','4','5','6','7','8','9' };
void board();

int check_winner = 0;
int choice;
// Variable for set player name
string player_first_name;
string player_second_name;
void check_win() {
	//This will be run in another thread for check who is the winner
	while (true) {
		// Check columns
		if (square[2][1] == square[2][4] and square[2][4] == square[2][7]) {
			check_winner = 1;
			break;
		}
		else if (square[2][2] == square[2][5] and square[2][5] == square[2][8]) {
			check_winner = 1;
			break;
		}
		else if (square[2][3] == square[2][3] and square[2][6] == square[2][9]) {
			check_winner = 1;
			break;
		}// Check Rows
		else if (square[2][1] == square[2][2] and square[2][2] == square[2][3]) {
			check_winner = 1;
			break;
		}
		else if (square[2][4] == square[2][5] and square[2][5] == square[2][6]) {
			check_winner = 1;
			break;
		}
		else if (square[2][7] == square[2][8] and square[2][8] == square[2][9]) {
			check_winner = 1;
			break;
		}// Check 1,5,9 (Sorry for my bad english ! i dont know what is "\" called in english )
		else if (square[2][1] == square[2][5] and square[2][5] == square[2][9]) {
			check_winner = 1;
			break;
		}// Check 3,5,7
		else if (square[2][3] == square[2][5] and square[2][5] == square[2][7]) {
			check_winner = 1;
			break;
		}
	}
}
int main(int argc, char** argv) {

	cout << "First player name (O): " << endl;
	cin >> player_first_name;
	cout << "Second player name (X): " << endl;
	cin >> player_second_name;
	
	//First Turn is random
	int turn = rand() % 2 + 1;
	//Game status
	string turn_of;
	string turn_of_ox;

	// Start thread that will run check_win func
	thread(check_win).detach();

	while (true) {
		// Set player stat
		if (turn == 1) {
			turn_of = player_first_name;
			turn_of_ox = 'O';
		}
		else if (turn == 2) {
			turn_of = player_second_name;
			turn_of_ox = 'X';
		}
		// Make this for future update lololololololololol or never 
		PlayerTurn:

		system("cls");

		board();
		cout << "Turn of (" << turn_of_ox << ") :" << turn_of << endl;
		cout << "Type number: ";
		if (check_winner == 1) {
			break;
		}
		cin >> choice;
		/* We need somethings to handle when someone type wrong choice
		Example: If choice is not 1,2,3,4,5,6,7,8,9 , program will need to goto PlayerTurn:
		PS: Maybe I Update it or nerver
		*/

		//Make sure player can not override X and O
		if (square[2][choice] == 'O') {
			continue;
		}
		else if (square[2][choice] == 'X') {
			continue;
		}//Handle Player choice
		else if (turn == 1 and square[2][choice] != 'O') {
			square[2][choice] = 'O';
			turn++;
		}
		else if (turn == 2 and square[2][choice] != 'X') {
			square[2][choice] = 'X';
			turn--;
		}
	}
	cout << endl << "Winner is : " << turn_of << endl;

	return 0;
}
// Game_Map 3x3
void board() {
	//Map and some credits (for fun because this game is opem source :D ):D :D :D :D :D :D 
	cout << "\t\t\t-------------" << endl;
	cout << "\t\t\t" << "| " << square[2][1] << " | " << square[2][2] << " | " << square[2][3] << " |\tTicTacToe" << endl;
	cout << "\t\t\t" << "| " << square[2][4] << " | " << square[2][5] << " | " << square[2][6] << " |\tProgrammed by Nguyen Minh Nhan" << endl;
	cout << "\t\t\t" << "| " << square[2][7] << " | " << square[2][8] << " | " << square[2][9] << " |" << endl;
	cout << "\t\t\t-------------" << endl;
}
