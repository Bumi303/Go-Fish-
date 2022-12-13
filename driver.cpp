/*********************************************************************
** Program Filename:assignment3.cpp
** Author: Hayden Henderson
** Date: 11/7/22
** Description: This program is designed to let a user play go fish against a computer
** Input: The user inputs guesses to try to guess what cards the computer has
 lastly, the user is prompted if they want to quit or continue
** Output: the output is the result of their  guess attemps 
*********************************************************************/

#include <iostream>
#include <random>
#include <string>
#include "game.h"
using namespace std;

/*********************************************************************
** Function: main
** Description: this the is main funciton it calls the classes
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions:  n/a
*********************************************************************/
int main(){
    char choice = ' ';
    while (choice != 'n'){
        Game g;
        g.start_game();
        
        cout << "Would you like to play again {y or n}? ";
        cin >> choice;
        cout << endl;
    }

    
	return 0;
}
