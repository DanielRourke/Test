#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int getSeatAllocation(bool emptySeat[8][4])
{
    bool allocated = false;
    int row = 0 , col = 0;
    while (!allocated)
    {
            cout << "Which seat would you reserve? :" << endl;
            cout <<  "Row  :   " ;
            cin >> row;
            cout << "Column:  " ;
            cin >> col;
            //if ( (row > 0) && (row < 9) && (col > 0) && (col > 5 ) &&  )
            if ( row > 0 && row < 9 && col > 0 && col < 9)
            {
                if((emptySeat[row -1][col -1]))
                {
                    emptySeat[row - 1][col - 1] = false;
                    allocated = true;
                    cout << "Seat in Row :" << row << "  Column: " << col << " has been reserved" << endl;
                }
                else
                {
                    cout << "that seat is unaviable. Please select another" << endl;
                    row = 0 , col = 0;
                }
            }
            else
            {
                cout << "Those seat numbers do not exist" << endl;
            }
    }

    return 0;
}

void displayAllocation(bool emptySeat[8][4])
{
    cout << "  1 2 3 4" << endl;
    for (int row = 0 ; row < 8; row++)
    {
        cout << row + 1;
        for (int col = 0 ; col < 4 ; col++)
        {
            cout << setw(2);

            if (emptySeat[row][col])
                cout << "_";
            else if (!(emptySeat[row][col]))
                cout << "X";
        }
        cout << endl;
    }
    cout << endl;

}
void intitialiseArray(bool emptySeat[8][4])
{
    for (int row = 0 ; row < 8; row++)
    {
        for (int col = 0 ; col < 4 ; col++)
        {
            emptySeat[row][col] = true;
        } 
    }
}
int main()
{
   
    bool emptySeat[8][4];
  //  avilableSeats = 32
  //  int passengers = 0;
    intitialiseArray(emptySeat);
    char ans  = 'y';


    for (int avilableSeats = 32; avilableSeats > 0; avilableSeats--)
    {
        displayAllocation(emptySeat);
        getSeatAllocation(emptySeat);
        cout <<" Empty Seats remain do you wish to allocate another seat ? ( y / n) ";
        cin >> ans;
        if (ans == 'n' || ans == 'N')
            break;
    }
    cout << "Allocation Complete" << endl;
    return 0;
}