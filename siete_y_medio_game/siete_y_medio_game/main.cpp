#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

int main()
{
    srand(time(NULL));
    int start_amount;
    cout << "How much would you like to enter the game with?" << endl;
    cin >> start_amount;
    Player self(start_amount);
    Player dealer(1000);                                        //dealer starts with 1000
    Hand* your_hand = &(self.get_hand());
    Hand* dealer_hand = &(dealer.get_hand());

    while (self.get_money() > 0 || dealer.get_money() > 0 )   //while either player goes broke
    {
        //your turn
        cout << "You have $" << self.get_money() << endl;
        cout << "How much would you like to bet?" << endl;
        int betting_amount;
        cin >> betting_amount;
        self.bet(betting_amount);

        while (true)
        {
            cout << "Your cards: \n";
            self.disp_hand();
            cout << "\nYour total points is: ";
            cout << (*your_hand).total_points() << endl;
            if ((*your_hand).bust())
            {
                cout << "Sorry you busted." << endl << endl;
                break;
            }
            string done;
            cout << "Do you want another card? (y/n) ";
            cin >> done;
            while (done != "n" && done != "y")
            {
                cout << "Not a valid input" << endl;
                cin >> done;
            }
            if (done == "n")
            {
                break;
            }
            cout << endl;
            (*your_hand).draw();
        }

        //dealer's turn
        while ((*dealer_hand).total_points() < 5.5)                 //dealer will stop drawing when total is above 5.5
        {
            cout << "Dealer's cards: " << endl;
            dealer.disp_hand();
            cout << (*dealer_hand).total_points() << endl << endl;
            (*dealer_hand).draw();
            
        }
        cout << (*dealer_hand).total_points() << endl;
        self.result(dealer, betting_amount);                        //result of game is displayed with money distributed
        self.new_hand();                                            //resets game to a new hand 
        dealer.new_hand();
    }
    
    


}