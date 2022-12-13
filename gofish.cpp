#include <iostream>
#include <random>
#include <string>
#include "gofish.h"

using namespace std;

// needs initializations???
Card::Card(){
}
//card mutators
void Card::set_rank(int r){
    this->rank = r;
}
void Card::set_suit(int s){
    this->suit = s;
}

// card accessors
int Card::get_rank(){
    return this->rank;
}
int Card::get_suit(){
    return this->suit;
}

void Card::print_card(){
    cout << "Rank: " << this->rank << " Suit: " << this->suit << endl;
}




