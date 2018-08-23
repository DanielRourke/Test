
#include <iostream>

using namespace std;

//Searches a partially filled array of nonnegative integers.
class oneDArray
{
    private:
    int array[10];
    int length;
    int numbersUsed;
    int target;
    
    public:
    oneDArray()
    {
        length = 10; 
        numbersUsed = 0;
        for (int i = 0; i < length; i++)
        {
            array[i] = -1;
        }
    }
    int getNumber()
    {
        int number;
        cin >> number;
        while (cin.fail())
        {
            cout << "Please enter whole number: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> number;
        }

        return number;
    }
    int valueAt(int i)
    {
       return array[i];
    }
    void fill()
    {
        cout << "Enter up to " << length << " nonnegative whole numbers.\n"
            << "Mark the end of the list with a negative number.\n";
        int next;
        next = getNumber();
        while ((next >= 0) && (numbersUsed < length ))
        {
            array[numbersUsed] = next;
            numbersUsed++;
            next = getNumber();
        }
    }
    void search(oneDArray& numbers)
    {
        cout << "What number would you like to find ? :";
       int target = getNumber();

        for (int i = 0; i < length; i++)
        {
            if(numbers.valueAt(i) == target && target > -1)
            {                     
                array[numbersUsed] = i;
                numbersUsed++;
            }
        }
    }

    

    void print()
    {
        if (numbersUsed > 0)
        {
            cout << "target is located in index ";
            for (int i = 0; i < numbersUsed ; i++ )
            {
                cout << array[i] ;
                if (i < numbersUsed -1)
                {
                    cout << ", ";
                }
            }
        }
        else
        {
            cout << "There are no elements to print";
        }

        cout << endl;
    }

};