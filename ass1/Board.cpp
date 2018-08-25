#include "Board.h"

using namespace std;

Board::Board(int s = 3, int k = 3)
{
    size = s;
    grid = new char*[size];

    for (int i= 0 ; i < size; i++)
    {
        grid[i] = new char[size];
    }

    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            grid[i][j] = ' ';
        }
    }

}

void Board::printBoard()
{
    //top numbers
    cout << " ";
    for (int i = 0 ; i < size; i++)
    {
        cout << "  " ;
        if(i < 10)
        {
            cout << " ";
        }
        cout << i + 1 ;
    }
    //
    cout << endl ;

    //start next line 
     //draw top line
    cout << "  " << (char)201;

    for (int i = 0; i < size; i++)
    {
        cout << (char)205 << (char)205 << (char)205  ;
        if (i < size -1)
        {
            cout << (char)203 ;
        }
    }

    cout << (char)187;
    
    //draw line with board values
 
    for (int i = 0 ; i < size; i++)
    {
        cout << endl ;
        if(i < 9)
        {
            cout << " ";
        }
        
        cout << i + 1;

        for (int j = 0 ; j < size; j++)
        {
            cout << (char) 186 << " " << grid[i][j] << " " ;
        }

        cout << (char)186;

   //draw line in the middle

        if (i < size -1)
        {
        
        cout << endl << "  " << (char)204;
        
        for (int i = 0; i < size; i++)
        {
            cout << (char)205 <<(char)205 <<(char)205 ;
            if (i < size -1)
            {
                cout  << (char)206;
            }
            else
            {
                cout << (char)185;
            }
        }


        //cout << (char)206 ;
        }
        
    }
    
    //draw last line
    cout << endl << "  " << (char)200;

    for (int i = 0; i < size; i++)
    {
        cout << (char)205 << (char)205 << (char)205 ;
        if (i < size -1)
        {
            cout << (char)202 ;
        }
    }
    cout << (char)188 << endl;
}

bool Board::isValidMove(int x, int y)
{
    if(grid[x][y] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

 void Board::addMove(int x , int y, char c)
 {
     grid[x][y] = c;
 }

