
//Main program

#include <iostream>


//#include "TicTacToe.h"
 #include "TicTacToeImp.cpp"
 
using namespace std;

int main()
{
	 ticTacToe game(5,5);

     game.play();

     return 0;
}