#include "cards.h"
#include <cstdlib>
#include <iostream>


/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
    int r = 1 + rand() % 4;
    switch (r) {
    case 1: suit = OROS; break;
    case 2: suit = COPAS; break;
    case 3: suit = ESPADAS; break;
    case 4: suit = BASTOS; break;
    default: break;
    }

    r = 1 + rand() % 10;
    switch (r) {
    case  1: rank = AS; break;
    case  2: rank = DOS; break;
    case  3: rank = TRES; break;
    case  4: rank = CUATRO; break;
    case  5: rank = CINCO; break;
    case  6: rank = SEIS; break;
    case  7: rank = SIETE; break;
    case  8: rank = SOTA; break;
    case  9: rank = CABALLO; break;
    case 10: rank = REY; break;
    default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
    case OROS:
        suitName = "oros";
        break;
    case COPAS:
        suitName = "copas";
        break;
    case ESPADAS:
        suitName = "espadas";
        break;
    case BASTOS:
        suitName = "bastos";
        break;
    default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
    case AS:
        rankName = "As";
        break;
    case DOS:
        rankName = "Dos";
        break;
    case TRES:
        rankName = "Tres";
        break;
    case CUATRO:
        rankName = "Cuatro";
        break;
    case CINCO:
        rankName = "Cinco";
        break;
    case SEIS:
        rankName = "Seis";
        break;
    case SIETE:
        rankName = "Siete";
        break;
    case SOTA:
        rankName = "Sota";
        break;
    case CABALLO:
        rankName = "Caballo";
        break;
    case REY:
        rankName = "Rey";
        break;
    default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
    string eng_suit;
    switch (suit)
    {
    case OROS:
        eng_suit = "diamonds";
        break;
    case COPAS:
        eng_suit = "clubs";
        break;
    case ESPADAS:
        eng_suit = "spades";
        break;
    case BASTOS:
        eng_suit = "heart";
        break;
    }
    return eng_suit;

}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
    string eng_rank;
    switch (rank)
    {
    case AS:
        eng_rank = "Ace";
        break;
    case DOS:
        eng_rank = "Two";
        break;
    case TRES:
        eng_rank = "Three";
        break;
    case CUATRO:
        eng_rank = "Four";
        break;
    case CINCO:
        eng_rank = "Five";
        break;
    case SEIS:
        eng_rank = "Six";
        break;
    case SIETE:
        eng_rank = "Seven";
        break;
    case SOTA:
        eng_rank = "Jack";
        break;
    case CABALLO:
        eng_rank = "Queen";
        break;
    case REY:
        eng_rank = "King";
        break;
    }
    return eng_rank;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    if (rank > 7)
    {
        return static_cast<int>(rank) + 3;
    }
    return static_cast<int>(rank) + 1;
}

double Card::get_value() const
{
    double value = get_rank();
    if (get_rank() >= 10)
    {
        value = .5;
    }
    return value;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}

ostream& operator<<(ostream& out, Card c)
{
    out << c.get_english_rank() << " of " << c.get_english_suit();
    return out;
}




/* *************************************************
Hand class
************************************************* */
// Implemente the member functions of the Hand class here.
Hand::Hand()
{
    Card first_card;
    hand.push_back(first_card);
}

void Hand::draw()
{
    Card next_card;
    hand.push_back(next_card);
}

int Hand::num_of_cards()
{
    return hand.size();
}

void Hand::disp()
{
    for (int i = 0; i < hand.size(); i++)
    {
        cout << hand[i] << endl;
    }
}

double Hand::total_points()
{
    double points = 0;
    for (int i = 0; i < num_of_cards(); i++)
    {
        double value = hand[i].get_value();
        points += value;
    }
    return points;
}


/* *************************************************
Player class
************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int m)
{
    money = m;
    Hand start_card;
    your_hand = start_card;
}

void Player::bet(int amount)
{
    while (amount > money)
    {
        cout << "Cannot bet more money than you already have. \n";
    }
    money -= amount;
}

bool Player::no_more_money()
{
    if (money == 0)
    {
        return true;
    }
    return false;
}

int Player::get_money()
{
    return money;
}

void Player::disp_hand()
{
    your_hand.disp();
}

Hand Player::get_hand()
{
    return your_hand;
}