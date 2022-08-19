#include <iostream>
#include <string>
#include <memory>
using namespace std;
class A{
    public:
    virtual ~ A()
    {
        //cout<<"A destructor"<<endl;
    }
};
class B: public A{
    public:
     ~B()
     {
       //  cout<<"~B()"<<endl;
     }
};

int main(int argc, char ** argv)
{
     A a;
     B b;
    A *p ;
    p = &a;
    cout<<typeid(a).name()<<" &a: "<<typeid(&a).name()<<endl;
    cout<<" b: "<<typeid(b).name()<<" &b: "<<typeid(&b).name()<<endl;
    p = &a;
    cout<<" p: "<<typeid(p).name()<<" *p: "<<typeid(*p).name()<<endl;
    p = &b;
    cout<<" p "<<typeid(p).name()<<" *p: "<<typeid(*p).name()<<endl;
     A &r1 = a;
     A &r2 = b;
     cout<<" r1: "<<typeid(r1).name()<<" r2: "<<typeid(r2).name()<<endl;
}