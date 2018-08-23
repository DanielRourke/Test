#include <iostream>

using namespace std;

class person
{
 // std::string name;
  int age;
public:
  person() : age(5) { }
  void print() const;
};
    
void person::print() const
{
  std::cout  << ":" << age << std::endl;
  /* "name" and "age" are the member variables.
     The "this" keyword is an expression whose value is the address
     of the object for which the member was invoked. Its type is 
     const person*, because the function is declared const.
 */
}