#include "Board.cpp"
#include "Human.h"
#include <iostream>
#include <string>
using namespace std;

class MKgame
{
    private:
    Board * gameBoard;
    Player ** players; 
    int playerCount;
    public:
    MKgame()
    {
        int m, k ,p, max_players = 4; 
        char symbols[] = {'X','O','S','T'};

        cout << "What size board would you like to play on ? ";
        m = getNumber();
        cout << "How many in a row do you need to win ? ";
        k = getNumber(m);

        gameBoard = new Board(m, k);

        cout << "How many players would you like ? ";
        playerCount = getNumber(max_players);



        players = new Player*[playerCount];
        for (int i = 0; i < playerCount; i++)
        {
            players[i] = new Human(i, symbols[i]) ;
        }

    }
    ~MKgame()
    {
        delete gameBoard;
     //   delete [] players;
    }
    int run()
    {
    gameBoard->printBoard();

        return 0;
    }
    int play()
    {
        int index = 0;
        while(true)
        {
            int x,y;
            gameBoard->printBoard();
            do
            {
                players[index]->getMove( x , y);
                x--;
                y--;
            }
            while ( !(gameBoard->isValidMove(x , y ))  );
           // players[index]->getMove( x , y);
            
            gameBoard->addMove(x ,y , players[index]->retSymbol());

            index = (index + 1) % playerCount;
        }
    }
    int getNumber(int max = 100000) //gets a interger
    {

        int ret = 0 ;

        while (true)
        {
            cin >> ret;
            if(cin.fail() || ret > max ||  ret == 0)
            {   
                cout << "Invailed input! try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                return ret;
            }

        }
       
        return -1;
    }
};