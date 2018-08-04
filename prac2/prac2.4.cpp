#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int getSeatAllocation(char seats[][8])
{
    bool allocated = false;
    int row = 0 , col = 0;
    while (!allocated)
    {
            cout << "Which seat would you reserve? :" << endl;
            cin >> row, col;
            if (seats[row][col] == '_')
            {
                seats[row][col] = 'X';
                allocated = true;
                cout << "Seat " << row << " " << col << " has been reserved" << endl;
             
            }
            else
            {
                 cout << "that seat is unaviable. Please select another" << endl;

            }
               
    }

    return 0;
}

bool vaildSelection(char)

int displayAllocation(char seats[][8])
{
    cout << "  1 2 3 4" << endl;
    for (int row = 0 ; row < 8; row++)
    {
        cout << row + 1;
        for (int col = 0 ; col < 4 ; col++)
        {
            cout << setw(2) << seats[row][col];
        }
        cout << endl;
    }
}

int intialiseSeats(char seats[][8])
{
    //char emptySeat = '_';
    for (int row = 0 ; row < 8; row++)
        for (int col = 0 ; col < 4 ; col++)
        {
            seats[row][col] = '_';
        }
    return 0;
}


int main()
{
   
    bool seats[4][8];
    intialiseSeats(seats);
    displayAllocation(seats);

    for (int avilableSeats = 32; avilableSeats > 0; avilableSeats--)
    {
        getSeatAllocation(seats);
        displayAllocation(seats);


        char ans  = 'y';
        cout << avilableSeats << " seats remain do you wish to allocate another seat ? ( y / n) ";
        cin >> ans;

        if (ans == 'n' || ans == 'N')
            break;
           
        
    }
    cout << "Allocation Complete" << endl;
    return 0;
}