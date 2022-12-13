#include <iostream>
#include <random>
#include <string>
#include "card.h"
#include "deck.h"

using namespace std;

/*********************************************************************
** Function: card
** Description: defualt constructor for card class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions:n/a
*********************************************************************/
// needs initializations???
Card::Card(){
    this->rank = -1;
    this->suit = -1;
}

/*********************************************************************
** Function: set rank
** Description: sets the rank value for card class
** Parameters: int r
** Pre-Conditions: n/a
** Post-Conditions:n/a
*********************************************************************/
//card mutators
void Card::set_rank(int r){
    this->rank = r;
}

/*********************************************************************
** Function:set suit
** Description: sets the suti value for the card class
** Parameters: int s
** Pre-Conditions: n/a
** Post-Conditions:n/a
*********************************************************************/
void Card::set_suit(int s){
    this->suit = s;
}

/*********************************************************************
** Function: get rank
** Description:returns that value for rank in the card class
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
// card accessors
int Card::get_rank(){
    return this->rank;
}

/*********************************************************************
** Function: get suit
** Description: returns the value for the suit in the card class
** Parameters:n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
int Card::get_suit(){
    return this->suit;
}

