#ifndef GOFISH_H
#define GOFISH_H

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
    
    void print_card();
    // must have constructors, destructor, accessors, and mutators
};

class Deck {
private:
    Card cards[52]; //A full deck of cards
    /*
     can use 52 - n-cards to find position
     needs to be static because deck size never change
     */
    int n_cards; // Number of cards remaining in the deck
public:
    Deck();
    void shuffle_deck();
    void print_deck();
        
    
    // must have constructors, destructor, accessors, and mutators
};

class Hand {
private:
    Card* cards; // An array of cards in hand
    /*
     cards in hand is always changing
     if I were a betting man i would say that n_cards initializes dynamic array 
     */
    int n_cards; // Number of cards in the hand.
public:
    Hand();
// must have constructors, destructor, accessors, and mutators
};

class Player {
private:
    Hand hand;
    int* books; // Array with ranks for which the player has books.
    int n_books;
public:
    Player();
// must have constructors, destructor, accessors, and mutators
};

class Game {
private:
    Deck d;
    Player players[2];
public:
    Game();
// must have constructors, destructor, accessors, and mutators
};

#endif
