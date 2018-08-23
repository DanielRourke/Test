
#include <iostream>

using namespace std;
class Board
{
    private:
    char** grid;
    int size;


    public:
    Board(int);
    void printBoard();

};
Board::Board(int s = 3)
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
            grid[i][j] == ' ';
        }
    }

}

void Board::printBoard()
{

    for (int i = 0 ; i < size; i++)
    {
        cout << "  " << i + 1 ;
    }

    cout << endl << " " << (char)201;

    for (int i = 0; i < size; i++)
    {
        cout << (char)205 << (char)205 ;
        if (i < size -1)
        {
            cout << (char)203 ;
        }
    }

    cout << (char)187;

    for (int i = 0 ; i < size; i++)
    {
        std::cout << std::endl << i + 1;
        for (int j = 0 ; j < size; j++)
        {
            cout << (char) 186 << grid[i][j] ;
        }

    }
}

int main()
{
    Board brd(3);
    brd.printBoard();
    return 0;
}