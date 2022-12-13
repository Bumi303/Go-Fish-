#include <iostream>
#include <random>
#include <string>
#include "player.h"

using namespace std;

/*********************************************************************
** Function: player
** Description: defualt  constructor for player class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Player::Player(){
    this->books = new int[13];
    this->n_books = 0;
}

/*********************************************************************
** Function: set a card
** Description: sets the value of a card
** Parameters: card c
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
void Player::set_a_card(Card c){
    this->hand.deal_card(c);
}

/*********************************************************************
** Function: get hand
** Description: gets the hand for a specific player
** Parameters:n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
Hand& Player::get_hand(){
    return hand;
}

/*********************************************************************
** Function: set book
** Description: acccessor for books
** Parameters: rank
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
void Player::set_book(int rank){
    this->n_books++;
    this->books[this->n_books - 1] = rank;
}

/*********************************************************************
** Function: get books
** Description: accessor for books array
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
int* Player::get_books(){
    return books;
}

/*********************************************************************
** Function: get n books
** Description: returns the amount of books in player class
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
int Player::get_n_books() const{
    return n_books;
}

/*********************************************************************
** Function: player destructor
** Description: frees memory from the heap
** Parameters: n/a
** Pre-Conditions: class has to leave scope
** Post-Conditions:n/a
*********************************************************************/
Player::~Player(){
    if (this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }
}

/*********************************************************************
** Function: player
** Description: copy constructor of player class
** Parameters: player &P
** Pre-Conditions: two objects are assigned
** Post-Conditions: n/a
*********************************************************************/
// Copy constructor
Player::Player(const Player &p){
    this->n_books = p.n_books;

    this->books = new int[n_books];
    for (int i = 0; i < n_books; i++){
        this->books[i] = p.books[i];
    }
}


/*********************************************************************
** Function: player
** Description: assignment operator overload used to copy two objects
** Parameters: const player & p
** Pre-Conditions: two objects are assigned
** Post-Conditions: n/a
*********************************************************************/
// Assignment Operator Overload
Player& Player::operator = (const Player &p){
    this->n_books = p.n_books;

    if (this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }

    this->books = new int[n_books];
    for (int i = 0; i < n_books; i++){
        this->books[i] = p.books[i];
    }
    return *this;
}

