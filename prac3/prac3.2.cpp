#include <string>
#include <iostream>

using namespace std;


class Student
{
private:
    int id;
    string name;
    int courseNo;
    bool enrolled;
public:
    Student()
    {
    char ans;
        do
        { if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000 ,'\n');
            }
            cout << "What is the Students ID number ? : ";
            cin >> id;
        }
        while (cin.fail());

        cout << "What is the Students name? : ";
        cin >> name;
        
            do
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000 ,'\n');
            }
            cout << "What is the Students Course number : ";
            cin >> courseNo;
        }
        while (cin.fail());

        cout << "Is the Students Enrolled  ( y / n ):  ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            enrolled = true;
        }
        else
        {
            enrolled = false;
        }
    }
    void display()
    {
        cout << "Student :" << id << endl;
        cout << name << " is currently ";
        if (!enrolled)
        {
            cout << "not " ;
        }
        cout << "enrolled in Course " << courseNo << endl; 
    }


     
  
};

int main()
{
    Student stu;
    stu.display();
    return 0;
}