
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <random>
#include <string>
#include "card.h"

using namespace std;

class Deck {
private:
    Card cards[52]; //A full deck of cards
    int n_cards; // Number of cards remaining in the deck
public:
    Deck();
    void shuffle_deck();
    int get_n_cards() const;
    void set_n_cards(int);
    Card& remove_card();
    
    // must have constructors, destructor, accessors, and mutators
};

#endif
