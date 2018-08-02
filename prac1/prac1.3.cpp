#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int * outputOdd(int first, int second)
{
    int arraySize = floor((second - first) / 2.0);
    int oddNumArray [arraySize];

    for( int i = first + 1; i < second; i++)
    {
        if (i % 2 != 0)
        {
             oddNumArray[i] = i;
             cout << i << endl;
        }
       
    }
    return oddNumArray;
}
int main()
{
    int firstNum = 0 , secondNum = 0;
    string letter = "a)";

    while(firstNum >= secondNum)
    {
        cout << letter << " Please Enter two intergers the first interger must be smaller than second" << endl;
        cin >> firstNum >> secondNum;
        letter = "b)";
    }
    //c)
    int *odds = outputOdd(firstNum, secondNum);
    //d)
  //  outputSumEven(firstNum, secondNum);
    //e)
  //  outputFirstTen(firstNum, secondNum);




    return 0;
}
