#include <iostream>
#include <string>
#include <istream>
#include <iomanip>

using namespace std;



int getSeatAllocation(bool emptySeat[8][4])
{
    bool allocated = false;
    char inpRow, inpCol;
    int row = 0 , col = 0;
    while (!allocated)
    {
            cout << "Which seat would you reserve? (row : column) : ";
            cin >> row >> col;
            if (cin.fail())
            {
                row = 0;
                col = 0;
                cin.clear();
                cin.ignore(1000, '\n');
            }

            if ( row > 0 && row < 9 && col > 0 && col < 5)
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
    int avilableSeats = 32, passengers;
    intitialiseArray(emptySeat);
    char ans;
    do
    {

        cout << "How many Passengers booking ? " ;
        cin >> passengers;
        if (cin.fail())
        {
            cout << "invaild input" << endl;
            passengers = 0;
            cin.clear();
            cin.ignore(1000 , '\n');
        }
        for (int i = 0; i < passengers; i++)
        {
            displayAllocation(emptySeat);
            getSeatAllocation(emptySeat);
            avilableSeats--;
        }
        cout << "Do you wish to make another booking ? ( y / n) ";
        cin >> ans;

    } while ((ans != 'n' && ans != 'N') && avilableSeats > 0);

    cout << "Allocation Complete" << endl;
    return 0;
}