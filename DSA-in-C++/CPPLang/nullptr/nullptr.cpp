#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 20;
    decltype(a) b = 33;
    cout<<"b: "<<b<<endl;
char* p = nullptr;     // p has the null pointer value 
char* p1 = 0;          // p has the null pointer value 
//int a = nullptr;       // error 
int a2 = 0;            // a2 is zero of integral type
if( p == 0 )
{
    cout<<"true"<<endl;
}        // evaluates to true 
if( p == nullptr );    // evaluates to true 
{
    cout<<"true"<<endl;
}
if( p )
{
    cout<<"true"<<endl;
}
else{
    cout<<"false"<<endl;
}           // evaluates to false
//if( a2 == 0 );         // evaluates to true 
//if( a2 == nullptr );   // error, no conversion
if( nullptr )
{
    cout<<"1"<<endl;
} 
else{
    cout<<"1"<<endl;
}    // OK, conversion to the bool type 
if( nullptr == 0 )    // OK, comparison with 0
{
    cout<<"true"<<endl;
}
else{
    cout<<"false"<<endl;
}
//if(nullptr==1) //compilation error
/*nullptr = 0;           // error, nullptr is not an lvalue 
nullptr + 2;           // error*/

}