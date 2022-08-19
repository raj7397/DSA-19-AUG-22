#include <iostream>
#include <string>

using namespace std;
class B{
//    int c,d;
    public:
    B()
    {
        c = 5;
        d = 30;
        cout<<"B constructor"<<endl;
    }
    operator int()
    {
        return c;
    }
    int c,d;  
};
class A{
    int a,b;
    public:
    A(int i){
        cout<<"A(i) construcotr"<<endl;
    }
    A(B &bObj)
    {
        cout<<"A copy constructor"<<endl;
        cout<<"A address: "<<(this)<<" b Address: "<<(&bObj)<<endl;
        cout<<"copy constructor ends"<<endl;
    }
    A & operator=( B &bObj)
    {
        cout<<" copy assingment: "<<endl;
        cout<<" A addres: "<<(this)<<" b addrs: "<<(&bObj)<<endl;
     //   this->a= bObj.c;
       // this->b = bObj.d;
        cout<<"copy assingmet end"<<endl;
        return *this;
    } 
    A() = default;
};
int main()
{
    B bObj;
    int k = bObj;
    cout<<"k: "<<k<<endl;
/*    B bObj;
    A aObj;
    cout<<"B Address: "<<(&bObj)<<" a Address: "<<(&aObj)<<endl;
    aObj = bObj;
    int i = 20;
    aObj = i;*/
}