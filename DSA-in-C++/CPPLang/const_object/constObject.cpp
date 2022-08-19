#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Complex{
    int m1;
    public:
        int m2;
    Complex(int m1,int m2){
        this->m1 = m1;
        this->m2 = m2;
    }
    void print() const 
    {
        cout<<"m1: "<<m1<<" m2: "<<m2<<endl;
    }
    int getM1() const
    {
        return m1;
    }
    void setMember(int a,int b) const
    {
      //  continue;
     //   this->m1 = a;
       // this->m2 = b;
    }
   
};
int main()
{
    const Complex c1(10,39);
    c1.print();
    //c1.m2 = 300;
    c1.print();
    c1.setMember(300,399);
    c1.print();
    c1.getM1();

}