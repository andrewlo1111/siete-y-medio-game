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
    while (true)
    {
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
            cout << self.get_hand().total_points() << endl;
            if (self.get_hand().bust())
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
            self.get_hand().draw();
        }
        break;
    }
    
    


}