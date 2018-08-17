
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void printAvailableSeats(char seats[][4], int ROWS, int COLS)
{
    cout << " ";
    for (int i = 0 ; i < COLS ; i++)
    {
        cout << " " << i ;
    }
    cout << endl;
    for (int i = 0; i < ROWS; i ++) 
    {
        cout << i +1 ;
		for (int j = 0; j < COLS; j++)   
		{
			cout << setw(2)<< seats[i][j];
		}
		
		cout << endl;
	}
}

void intialise(char seats[][4], int ROWS, int COLS)
{
		for (int i = 0; i < ROWS; i ++) 
		{
		    for (int j = 0; j < COLS; j++)   
		    {
			    seats[i][j] = '_';
		    }
		}
}

void bookSeats(char seats[][4], int ROWS, int COLS)
{
    char ans;
    int aviableSeats = ROWS * COLS;
    int customers, row, column;
   
    do
    {

        if(cin.fail())
        {
         cin.clear();
         cin.ignore(1000, '\n');
        }
        cout <<   "How many seats would you like to book: ";
        cin >> customers ;  
     
        for (int i = 0 ; i < customers ; i++)
        {
            do
            {
                if(cin.fail())
                {
                 cin.clear();
                 cin.ignore(1000, '\n');
                }
                cout << "Locatation for booking " << i + 1 << " with row and column: ";
                cin >> row >> column;
                row--;
                column--;
                
            }while ((row < 0 ) || (row > 7) ||  (column < 0) || (column > 3) || seats[row][column] == 'X') ;
            
            aviableSeats--;
            seats[row][column] = 'X';
        }

        printAvailableSeats(seats, ROWS, COLS);
        cout << "Allocate more seats?(y/n followed by return): ";
        cin >> ans;
   

        
    }while(aviableSeats > 0 && (ans != 'n' && ans != 'N' ) );
}


int main()
{
	const int ROWS=8;
	const int COLS=4;

	char table[ROWS][COLS];

	
	intialise(table, ROWS, COLS);
	printAvailableSeats(table, ROWS, COLS);
	bookSeats(table, ROWS, COLS);

}