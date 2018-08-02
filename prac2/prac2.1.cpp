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

string search(const int a[], int numberUsed, int target)
{
    int index = 0; 
    string ret = "";
    while ((index < numberUsed))
    {
        if (target == a[index])
        {
            ret += to_string(index);
            ret += ", ";
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

    fillArray(arr, DECLARED_SIZE, listSize);

    char ans;
    string result;
    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;
        if (cin.fail())
        {
           cout << "That wasnt a number. Now Its Broken!" << endl;
            cin.clear();
            string gnor = to_string(target);
            cin.ignore(gnor.length());
            cout << endl;
        }
        else
            result = search(arr, listSize, target);       
        
        if (result == "")
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position " 
                << result << endl
                << "(Remember: The first position is 0.)\n";

        cout << "Search again?(y/n followed by return): ";
        cin >> ans;
        cin.ignore(0);
    }while ((ans == 'y') || (ans == 'Y'));

    cout << "End of program.\n";
    return 0;
}
