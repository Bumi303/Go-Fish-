
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <random>
#include <string>
#include "deck.h"
#include "player.h"

using namespace std;

class Game {
private:
    Deck d;
    Player players[2];
public:
    Game();
    void start_game();
    void deal_players();
    void player1_turn(bool&, bool&);
    void player2_turn(bool&, bool&);
    void check_if_exists(int, int, bool&);
    void print_hand(int);
    bool welcome();
    bool debug_mode();
    void take_cards(int, int, int, int);
    void debug_hand(bool);
    void add_card(int, int, bool&);
    void book_finder(int);
    void add_book(int, int);
    void print_books(int);
    void delete_cards(int, int);
    bool check_if_in_hand(int, int);
    int computer_decision();
    bool is_over();
    bool if_empty(int);
    
// must have constructors, destructor, accessors, and mutators
};

#endif
