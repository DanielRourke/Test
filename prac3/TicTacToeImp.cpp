

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip>
 
#include "TicTacToe.h"

using namespace std;

void ticTacToe::play()
{
    bool done = false;
    char player = 'X';

    displayBoard();

    while (!done)
    {
        done = getXOMove(player);

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

void ticTacToe::displayBoard() const
{
    for (int i = 0 ; i < size ; i++)
    {
        cout << "    " << i + 1;
    }
   cout << endl << endl;

    for (int row = 0; row < size; row++)
    {
        cout << row + 1;

        for (int col = 0; col < size; col++)
        {
            cout << setw(3) << board[row][col];

            if (col < size -1)
                cout << " |";

        }

        cout << endl << " " ;

        
        for (int col = 0; col < size; col++)
        {
            if (row < size - 1)
            {
                cout << "____";
                if (col < size -1)
                {
                    cout << "|";
                }
        
            }
            
        }
        cout << endl;
    }

    cout << endl;
}

bool ticTacToe::isValidMove(int row, int col) const
{
    if (true /*See your solution to Practical 2 Task 2.3 or ask your tutor for a solution */)
        return true;
    else
        return false;
}

bool ticTacToe::getXOMove(char playerSymbol)
{
    int row, col;

    do 
    {
        cout << "Player " << playerSymbol 
             << " enter move: ";
        cin >> row >> col;
        cout << endl;
    }
    while (!isValidMove(row - 1, col - 1) );

    row--;
    col--;

    noOfMoves++;

    board[row][col] = playerSymbol;
    displayBoard();

    status gStatus = gameStatus(playerSymbol , row, col);

    if (gStatus == WIN)
    {
        cout << "Player " << playerSymbol << " wins!" << endl;
        return true;
    }
    else if (gStatus == DRAW)
    {
        cout << "This game is a draw!" << endl;
        return true;
    }
    else if(noOfMoves >= 9) {
    	return true;
    } else
        return false;
}

status ticTacToe::gameStatus(char playerSymbol, int row, int col)
{
    //North South East West Loop
    for (int x = -1 ; x < 2; x++)
        {
        for(int y = -1; y < 2 ; y++)
        {
            int r = row + x;
            int c = col + y;
            int counter = 1; 

            while( (r > -1 && r < size && c > -1 && c < size && board[r][c] == playerSymbol) && (x != 0 || y != 0))
            {
                r += x;
                c += y;
                counter++;
                cout << winThreshold << " " << counter;
                if (counter == winThreshold)
                {
                    return WIN;
                }
                
            }
        }
    }  
   return CONTINUE;
}

void ticTacToe::reStart()
{
    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe(int s = 3, int k = 3)
{
    size = s;
    winThreshold = k;


    board = new char*[size];
    for (int i = 0; i < size; i++)
    {
        board[i] = new char[size];
    }

    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::~ticTacToe()
{
    for(int i = 0; i < size; ++i) {
        delete [] board[i];
    }
    delete [] board;
}