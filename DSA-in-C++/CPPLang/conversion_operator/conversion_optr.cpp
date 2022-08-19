#include <iostream>
#include <string>

using namespace std;
class B{
    public:
    int a,b;
    B(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    explicit B(int a)
    {
        cout<<"B(int)"<<endl;
    }
    void showB()
    {
        cout<<"B a: "<<this->a<<" b: "<<this->b<<endl;
    }
};
class A{
    public:
      int c, d;
      A(int c, int d)
      {
          this->c = c;
          this->d = d;
      }
      operator int()
      {
          cout<<" conversion opertor to int"<<endl;
          return this->c;
      }
      void showA()
      {
          cout<<" A: c: "<<this->c<<" d: "<<this->d<<endl;
      }
    operator B()
    {
        cout<<"Conversion operator: "<<endl;
        B bObj(1,2);
        bObj.a = this->c;
        bObj.b = this->d;
        return bObj;
        //return B(100,200);
    }
};
int main(int argc, char ** argv)
{
    A aObj(5,20);
    B bObj(33,55);
    int x = 30;
    bObj = x;
    cout<<" before call: "<<endl;
    aObj.showA();
    bObj.showB();
    bObj = aObj;
   cout<<" After call: "<<endl;
    aObj.showA();
    bObj.showB();
    int k = aObj;
    cout<<"K:  "<<k<<endl;
}