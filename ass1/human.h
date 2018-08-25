 #include"Player.h"
// #include "Board.h"
#include <iostream>

using namespace std;

class Human : public Player
{
    public:
    Human(int i, char s) : Player(i,s) 
    {
        name += " (Human)";
        // cout << "What is the name for " << name;
        // cin >> name;
        // cout << " What is the Player Symbol for" ;
        // cout << name << " : " ;
        // cin >> playerSymbol ;
    }

    void getMove(int& x ,int& y)
    {
        do
        {
            cout << name << "  move : ";
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }

           cin >> x >> y ;
           
        }
        while (cin.fail());
    }





};