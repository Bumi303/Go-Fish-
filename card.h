#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <random>
#include <string>

using namespace std;

class Card {
private:
    int rank; // Should be in the range 0-12.
    int suit; // Should be in the range 0-3.
public:
    Card();
    void set_rank(int);
    void set_suit(int);
    int get_rank();
    int get_suit();
    // must have constructors, destructor, accessors, and mutators
};
#endif
