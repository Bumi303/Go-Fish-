#include <iostream>
#include <random>
#include <string>
#include "player.h"
#include "deck.h"
#include "game.h"

using namespace std;


/*********************************************************************
** Function: game constructor
** Description: default constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Game::Game(){
}

/*********************************************************************
** Function: start_game
** Description: starts the game of go fish
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::start_game(){
    bool debug_mode = false;
    deal_players();
    debug_mode = welcome();
    bool gofish = false;
    bool game_over = false;
    
    while (game_over == false){
        while (gofish == false && game_over != true){
            cout << endl;
            cout << "Your turn" << endl << endl;
            debug_hand(debug_mode); //shows computer hand
            player1_turn(gofish, debug_mode); // user's turn
            book_finder(0);
            game_over = is_over();
        }
        
        cout << endl;
        gofish = false;
        while (gofish == false && game_over != true){
            cout << "Computer's turn" << endl << endl;
            debug_hand(debug_mode); // shows computer hand
            player2_turn(gofish, debug_mode); // computers's turn
            book_finder(1);
            game_over = is_over();
        }
        cout << endl;
        gofish = false;
    }
}

/*********************************************************************
** Function: welcome
** Description: this welcoms the user and asks them if they want to enter debug mode
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: have to enter a value for choice
*********************************************************************/
// welcoming statement
bool Game::welcome(){
    bool choice;
    cout << endl << "Welcome to Go Fish!" << endl << endl;
    choice = debug_mode();
    if (choice == true){ // shows the computers hand
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************
** Function: deal players
** Description: deals cards to each player
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
// deal players
void Game::deal_players(){ // gives players their cards
    for (int i = 0; i < 14; i++){
        Card c = this->d.remove_card();
        this->players[i % 2].set_a_card(c);
    }
}

/*********************************************************************
** Function: player1_turn
** Description: this does all the work for player one's turn
** Parameters: bool &gofish, bool& debug_mode
** Pre-Conditions: game can't be over and it has to be their turn
** Post-Conditions: have to guess a card that is in their deck
*********************************************************************/
// asks for which card they want
void Game::player1_turn(bool &gofish, bool& debug_mode){
    int ask_card;
    cout << endl << "Your Hand " << endl;
    print_hand(0);
    print_books(0);
    bool empty = if_empty(0);
    if (empty == false){
        cout << endl << "What card do you want to ask for (1 - A,2,3,4,5,6,7,8,9,10,11 - J,12 - Q,13 - K)? ";
        cin >> ask_card;
        cout << endl;
    }
    else{
        cout << endl << "You ran out of cards, pick one from the stack!" << endl;
        add_card(0, -99, gofish);
        debug_hand(debug_mode);
        cout << endl << "Your Hand " << endl;
        print_hand(0);
        print_books(0);
        cout << endl << "What card do you want to ask for (1 - A,2,3,4,5,6,7,8,9,10,11 - J,12 - Q,13 - K)? ";
        cin >> ask_card;
        cout << endl;
        //does this need to ask for card
    }
    bool is_valid = check_if_in_hand(0, ask_card);
    while (is_valid == false){
        cout << "Error, requested card not in hand try again." << endl;
        cout << endl << "What card do you want to ask for (1 - A,2,3,4,5,6,7,8,9,10,11 - J,12 - Q,13 - K)? ";
        cin >> ask_card;
        is_valid = check_if_in_hand(0, ask_card);
    }
    check_if_exists(ask_card, 0, gofish);
}

/*********************************************************************
 ** Function: player2_turn
 ** Description: this does all the work for player two's turn
 ** Parameters: bool &gofish, bool& debug_mode
 ** Pre-Conditions: game can't be over and it has to be their turn
 ** Post-Conditions: n/a
*********************************************************************/
void Game::player2_turn(bool &gofish, bool& debug_mode){
    int ask_card2;
    cout << endl << "Your Hand " << endl;
    print_hand(0);
    print_books(0);
    bool empty = if_empty(1); // need to ask for both ????
    if (empty == false){
        ask_card2 = computer_decision();//computer brain
    }
    else{
        cout << endl << "Computer ran out of cards, it will pick one from the stack!" << endl;
        add_card(1, -99, gofish);
        debug_hand(debug_mode);
        print_hand(0);
        print_books(0);
        ask_card2 = computer_decision();
    }
    
    cout << endl;
    check_if_exists(ask_card2, 1, gofish);
}

/*********************************************************************
** Function: check if exists
** Description: checks if the cards exists in other players hand
** Parameters: int ask_card, int pos, bool &gofish
** Pre-Conditions: a card has to be requested
** Post-Conditions: n/a
*********************************************************************/
// checks if the card exists
void Game::check_if_exists(int ask_card, int pos, bool &gofish){
    gofish = true;
    int card_amount;
    card_amount = players[1 - pos].get_hand().get_n_cards();
    for (int i = 0; i < card_amount; i++){
        if (this->players[1 - pos].get_hand().get_card()[i].get_rank() + 1 == ask_card){
            //remove card and add to other player hand
            card_amount --;
            take_cards(ask_card, pos, card_amount, i);
            gofish = false;
            i = -1;
        }
    }
    if (gofish == true){
        cout << "Go fish!!" << endl;
        add_card(pos, ask_card, gofish);//add card to players deck
    }
}

/*********************************************************************
** Function:add card
** Description: adds a card to a hand
** Parameters: int pos, int ask_card, bool &gofish
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::add_card(int pos, int ask_card, bool &gofish){
    Card c2 = this->d.remove_card();
    this->players[pos].set_a_card(c2);
    int card_amount = players[pos].get_hand().get_n_cards();
    cout << "A " << this->players[pos].get_hand().get_card()[card_amount - 1].get_rank() + 1 << " was fished" << endl;
    if ((ask_card == this->players[pos].get_hand().get_card()[card_amount - 1].get_rank() + 1) && (ask_card != 0)){
        cout << endl << "Fished what you wished! " << endl << endl;
        gofish = false;
    }
}

/*********************************************************************
** Function: take cards
** Description: takes card from other player
** Parameters:int ask_card, int pos, int card_amount, int i
** Pre-Conditions: other card has to be found in hand
** Post-Conditions: n/a
*********************************************************************/
void Game::take_cards(int ask_card, int pos, int card_amount, int i){
    Card c1 = this->players[1 - pos].get_hand().remove_card(i);
    this->players[pos].set_a_card(c1); // takes a card from other hand
}

/*********************************************************************
** Function: print hand
** Description: prints hand with string value notation
** Parameters: pos
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
// prints out a players hand
void Game::print_hand(int pos){
    int card_num = players[pos].get_hand().get_n_cards();
    string arr_rank[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string arr_suit[4] = {"S", "H", "C", "D"};
    string card[52];
    for (int i = 0; i < card_num; i++){
        card[i] = arr_rank[this->players[pos].get_hand().get_card()[i].get_rank()] + arr_suit[this->players[pos].get_hand().get_card()[i].get_suit()];
    }
    
    cout << "| ";
    for (int k = 0; k < card_num; k++){
        cout << card[k] << " | ";
    }
    cout << endl;
}

/*********************************************************************
** Function: debug mode
** Description: shows computers hand
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: user has to choose if they want to use debug mode
*********************************************************************/
// allows user to see computers cards
bool Game::debug_mode(){
    char choice = ' ';
    cout << "Would you like to enter debug mode {y - yes :: n - no}? ";
    cin >> choice;
    cout << endl;
    if (choice == 'y'){
        return true;
    }
    else if (choice == 'n'){
        return false;
    }
    else{
        cout << "Error, try again" << endl;
        debug_mode();
    }
}

/*********************************************************************
** Function: debug_hand
** Description: shows computers hand
** Parameters:bool debug_mode
** Pre-Conditions: debug mode needs to be true
** Post-Conditions: n/a
*********************************************************************/
void Game::debug_hand(bool debug_mode){
    if (debug_mode == true){ // shows the computers hand
        cout << "Computer's Hand" << endl;
        print_hand(1);
        print_books(1);
        cout << endl;
    }
}

/*********************************************************************
** Function: book finder
** Description: finds if there is a book in a hand
** Parameters: pos
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::book_finder(int pos){
    int hand_size = players[pos].get_hand().get_n_cards();
    int temp_rank;
    int count;
    for (int i = 0; i < hand_size; i++){
        temp_rank = this->players[pos].get_hand().get_card()[i].get_rank();
        count = 0;
        for (int k = 0; k < hand_size; k++){ // iterates throught the books
            if (this->players[pos].get_hand().get_card()[k].get_rank() == temp_rank){
                count++;
                if (count == 4){
                    add_book(temp_rank, pos);
                    i = 100;
                    k = 100;
                    break;
                }
            }
        }
    }
}

/*********************************************************************
** Function: add book
** Description: adds a book to the correct player
** Parameters: int rank, int pos
** Pre-Conditions: a book has to be found
** Post-Conditions: n/a
*********************************************************************/
void Game::add_book(int rank, int pos){
    int num_books = this->players[pos].get_n_books();
    this->players[pos].set_book(rank);// adds a book
    delete_cards(pos, rank);
}

/*********************************************************************
** Function: delete cards
** Description: deletes cards from a hand
** Parameters: int pos, int rank
** Pre-Conditions: a card has to be found
** Post-Conditions: once card it gone
*********************************************************************/
void Game::delete_cards(int pos, int rank){
    int hand_size = players[pos].get_hand().get_n_cards();
    for (int i = 0; i < hand_size; i++){
        if (rank == this->players[pos].get_hand().get_card()[i].get_rank()){
            this->players[pos].get_hand().delete_card(i); // deletes requested card
            hand_size--;
            i = -1;
        }
    }
}

/*********************************************************************
** Function: print books
** Description: prints all the books of the player and the computer
** Parameters: pos
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::print_books(int pos){
    int num_books = this->players[pos].get_n_books();
    if (pos == 1){
        cout << "Computer's books: ";
    }
    else if(pos == 0){
        cout << "Your books: ";
    }
    
    for (int i = 0; i < num_books; i++){
        cout << this->players[pos].get_books()[i] + 1 << "'s, ";
    }
    cout << endl;
}

/*********************************************************************
** Function: check if in hand
** Description: checks if a card is in hand when requesting a cards
** Parameters: int pos, int ask_card
** Pre-Conditions: user has to ask for a card
** Post-Conditions: either found or not
*********************************************************************/
//check if the user has the requested card
bool Game::check_if_in_hand(int pos, int ask_card){
    bool in_hand = false;
    int card_amount = players[pos].get_hand().get_n_cards();
    for (int i = 0; i < card_amount; i++){
        if (this->players[pos].get_hand().get_card()[i].get_rank() + 1 == ask_card){
            return true;
        }
    }
    if (in_hand == false){
        return false;
    }
}

/*********************************************************************
** Function: computer decision
** Description: gives the computer the option to find a card
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Game::computer_decision(){
    srand(time(NULL));
    bool found = false;
    int random_pos;
    int card_amount = players[1].get_hand().get_n_cards();
    while (found == false){
        random_pos = rand() % 13;
        for (int i = 0; i < card_amount; i++){
            if (random_pos == this->players[1].get_hand().get_card()[i].get_rank()){
                cout << endl << "Computer ask for a " << random_pos + 1 << endl;
                return random_pos + 1;
            }
        }
    }
}

/*********************************************************************
** Function: is over
** Description: checks whether the game is over
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: if game is over returns true
*********************************************************************/
bool Game::is_over(){
    if (this->players[0].get_n_books() + this->players[1].get_n_books() == 13){
        cout << "Game Over!" << endl;
        if (this->players[0].get_n_books() > this->players[1].get_n_books()){
            cout << "Congrats you win!" << endl;
            print_books(0);
            print_books(1);
        }
        else if (this->players[0].get_n_books() < this->players[1].get_n_books()){
            cout << "Computer wins ..." << endl;
            print_books(0);
            print_books(1);
        }
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************
** Function: if empty
** Description: checks if a hand is empty and acts accordingly
** Parameters: pos
** Pre-Conditions: n/a
** Post-Conditions: returns true if no cards are in hand false otherwise
*********************************************************************/
bool Game::if_empty(int pos){
    if (this->players[pos].get_hand().get_n_cards() == 0){ //checks if the hand is empty
        return true;
    }
    else{
        return false;
    }
}

