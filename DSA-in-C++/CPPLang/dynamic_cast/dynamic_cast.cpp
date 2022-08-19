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
      ~C()
     {
         cout<<"~C()"<<endl;
     }
};

int main(int argc, char ** argv)
{
    A a;
    B b;
    C c;
    A *pA;
    B *pB;
    C *pC;

    void *pV;
    pB = &b;
    pA  = dynamic_cast<A*>(pB);
    cout<<"pB: "<<pB<<" pA: "<<pA<<endl;
    pA = &b;
    pB = dynamic_cast<B*>(pA);
    cout<<"pB: "<<pB<<" pA: "<<pA<<endl;
    pA = (A*)&c;
  //  pC = dynamic_cast<C*>(pA);
    //cout<<"&c: "<<&c<<" PA: "<<pA<<endl;
  //  cout<<"HI pC: "<<pC<<" pA: "<<pA<<endl;
    pA = 0;
    pC = dynamic_cast<C*>(pA);
    cout<<"pC: "<<pC<<" pA: "<<pA<<endl;
    pA = &a;
    pV = dynamic_cast<void *> (pA);
    cout<<"pV: "<<pV<<" pA: "<<pA<<endl;
 //   pA = dynamic_cast<A*>(pV);
   // cout<<"pA: "<<pA<<endl;
}