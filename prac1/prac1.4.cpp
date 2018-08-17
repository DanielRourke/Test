#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int month, day;
    cout << "Welcome to your friendly weather program.\n"
         << "Enter today's date as two integers for the month and the day:\n";
    //takes to intergers
    cin >> month;
    cin >> day;
    
    if ( (month < 12 && month > 0) && ( day < 31 && day > 0 ) )
    {
        srand(month*day);
    }
    else
    {
        srand(time(0));
      //  cout << time(0) ;
    }
    //Uses intergers to seed random

    int prediction;
    char ans;
    cout << "Weather for today:\n";

    //switch case 3 options for random number
    //prints one of the three
    do {
        prediction = rand() % 3;
        switch (prediction) {
            case 0:
                cout << "The day will be sunny!!\n";
                break;
            case 1:
                cout << "The day will be cloudy.\n";
                break;
            case 2:
                cout << "The day will be stormy!.\n";
                break;
            default:
                cout << "Weather program is not functioning properly.\n";
        }
        //checks the user to see if they want to continue
        cout << "Want the weather for the next day?(y/n): ";
        cin >> ans;
        // if the answer is yes repeat
    } while (ans == 'y' || ans == 'Y');
    cout << "That's it from your 24 hour weather program.\n";
    return 0;
}