#include <iostream>
#include <string>

using namespace std;
class Base1{
    protected:
        int i,j;
    public:
        Base1(int a,int b):i(a),j(b)
        {
         //   cout<<"Base1()"<<endl;
            cout<<"Base1() i: "<<i<<" j: "<<j<<endl;
        }
        ~Base1()
        {
            cout<<"~Base1()"<<endl;
        }
        void fun(int x)
        {
            cout<<"Base1 fun(x)"<<endl;
        }
        void g()
        {
            cout<<"Base1 g()"<<endl;
        }
};
class Base2{
    protected:
        int k,l;
    public:
        Base2(int a,int b):k(a),l(b)
        {
            //cout<<"Base2()"<<endl;
            cout<<"Base2() k: "<<k<<" l: "<<l<<endl;
        }
        ~Base2()
        {
            cout<<"~Base2()"<<endl;
        }
       void fun(int x)
        {
            cout<<"Base2 fun(x)"<<endl;
        }
        void g(int x)
        {
            cout<<"Base2 g(x)"<<endl;
        }

};
class Base3: public Base1,public Base2{
    protected:
        int m,n;
    public:
        Base3(int a, int b,int c,int d,int e,int f):Base2(a,b),Base1(c,d),m(e),n(f)
        {
            
            cout<<"Base3() m: "<<m<<" n: "<<n<<endl;
        }
        ~Base3()
        {
            cout<<"~Base3()"<<endl;
        }
  //      using Base1::fun;
    //    using Base2::g;

};
class Base4: public Base1{
    public:
    Base4(int a,int b):Base1(a,b)
    {
        cout<<"Base4() cosntructor: "<<endl;
    }
    void fun(int x)
    {
        cout<<"Base4 fun()"<<endl;
    }
};
int main()
{
    Base3 b(10,20,30,40,50,60);
   // b.fun(5);
    b.g(5);
    b.g();
  /* Base4 b(10,20);
    b.fun(3);

    b.Base1::fun(5);
    b.Base1::g();
    //b.Base2::fun(10);
    //b.Base2::g(2);*/
}