#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <random>
#include <string>
#include "hand.h"

using namespace std;

class Player {
private:
    Hand hand;
    int* books; // Array with ranks for which the player has books.
    int n_books;
public:
    Player();
    Player(int);
    void set_a_card(Card);
    Hand& get_hand();
    void set_book(int);
    int* get_books();
    int get_n_books() const;
    ~Player();
    Player(const Player &);
    Player& operator = (const Player &);
// must have constructors, destructor, accessors, and mutators
};

#endif
