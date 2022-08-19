#include <iostream>
#include <string>

using namespace std;

class A
{
int i;
 
public:
A( ) =default; //compiler will generate a default constructor for us
 
A(int ii):i(ii) //user-defined constructor
{ }
 
int get() const  { return i; }
 
~A() =default; //compiler will generate a default destructor for us
};
 
int main( )
{
A a; //calls the synthesized default constructor
 
A a1(90) ; //calls the user-defined constructor
 
cout<< a1.get() << endl ;
 
//cin.get() ;
return 0 ;
}
