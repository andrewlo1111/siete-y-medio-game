# siete-y-medio-game

Siete y medio game (Similar to blackjack)

Documentation:

Card Class

    Card(): constructor takes in no values, randomly generates a card between 2-7 or A,J,Q,K with suit
  
    string get_spanish_suit(): returns the spanish version of the suit of card drawn
  
    string get_spanish_rank(): returns the spanish version of the name of the card drawn
  
    string get_english_suit(): returns english suit of card drawn
  
    string get_english_rank(): returns english name of card drawn
  
    int get_rank() const: returns the rank of the card
  
    double get_value() const: returns the value that the card will have in the game
  
  
  
 Hand Class
 
    Hand(): generates a random card for hand
  
    void draw(): adds a card to your hand
  
    void disp() const: displays the cards in your hand
  
    int num_of_cards() const: returns the number of cards in your hand
  
    double total_points(): returns the total value of your hand
  
    bool bust() const: if hand total is above 7.5, then returns true
  
    void discard_all(): resets hand to have nothing
  
  
  
 Player Class 
 
    Player(int m = 0): Player inputs amount of money they want to start with and also gets a starting hand
      -if no input given, then player starts with 0
    
    void bet(int amount): Player loses the amount of money they bet
      -if amount is greater than what player has, will be forced to put a smaller amount
  
    int get_money(): returns amount of money that player has
  
    Hand& get_hand(): returns a reference to hand that player currently is holding
  
    Hand get_hand() const: returns a const version of hand that player currently is holding
  
    void disp_hand(): prints hand 
  
    void result(Player& dealer, int bet_amount): determines winner of game between dealer and player
      - if dealer's hand's value is greater than player's hand's, dealer gets money that player bets
      - if dealer's hand's value is equal to player's hand's, player gets back money he bet
      - if dealer's hand's value is lower than player's hand's, player gets back money he bet and additional betting amount from dealer
    
    void newHand(): resets hand of player
  
  
  Non-Member Class Functions
  
    ostream& operator<<(ostream& out, Card c): prints card with english suit and rank
  
  
  
  
