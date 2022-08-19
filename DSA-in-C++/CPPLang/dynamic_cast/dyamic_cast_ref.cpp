#include <iostream>
#include <string>
#include <memory>
using namespace std;


class A{
    public:
    virtual ~ A()
    {
        cout<<"A destructor"<<endl;
    }
};
class B: public A{
    public:
     ~B()
     {
         cout<<"~B()"<<endl;
     }
};
class C{
    public:
     virtual ~C()
     {
         cout<<"~C()"<<endl;
     }
};

int main(int argc, char ** argv)
{
    A a;
    B b;
    C c;
    try{
        B &rB1 = b;
        A &rA2 = dynamic_cast<A&>(rB1);
        cout<<"valid upcast"<<endl;
        A &rA3 = b;
        B &rB4 = dynamic_cast<B&>(rA3);
        cout<<"valid upcast"<<endl;
        try{
            A &rA4 = a;
            B &rB5 = dynamic_cast<B&>(rA4);
        }
        catch(bad_cast b)
        {
            cout<<"downcast: "<<b.what()<<endl;
        }
        try{
            A &rA6 = (A&)c;
            C &rC7 = dynamic_cast<C&>(rA6);
        }
        catch(bad_cast e)
        {
            cout<<"unrelated: "<<e.what()<<endl;
        }
    }
    catch(bad_cast e)
    {
        cout<<"Bad cast: "<<e.what()<<endl;
    }
    cout<<"End of pgm: "<<endl;
}