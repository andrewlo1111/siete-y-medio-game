#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {
public:
    // Constructor assigns random rank & suit to card.
    Card();

    // Accessors 
    string get_spanish_suit() const;
    string get_spanish_rank() const;

    /*
    These are the only functions you'll need to code
    for this class. See the implementations of the two
    functions above to get an idea of how to proceed.
    */
    string get_english_suit() const;
    string get_english_rank() const;

    // Converts card rank to number.
    // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
    int get_rank() const;
    double get_value() const;

    // Compare rank of two cards. E.g: Eight<Jack is true.
    // Assume Ace is always 1. 
    // Useful if you want to sort the cards.
    bool operator < (Card card2) const;

private:
    suit_t suit;
    rank_t rank;
};

ostream& operator<<(ostream& out, Card c);


class Hand {
public:
    // A vector of Cards
    Hand();
    void draw();
    void disp() const;
    int num_of_cards() const;
    double total_points() const;
    bool bust() const;
    void discard_all();
    // You decide what functions you'll need...

private:
    // You decide what fields you'll need...
    vector<Card> hand;
};


class Player {
public:
    // Constructor. 
    //    Assigns initial amount of money 
    Player(int m = 0);
    void bet(int amount);    //allows player to place a specific amount of money to bet
    bool no_more_money() const;   //returns true if player no longer has any money
    int get_money() const;
    Hand& get_hand();
    Hand get_hand() const;
    void disp_hand() const;
    void result(Player& dealer, int bet_amount);
    void new_hand();
    //void draw();

    //void draw();

    // You decide what functions you'll need...

private:
    int money;
    Hand your_hand;
    // You decide what extra fields (if any) you'll need...
};



#endif