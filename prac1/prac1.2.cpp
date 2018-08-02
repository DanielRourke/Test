#include <iostream>
#include <string>

using namespace std;


//print values and change in2 value to be parRef Values
void doStuff(int parValue, int& parRef)
{
    parValue = 100;
    cout << "parValue = " << parValue << endl;
    parRef = 222;
    cout << "parRef = " << parRef << endl;
}

int main()
{
    int n1 = 1, n2 =2;
    //parse doStuff two intergers. pass n1 by Value and n2 by reference
    doStuff(n1, n2);

    //outputs n1 and n2
    //n2 value was changed in the doStuff function but n1 was not
    cout << "n1 = " << n1 << ". n2 = " << n2 << endl;

    return 0;
}