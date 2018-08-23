#include<iostream>
#include<iomanip>
#include<ctime>


using namespace std;

int main() {
	srand(time(0));
	const int ROWS=3;
	const int COLS=4;


	int table[ROWS][COLS];
	int sumOfZeros= 0, row , column;
	

	for (int i = 0; i < ROWS; i ++) {
		for (int j = 0; j < COLS; j++)   
		{
			table[i][j] = rand()%3-1;
			if (table[i][j] == 0)
			{
				sumOfZeros++;
			}
		}
	}

	for (int i = 0; i < ROWS; i ++)  {
		for (int j = 0; j < COLS; j++)
		{
			cout << setw(3) << table[i][j];
		}
	
		cout << endl;
	 }

	cout << "There are " << sumOfZeros << " is this table" << endl;
	do
	{	
		cout << "Please enter your Co-ords:" ;
		cin >> row >> column;
	}
	while (row > ROWS -1 || column > COLS -1 || row < 0 || column < 0);


	for (int i = 0; i < ROWS; i ++)  
	{
		for (int j = 0; j < COLS; j++)
		{
			if ( ( (j == column - 1 || j == column + 1 ) && (i == row) ) || ( (j == column) && (i == row - 1 || i == row + 1 ) ) )
			{
				cout << setw(3) << table[i][j];
			}
			else
			{
				cout << setw(3) << " ";
			}
		}
	
		cout << endl;
	 }
	return 0;
}
