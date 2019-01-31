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
            self.get_hand().draw();
            self.disp_hand();
            cout << self.get_hand().total_points() << endl;
            string done;
            cout << "Do you want another card? (y/n)" << endl;
            cin >> done;
            if (done == "n")
            {
                break;
            }
            else
            {
                self.get_hand().draw();
            }
        }
        break;
    }
    
    


}