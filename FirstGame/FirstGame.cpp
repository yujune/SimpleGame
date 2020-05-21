// FirstGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void Print_Start_Logo();
void Print_End_Logo();
void Menu();
void Choose_Menu();
void Program1();
void Program2();
void Program3();

void Print_P1_Title();

void Print_P2_Title();
void Draw_Hangman(int);
void Print_Result_P2(int *ptrcount, int);

void Print_P3_Title();
bool Check_Input(string);

int main() {

	Print_Start_Logo();
	Choose_Menu();
	Print_End_Logo();

	return 0;
}

void Menu() {
	string Menu_choice = "      ======================================================================"
		"\n      **                                                                  **"
		"\n      **                 Hello, This is our Menu choice:                  **"
		"\n      **                 -------------------------------                  **"
		"\n      **                   [1] - Matching game                            **"
		"\n      **                   [2] - Guessing game (HANGMAN)                  **"
		"\n      **                   [3] - Generating game                          **"
		"\n      **                   [Q] - Exit the program                         **"
		"\n      **                                                                  **"
		"\n      ======================================================================";
	cout << Menu_choice << endl;
}

void Choose_Menu() {
	char program = 'Q';

	do {
		system("CLS");
		Menu();
		cout << "\n                          Please kindly choose one. >.<\n                          --> ";
		cin >> program;

		cin.clear();
		cin.ignore(100, '\n');

		while (program != '1' && program != '2' && program != '3' && program != 'Q' && program != 'q') {
			system("CLS");
			Menu();
			cout << "\n                          Please enter 1,2,3,Q or q only\n                          --> ";
			cin >> program;

			cin.clear();
			cin.ignore(100, '\n');
		}

		switch (program) {
		case '1':
			Program1();
			break;

		case '2':
			Program2();
			break;

		case '3':
			Program3();
			break;

		default:
			cout << "\n                          Are you sure to exit? ('Q' to exit, enter any key to continue)\n                          --> ";
			cin >> program;
			cin.clear();
			cin.ignore(100, '\n');
			if (program == 'Q' || 'q')
				cout << "\n\n\n   \t\tThank you for playing our game. >.<" << endl;
			break;
		}
	} while (program != 'Q' && program != 'q');
}

void Program1() {
	int numplay = 1; //initialise game equal = 0
	char game = 'Y';

	while (game == 'Y' || game == 'y') {         //loop start

		srand(time(NULL));
		int range, count, count1, none = 0, a = 0;              //variable declaration//variable declaration
		int number1, number2, number3, number4, number5, number6; //variable declaration
		int rannumber1, rannumber2, rannumber3, rannumber4, rannumber5, rannumber6;   //variable declaration

		range = (42 - 1) + 1;    //set range number

		rannumber1 = rand() % range + 1;    //generate first random number between 1 and 42
		rannumber2 = rand() % range + 1;    //generate second random number between 1 and 42
		rannumber3 = rand() % range + 1;    //generate third random number between 1 and 42
		rannumber4 = rand() % range + 1;    //generate fourth random number between 1 and 42
		rannumber5 = rand() % range + 1;    //generate fifth random number between 1 and 42
		rannumber6 = rand() % range + 1;    //generate sixth random number between 1 and 42

		Print_P1_Title();
		cout << "   " << setw(75) << setfill('=') << "=" << endl;
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
		cout << "   **   Your game #" << numplay << " :                                                      **" << endl;       //display number of game
		cout << "   **   Please choose 6 numbers between 1 until 42 :";

		int randomA[6] = { rannumber1,rannumber2,rannumber3,rannumber4,rannumber5,rannumber6 };  //aray of randomA,storage
		cin >> number1 >> number2 >> number3 >> number4 >> number5 >> number6;     //get six number input from user
		int *numberA[6] = { &number1,&number2,&number3,&number4,&number5,&number6 };      //store input in array

		for (int i = 0; i < 6; i++) {                              //for loop then while loop for checking the invalid number
			while ((cin.fail())) {
				cout << "   **   Pls re-enter all the number . Must be an integer :";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> number1 >> number2 >> number3 >> number4 >> number5 >> number6;
			}
			while (*numberA[i] < 0 || *numberA[i]>42) {
				cout << "   **   Pls re-enter number#" << i + 1 << " :";
				cin >> *numberA[i];
			}
		}

		for (count = 0; count < 6; count++); {                      // nested for-loop for checking the same number generat
			for (count1 = 0; count1 < 6; count1++) {
				if (count != count1 && randomA[count] == randomA[count1]) {
					randomA[count] = rand() % range + 1;         //generate new random number
					count = 0;                                    //compare new random number again with rest of the number
				}
			}
		}
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
		cout << "   " << setw(75) << setfill('*') << "*" << endl;
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

		cout << "   **   The 6 random numbers generated are:" << randomA[0] << " " << randomA[1] << " " << randomA[2] << " " << randomA[3] << " " << randomA[4] << " " << randomA[5] << endl;  //display six generated random number

		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

		cout << "   **   Matched numbers(s):";         //display matched number

		for (count = 0; count < 6; count++) {               //nested for-loop for checking the matched number
			for (count1 = 0; count1 < 6; count1++)
				if (*numberA[count1] == randomA[count]) {
					cout << *numberA[count1] << " ";                  //display matched number
				}
				else {
					none += 1;                                       //none +1 if number does not match
				}
		}

		if (none == 36) {                  //display none if sum of none =36
			cout << "None";
		}
		cout << endl;

		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
		cout << "   " << setw(75) << setfill('*') << "*" << endl;

		cout << "\n Continue ? (Y for yes, Enter any key to exit)\n-- > ";     //ask user to continue or break
		cin >> game;                             //get input
		cin.clear();
		cin.ignore(100, '\n');

		cout << "\n";                            //new line
		numplay++;                               //numplay = numplay+1
	}
}

void Print_P1_Title() {
	system("CLS");
	cout << "   " << setw(75) << setfill('=') << "=" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **" << setw(47) << setfill(' ') << "Game 1 - MATCHING GAME" << setw(26) << setfill(' ') << "**" << endl;
	cout << "   **" << setw(73) << "**" << endl;
	cout << "   " << setw(75) << setfill('=') << "=" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **   This game can six generate numbers to let player guess it.          **" << endl;
	cout << "   **   It will display the matched number, if player success to guess it.  **" << endl;
	cout << "   **                  It's like lottery. Let's have fun!                   **" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **              Please key in six number for 1 to 42 only.               **" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
}

void Program2() {
	char Start_Game = 'Y';

	do {
		int randnum, answer, count = 1, fail = 0;
		string guess, history;
		srand(time(NULL));

		Print_P2_Title();
		Draw_Hangman(count);

		randnum = rand() % 100 + 1;

		cout << "   " << setw(75) << setfill('=') << "=" << endl;
		cout << "   **    Guess #" << count << " : ";
		cin >> answer;

		while (cin.fail() || answer != randnum) {

			cin.clear();
			cin.ignore(100, '\n');

			count++;

			Print_P2_Title();
			Draw_Hangman(count);

			if (count > 8)
				break;

			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **   Previous guess:                                                     **" << endl;
			history.append(" ");
			history.append(to_string(answer));
			cout << "   **   " << history << endl;

			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **   Comment:                                                            **" << endl;

			if (answer >= 1 && answer <= 100) {
				if (answer > randnum)
					cout << "   **        No, give a lower number.                                       **" << endl;
				else
					cout << "   **        No, give a higher number.                                      **" << endl;
			}
			else
				cout << "   **        Please give a number from 1 to 100 only.                       **" << endl;

			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **   Guess #" << count << " : ";
			cin >> answer;
		}
		Print_Result_P2(&count, randnum);

		cout << "\n Continue ? (Y for yes, Enter any key to exit to main menu)\n -->";
		cin >> Start_Game;

		cin.clear();
		cin.ignore(100, '\n');

	} while (Start_Game == 'Y' || Start_Game == 'y');
}

void Program2_1() {
	char Start_Game = 'Y';

	do {
		int randnum, answer, count = 1;
		string guess, history;
		srand(time(NULL));

		Print_P2_Title();
		Draw_Hangman(count);

		randnum = rand() % 100 + 1;

		cout << "   " << setw(75) << setfill('=') << "=" << endl;
		cout << "   **    Guess #" << count << " : ";
		cin >> guess;

		cin.clear();
		cin.ignore(100, '\n');

		if (Check_Input(guess))
			answer = stoi(guess);
		else
			answer = 0;

		while (answer != randnum) {

			count++;

			Print_P2_Title();
			Draw_Hangman(count);

			if (count > 8)
				break;

			cout << "   **   Previous guess:                                                     **" << endl;
			history.append(" ");
			history.append(guess);

			cout << "   **   " << history << endl;
			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **   Comment:                                                            **" << endl;

			if (answer >= 1 && answer <= 100) {
				if (answer > randnum)
					cout << "   **        No, give a lower number.                                       **" << endl;
				else
					cout << "   **        No, give a higher number.                                      **" << endl;
			}
			else if (Check_Input(guess))
				cout << "   **        Please give a number from 1 to 100 only.                       **" << endl;
			else
				cout << "   **        Please give an integer only.                                   **" << endl;

			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **   Guess #" << count << " : ";
			cin >> guess;

			cin.clear();
			cin.ignore(100, '\n');

			if (Check_Input(guess))
				answer = stoi(guess);
			else
				answer = 0;
		}
		Print_Result_P2(&count, randnum);

		cout << "\n Continue ? (Y for yes, Enter any key to exit to main menu)\n -->";
		cin >> Start_Game;

		cin.clear();
		cin.ignore(100, '\n');

	} while (Start_Game == 'Y' || 'y');
}

void Print_P2_Title() {
	system("CLS");
	cout << "   " << setw(75) << setfill('=') << "=" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **" << setw(47) << setfill(' ') << "Game 2 - HANGMAN GAME" << setw(26) << setfill(' ') << "**" << endl;
	cout << "   **" << setw(73) << "**" << endl;
	cout << "   " << setw(75) << setfill('=') << "=" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **    This game challenge user to guess a number given from 1 to 100     **" << endl;
	cout << "   **    Player has eight tries each game, if winthe man will be saved,     **" << endl;
	cout << "   **    if not the man will be HANGED! Think wisely. >.<                   **" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **    When enter a number, a hint will be given (higher/lower), we       **" << endl;
	cout << "   **    only accept integer in the range of 1 ~ 100. Let's have fun.       **" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
}

void Draw_Hangman(int count_3) {
	switch (count_3) {
	case 1:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                          " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	case 2:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |                          " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	case 3:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         O                " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	case 4:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         O                " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	case 5:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         O                " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |        /|                                 **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	case 6:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         O                " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |        /|\\                                **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	case 7:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         O                " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |        /|\\                                **" << endl
			<< "   **                           |        /                                  **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	case 8:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         |                                 **" << endl
			<< "   **                           |         O                " << 9 - count_3 << " more tries.    **" << endl
			<< "   **                           |        /|\\                                **" << endl
			<< "   **                           |        / \\                                **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	default:
		cout << "   ===========================================================================" << endl
			<< "   **                                                                       **" << endl
			<< "   **                           @~~~~~~~~~+                                 **" << endl
			<< "   **                           |         \\                                 **" << endl
			<< "   **                           |          \\            " << " No more try.       **" << endl
			<< "   **                           |           O                               **" << endl
			<< "   **                           |                        " << " Head Off!         **" << endl
			<< "   **                           |        \\./                                **" << endl
			<< "   **                           |        \\|/             " << " You Lose!         **" << endl
			<< "   **                           |                                           **" << endl
			<< "   **                          =^===============+                           **" << endl
			<< "   **                                                                       **" << endl;
		break;
	}
}

void Print_Result_P2(int *ptrcount, int randnum) {
	cout << "   " << setw(75) << setfill('*') << "*" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

	if (*ptrcount <= 3) {
		cout << "   **                          Yes, you are right!                          **" << endl;
		cout << "   **              Guess it in " << *ptrcount << " times. WOW, you're fantastics!             **" << endl;
	}

	else if (*ptrcount <= 8) {
		cout << "   **                          Yes, you are right!                          **" << endl;
		cout << "   **              Just " << *ptrcount << " guesses. Good, try better next time!              **" << endl;
	}

	else {
		cout << "   **                          Gosh! You Lose! T.T                          **" << endl;
		cout << "   **                It is " << randnum << ". Oh, you need more practices!                 **" << endl;
	}

	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   " << setw(75) << setfill('*') << "*" << endl;
}

void Program3() {
	char Start_Game = 'Y';

	do {
		int Min_num, Max_num, randlist[2], range;
		string minimum, maximum, property[2];
		srand(time(NULL));

		Print_P3_Title();

		cout << "   " << setw(75) << setfill('=') << "=" << endl;
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

		cout << "   **     Minimum value : ";
		cin >> Min_num;
		cin.ignore(100, '\n');
		cout << "   **     Maximum value : ";
		cin >> Max_num;
		cin.ignore(100, '\n');


		while (cin.fail() || Min_num >= Max_num) {
			Print_P3_Title();

			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

			if (cin.fail())
				cout << "   **   Please enter integer thanks.                                        **" << endl;

			else
				cout << "   **   Minimum value cannot be bigger or equal to maximum value.           **" << endl;

			cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

			cout << "   **     Minimum value : ";
			cin >> Min_num;
			cin.ignore(100, '\n');
			cout << "   **     Maximum value : ";
			cin >> Max_num;
			cin.ignore(100, '\n');
		}

		range = ((Max_num - Min_num) + 1);

		randlist[0] = rand() % range + Min_num;
		randlist[1] = rand() % range + Min_num;

		while (randlist[1] == randlist[0])
			randlist[1] = rand() % range + Min_num;

		for (int i = 0; i < 2; i++) {

			if (randlist[i] < 0)
				property[i] = "It is a negative number.            **";

			else if (randlist[i] > 0) {
				if (randlist[i] % 2 == 0)
					property[i] = "It is an even positive number.      **";

				else
					property[i] = "It is an odd positive number.       **";
			}
			else
				property[i] = "";
		}
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
		cout << "   " << setw(75) << setfill('*') << "*" << endl;
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

		cout << "   ** The first number generated is " << randlist[0] << ". " << property[0] << endl;
		cout << "   ** The second number generated is " << randlist[1] << ". " << property[1] << endl;

		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
		cout << "   " << setw(75) << setfill('*') << "*" << endl;

		cout << "\n Continue ? (Y for yes, Enter any key to exit)\n -->";
		cin >> Start_Game;

		cin.clear();
		cin.ignore(100, '\n');

	} while (Start_Game == 'Y' || Start_Game == 'y');
}

void Program3_1() {
	char Start_Game = 'Y';

	do {
		int Min_num = 0, Max_num = 0, randlist[2], range;
		string minimum, maximum, property[2];
		srand(time(NULL));

		Print_P3_Title();

		cout << "   " << setw(75) << setfill('=') << "=" << endl;
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

		cout << "   **     Minimum value : ";
		cin >> minimum;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "   **     Maximum value : ";
		cin >> maximum;
		cin.clear();
		cin.ignore(100, '\n');

		if (Check_Input(minimum) && Check_Input(maximum)) {
			Min_num = stoi(minimum);
			Max_num = stoi(maximum);
		}

		while (Min_num >= Max_num) {
			Print_P3_Title();

			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

			if (!(Check_Input(minimum) && Check_Input(maximum)))
				cout << "   **   Please enter integer thanks.                                        **" << endl;

			else
				cout << "   **   Minimum value cannot be bigger or equal to maximum value.           **" << endl;

			cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
			cout << "   " << setw(75) << setfill('=') << "=" << endl;
			cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

			cout << "   **     Minimum value : ";
			cin >> minimum;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "   **     Maximum value : ";
			cin >> maximum;
			cin.clear();
			cin.ignore(100, '\n');

			if (Check_Input(minimum) && Check_Input(maximum)) {
				Min_num = stoi(minimum);
				Max_num = stoi(maximum);
			}
		}

		range = ((Max_num - Min_num) + 1);

		randlist[0] = rand() % range + Min_num;
		randlist[1] = rand() % range + Min_num;

		while (randlist[1] == randlist[0])
			randlist[1] = rand() % range + Min_num;

		for (int i = 0; i < 2; i++) {

			if (randlist[i] < 0)
				property[i] = "It is a negative number.            **";

			else if (randlist[i] > 0) {
				if (randlist[i] % 2 == 0)
					property[i] = "It is an even positive number.      **";

				else
					property[i] = "It is an odd positive number.       **";
			}
			else
				property[i] = "";
		}
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
		cout << "   " << setw(75) << setfill('*') << "*" << endl;
		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;

		cout << "   ** The first number generated is " << randlist[0] << ". " << property[0] << endl;
		cout << "   ** The second number generated is " << randlist[1] << ". " << property[1] << endl;

		cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
		cout << "   " << setw(75) << setfill('*') << "*" << endl;

		cout << "\n Continue ? (Y for yes, Enter any key to exit)\n -->";
		cin >> Start_Game;

		cin.clear();
		cin.ignore(100, '\n');

	} while (Start_Game == 'Y' || 'y');
}

void Print_P3_Title() {
	system("CLS");
	cout << "   " << setw(75) << setfill('=') << "=" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **" << setw(48) << setfill(' ') << "Game 3 - GENERATING GAME" << setw(25) << setfill(' ') << "**" << endl;
	cout << "   **" << setw(73) << "**" << endl;
	cout << "   " << setw(75) << setfill('=') << "=" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **     This game can two generate numbers based on user input range      **" << endl;
	cout << "   **     and tell the user the two generate numbers whether                **" << endl;
	cout << "   **     it is negative, odd positive or even positive.                    **" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
	cout << "   **      Please key in the minimum value first, then maximum value        **" << endl;
	cout << "   **      for the range of the random number.                              **" << endl;
	cout << "   **" << setw(73) << setfill(' ') << "**" << endl;
}

bool Check_Input(string isnumber) {
	bool checking = true;

	for (int i = 0; i < isnumber.length(); i++) {
		if (!isdigit(isnumber.at(i))) {
			if (i = 0 && isnumber.at(i) == '-')
				continue;
			checking = false;
		}
	}
	return checking;
}

bool Check_Input_1(string isnumber) {
	string::const_iterator bychar = isnumber.begin();

	while (bychar != isnumber.end())
		bychar++;

	if (bychar == isnumber.end())
		return true;
	else
		return false;
}

void Print_Start_Logo() {
	system("color 0E");

	cout << "                                                 ______                 " << endl;
	cout << "                                                /team./                 " << endl;
	cout << "                                               /team./                  " << endl;
	cout << "                                              |team./     ___________   " << endl;
	cout << "              *******    ooooooooooooooo     /team./     /teamteamte/   " << endl;
	cout << "              *****   ===================== /team./ ____/teamteamte/    " << endl;
	cout << "              ***  o===== W E L C O M E =====o____________________/     " << endl;
	cout << "              ** oo ==========================oo                        " << endl;
	cout << "              * oo   *                    *     oo                      " << endl;
	cout << "                o    ***                ***      o                      " << endl;
	cout << "                o    *****            *****      o                      " << endl;
	cout << "                o    ******          ******      o                      " << endl;
	cout << "                o                                o                      " << endl;
	cout << "                oooooooooooooooooooooooooooooooooo                      " << endl;
	cout << "                oteamteamteamteamteamteamteamteamo                      " << endl;
	cout << "                 oteamteamteamteamteamteamteamteo                       " << endl;
	cout << "                  oteamteamteamteamteamteamteamo                        " << endl;
	cout << "              * *  oteamteamteamteamteamteamteo  * *                    " << endl;
	cout << "              ** *  oteamteamteamteamteamteamo  * **                    " << endl;
	cout << "              *** *  oteamteamteamteamteamteo  * ***                    " << endl;
	cout << "              **** *  oteamteamteamteamteamo  * ****                    " << endl;
	cout << "              ***** *  oteamteamteamteamteo  * *****                    " << endl;
	cout << "              ****** *  oteamteamteamteamo  * ******                    " << endl;
	cout << "              ******* *  oteamteamteamteo  * *******                    " << endl;
	cout << "              ******** *  oteamteamteamo  * ********                    " << endl;

	cout << "\n   \t\tWelcome, Enter any key to start --> ";
	string nothing;
	getline(cin, nothing);
}

void Print_End_Logo() {
	system("color 0E");

	cout << "                                                 ______                 " << endl;
	cout << "                                                /team./                 " << endl;
	cout << "                                               /team./                  " << endl;
	cout << "                                              |team./     ___________   " << endl;
	cout << "              *******    ooooooooooooooo     /team./     /teamteamte/   " << endl;
	cout << "              *****   ===================== /team./ ____/teamteamte/    " << endl;
	cout << "              ***  o==== T H A N K  Y O U ===o____________________/     " << endl;
	cout << "              ** oo ==========================oo                        " << endl;
	cout << "              * oo   *                    *     oo                      " << endl;
	cout << "                o    ***                ***      o                      " << endl;
	cout << "                o    *****            *****      o                      " << endl;
	cout << "                o    ******          ******      o                      " << endl;
	cout << "                o                                o                      " << endl;
	cout << "                oooooooooooooooooooooooooooooooooo                      " << endl;
	cout << "                oteamteamteamteamteamteamteamteamo                      " << endl;
	cout << "                 oteamteamteamteamteamteamteamteo                       " << endl;
	cout << "                  oteamteamteamteamteamteamteamo                        " << endl;
	cout << "              * *  oteamteamteamteamteamteamteo  * *                    " << endl;
	cout << "              ** *  oteamteamteamteamteamteamo  * **                    " << endl;
	cout << "              *** *  oteamteamteamteamteamteo  * ***                    " << endl;
	cout << "              **** *  oteamteamteamteamteamo  * ****                    " << endl;
	cout << "              ***** *  oteamteamteamteamteo  * *****                    " << endl;
	cout << "              ****** *  oteamteamteamteamo  * ******                    " << endl;
	cout << "              ******* *  oteamteamteamteo  * *******                    " << endl;
	cout << "              ******** *  oteamteamteamo  * ********                    " << endl;

	cout << "\n   \t\tThank you, Enter any key to exit --> ";
	string nothing;
	getline(cin, nothing);
}