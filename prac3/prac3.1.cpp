

#include "oneDArray.h"
//using namespace std;

int main()
{
    oneDArray numbers;
    oneDArray results;

    numbers.fill();
    results.search(numbers);
    results.print();

    return 0;
}