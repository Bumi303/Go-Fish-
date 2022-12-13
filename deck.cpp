#include <iostream>
#include <random>
#include <string>
#include "deck.h"
#include "card.h"

using namespace std;

/*********************************************************************
** Function: deck
** Description: this is the deck defualt construct
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
Deck::Deck(){
    this->n_cards = 52;
    int i = 0;
    for (int r = 0; r < 13; r++){
        for (int s = 0; s < 4; s++){
            this->cards[i].set_rank(r);
            this->cards[i].set_suit(s);
            i++;
        }
    }
    shuffle_deck();
}

/*********************************************************************
** Function: get n cards
** Description: return s the number of cards in the deck
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
int Deck::get_n_cards() const{
    return this->n_cards;
}

/*********************************************************************
** Function: set n cards
** Description: sets the number of cards in the deck
** Parameters: int n
** Pre-Conditions: n/a
** Post-Conditions:  n/a
*********************************************************************/
void Deck::set_n_cards(int n){
    this->n_cards = n;
}

/*********************************************************************
** Function: shuffle deck
** Description: shuffles the deck of cards randomly
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
//shuffles the deck
void Deck::shuffle_deck(){
    srand(time(NULL));
    int random_pos;
    for (int i = 0; i < 52; i++){
        random_pos = rand() % 52;
        swap(this->cards[i], this->cards[random_pos]);
    }
//    print_deck();
}

/*********************************************************************
** Function: remove card
** Description: removes a card form the deck and returns its value
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions:n/a
*********************************************************************/
Card& Deck::remove_card(){
    this->n_cards --;
    return this->cards[this->n_cards];
}

