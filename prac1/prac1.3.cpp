
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/*
Task 1.3:
Write a C++ program to perform the following:
a) Prompt the user to input two integers: firstNum and secondNum.
b) If firstNum is larger than or equals to secondNum, ask for input them again;
otherwise, do the following.
c) Output all odd numbers between firstNum and secondNum.
d) Output the sum of all even numbers between firstNum and secondNum.
e) Output up to the first 10 integers between firstNum and secondNum (if there
are no ten integers in between, output whatever there are).
f) Output the square of the odd numbers between firstNum and secondNum
Implement c)-f) as separate functions and call them in the main function. It is
assumed that the input device is keyboard and the output device is screen.
*/

//the point at which to many values are printed
const int MAX = 10000;

//finds and prints all odd numbers
int outputOdd(int first, int second)
{
    cout << "c) The odd numbers are: ";

    for( int i = first + 1; i < second; i++)
    {
        if (i % 2 != 0)
        {
             cout << i << ", ";
        }
    }
    cout << endl;
    return 0;
}
//Sums all the even numbers
int  outputSumEven(int first, int second)
{
    cout << "d) The sum of the even numbers is: ";
    int sum = 0;

    for(int i = first + 1; i < second; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + i;
        }
    }

    cout << sum << endl;
    return 0;
}
//outputs the first 10 numbers if available
int outputFirstTen(int first, int second)
{
    cout << "e) The first ten digits are: ";
 
    for( int i = first + 1; i < first + 11 && i < second ; i++)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
//squares all the odd numbers
int outputSqrOdd(int first, int second)
{
    cout << "f)i) The square of the odds : ";
    int dblcount = 0;
    for( int i = first + 1; i < second; i++)
    {
        if (i % 2 != 0)
        {
            dblcount = dblcount + pow(i,2);

             cout << pow(i,2) << ", " ;
        }
    }
    cout << endl;
    cout << "f)ii) Sum of the Squares: " << dblcount << endl;
    return 0;
}
 
int main()
{
    int firstNum = 0 , secondNum = 0;
    string letter = "a)";

    while(firstNum >= secondNum)
    {
        cout << letter << " Please Enter two intergers the first interger must be smaller than second" << endl;
        cin >> firstNum >> secondNum;
        if ( isnan(secondNum) || isnan(firstNum) )
        {
            cout << "Intergers are numbers" << endl;
            firstNum = 0, secondNum = 0;
        }
        else if (secondNum - firstNum < 2)
        {
            cout << "The are no numbers between" << firstNum << " and " << secondNum << " do you wish to procede y / n ? ";
            char answer;
            cin >> answer;
            if (answer != 'y')
            {
                firstNum = 0, secondNum = 0;
            }
        }
        else if ((secondNum - firstNum > MAX))
        {
            cout << "The are shedLoads of numbers between" << firstNum << " and " << secondNum << " do you wish to procede y / n ? ";
            char answer;
            cin >> answer;
            if (answer != 'y')
            {
                firstNum = 0, secondNum = 0;
            }
        }

        letter = "b)";
    }
    //c)
    outputOdd(firstNum, secondNum);
    //d)
    outputSumEven(firstNum, secondNum);
    //e)
    outputFirstTen(firstNum, secondNum);
    //f)
    outputSqrOdd(firstNum, secondNum);

    return 0;
}
