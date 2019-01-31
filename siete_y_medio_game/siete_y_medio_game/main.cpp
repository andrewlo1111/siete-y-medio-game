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
    Player dealer;
    Hand your_hand = self.get_hand();
    Hand dealer_hand = dealer.get_hand();

    while (true)
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
            cout << your_hand.total_points() << endl;
            if (your_hand.bust())
            {
                cout << "Sorry you busted." << endl;
                break;
            }
            string done;
            cout << "Do you want another card? (y/n) ";
            cin >> done;
            if (done == "n")
            {
                break;
            }
            cout << endl;
            self.draw();
        }

        //dealer's turn
        /*while (dealer_hand.total_points() < 5.5)
        {
            cout << "Dealer's cards: " << endl;
            dealer.draw();
        }*/
        
        break;
    }
    
    


}