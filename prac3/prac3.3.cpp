/* Task 3.3: Use OO paradigm to redo Task 2.4 of Practical 2. Create a class with at
least a data member for storing seats availability. The data member must be a two
dimensional array. Your class must also contain a constructor and at least two
member functions: one for seat booking and the other for displaying seat availability
status. */


#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


class Plane
{
    private: 
    char** seats;
    int ROWS;
    int COLS;
    int aviableSeats;
    public:
    Plane(int , int);
    void showSeats();
    void bookSeats();
    ~Plane();

};



Plane::Plane(int r = 8, int c = 4)
{
    ROWS = r, COLS = c, aviableSeats = r * c;

    seats = new char*[r];

    for (int i = 0 ; i < r; i++)
    {
        seats[i] = new char[c];
    }
       
// cout << "2";
// cout << seats[0][0];


	for (int k = 0; k < r ; k ++)
    {
        for (int j = 0; j < c; j++)   
        {
            seats[k][j] = '_'; 
       
        }
		   
    } 
	


// cout << "3";
           
}

Plane::~Plane()
{
    for (int i = 0 ; i < COLS; i++)
        delete [] seats[i];

    delete [] seats;
}


void Plane::showSeats()
{
    cout << " ";
    for (int i = 0 ; i < COLS ; i++)
        cout << " " << i + 1 ;
    
    cout << endl;

    for (int i = 0; i < ROWS; i ++) 
    {
        cout << i +1 ;

		for (int j = 0; j < COLS; j++)   
			cout << setw(2)<< seats[i][j];
		
		cout << endl;
	}
}


void Plane::bookSeats()
{
    char ans;
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

        showSeats();
        cout << "Allocate more seats?(y/n followed by return): ";
        cin >> ans;
   
    }while(aviableSeats > 0 && (ans != 'n' && ans != 'N' ) );
}


int main()
{
    Plane airbus;
    airbus.showSeats();
    airbus.bookSeats();
    return 0;
}