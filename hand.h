#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <random>
#include <string>
#include "card.h"

using namespace std;

class Hand {
private:
    Card* cards; // An array of cards in hand
    int n_cards; // Number of cards in the hand.
public:
    Hand();
    void deal_card(Card);
    Card* get_card();
    int get_n_cards() const;
    Card remove_card(int);
    void delete_card(int);
    ~Hand();
    Hand(const Hand &);
    Hand& operator = (const Hand &);
    
// must have constructors, destructor, accessors, and mutators
};

#endif
