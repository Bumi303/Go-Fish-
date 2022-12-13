#include <iostream>
#include <random>
#include <string>
#include "hand.h"
#include "card.h"
#include "deck.h"

using namespace std;

/*********************************************************************
** Function:  hand
** Description: the defualt hand constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Hand::Hand(){
    this->n_cards = 0;
    this->cards = new Card[52];
}

/*********************************************************************
** Function: deal card
** Description: deals card to a specific hand
** Parameters: card c
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Hand::deal_card(Card c){    
    cards[n_cards] = c;
    this->n_cards++;
}

/*********************************************************************
** Function: get n cards
** Description: returns the values of the number of cards in a hand
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions:n/a
*********************************************************************/
int Hand::get_n_cards() const{
    return n_cards;
}

/*********************************************************************
** Function: get card
** Description: returns the value of an array of cards
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
Card* Hand::get_card(){
    return cards;
}

/*********************************************************************
** Function: remove card
** Description: removes a card from the hand of the user and lowers the number of cards in that hand
** Parameters: int i
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Card Hand::remove_card(int i){
    this->n_cards--;
    
    swap(this->cards[i], this->cards[n_cards]); // swaps with last card
    return this->cards[this->n_cards];
}

/*********************************************************************
** Function: delete card
** Description: deletes card from hand
** Parameters: int i
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Hand::delete_card(int i){
    this->n_cards--;
    swap(this->cards[i], this->cards[n_cards]);
}

/*********************************************************************
 ** Function: hand destructor
 ** Description: frees memory from the heap
 ** Parameters: n/a
 ** Pre-Conditions: class has to leave scope
 ** Post-Conditions:n/a
*********************************************************************/
//destructor
Hand::~Hand(){
    if (this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }
}

/*********************************************************************
 ** Function: hand
 ** Description: copy constructor of hand class
 ** Parameters: hand &h
 ** Pre-Conditions: two objects are assigned
 ** Post-Conditions: n/a
*********************************************************************/
//copy constructor
Hand::Hand(const Hand &h){
    this->n_cards = h.n_cards;

    this->cards = new Card[n_cards];
    for (int i = 0; i < n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}

/*********************************************************************
 ** Function: hand
 ** Description: assignment operator overload used to copy two objects
 ** Parameters: const hand & h
 ** Pre-Conditions: two objects are assigned
 ** Post-Conditions: n/a
*********************************************************************/
// Assignment Operator Overload
Hand& Hand::operator = (const Hand &h){
    this->n_cards = h.n_cards;

    if (this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }

    this->cards = new Card[n_cards];
    for (int i = 0; i < n_cards; i++){
        this->cards[i] = h.cards[i];
    }
    return *this;
}

