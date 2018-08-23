//  #include <iostream>

//  using namespace std;

// class oneDArray
//  {
//     private:
//     int array[10];
//     int length;
//     int numbersUsed;
//     public:
//     oneDArray(int);
//     void add(int a);
//     void fill();
//     bool search(int target, int results[]);
//     int getNumber();
//  };
// oneDArray::oneDArray()
// {

// }
// oneDArray::oneDArray(int s)
// {
//     length = s;
//     array = new int[10];
//     numbersUsed = 0;
//     for (int i = 0; i < length ; i++)
//     {
//         array[i] = 0;
//     }
// }
// void oneDArray::fill()
// {
//     cout << "Enter up to " << size << " nonnegative whole numbers.\n"
//          << "Mark the end of the list with a negative number.\n";
//     int next;
//     next = getNumber();
//     while ((next >= 0) && (numberUsed < size))
//     {
//         array[numberUsed] = next;
//         numberUsed++;
//         next = getNumber();
//     }

// }
// void oneDArray::add(int a)
// {
//     if (numbersUsed < size)
//     {
//         array[numbersUsed] = a;
//         numbersUsed++;
//     }
//     else
//     {
//         cout << "! Array is full no entry added !";
//     }
// }

// bool oneDArray::search(int target, oneDArray result)
// {
//     for (int i = 0; i < numberUsed ; i++)
//     {
//         if(array[i] == target)
//         {
//            results.add(i);
//         }
//     }
// }

// int oneDArray::getNumber()
// {
//     int number;
//     do
//     {
//         cin >> number;
//         cout << "Please enter whole number: ";
//         cin.clear();
//         cin.ignore(1000, '\n');

//     }while (cin.fail());

//     return number;
// }
