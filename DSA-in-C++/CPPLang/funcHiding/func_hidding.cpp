#include <iostream>
#include <string>

using namespace std;
class Base{
    public:
    void  fun()
    {
        cout<<"Base fun()"<<endl;
    }
};
class Child:public Base{
    public:
        using Base::fun;
        void fun(int x)
        {
            cout<<"child fun"<<endl;
        }
};
int main()
{
    /*Base b;
    Child ch1;
    Base *bp = &b;
    bp->fun();
    bp =&ch1;
    bp->fun();*/
     Child ch;
   // ch.fun(5);
    ch.fun();
}