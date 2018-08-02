#include<iostream>
#include<iomanip>
#include<ctime>


using namespace std;

int main() {
	srand(time(0));
	const int ROWS=3;
	const int COLS=4;

	int table[ROWS][COLS];

	for (int i = 0; i < ROWS; i ++) {
		for (int j = 0; j < COLS; j++)   {
			table[i][j] = rand()%3-1;
		}
	}

	for (int i = 0; i < ROWS; i ++)  {
		for (int j = 0; j < COLS; j++)
			cout << setw(3) << table[i][j];

		cout << endl;
	 }

	return 0;
}
