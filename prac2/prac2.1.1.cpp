//Searches a partially filled array of nonnegative integers.
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int DECLARED_SIZE = 10;

void fillArray(int a[], int size, int& numberUsed) {
    cout << "Enter up to " << size << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index;
}

bool search(const int a[], int numberUsed, int target, int result[])
{
    int index = 0, resultIndex = 0;
 
    bool ret = true;

    while ((index < numberUsed))
    {
        if (target == a[index])
        {
            ret = false;
            result[resultIndex] = index;
            resultIndex++;
        }   
        index++;
    }
    return ret;
}
int getNumber()
{
    int ret;
    do
    {
        cin.clear();
        cin.ignore();

        cin >> ret;
    } while (!cin);

    return ret;
}


int main(){

    int arr[DECLARED_SIZE], listSize, target;
    int result[DECLARED_SIZE];

    fillArray(arr, DECLARED_SIZE, listSize);

    char ans;
    
    do
    {
      cin.ignore(100);
        
        cout << "Enter a number to search for: ";
        while ( !(cin >> target) )
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter a number to search for: ";
        }
    
        if (search(arr, listSize, target, result))
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position " ;   
                for (int i = 0; i < 10 ; i++)
                {


                    cout << (int)result[i];
                }
                cout << endl;
           

        cout << "Search again?(y/n followed by return): ";
        cin >> ans;
       
    }while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";
    return 0;
}
