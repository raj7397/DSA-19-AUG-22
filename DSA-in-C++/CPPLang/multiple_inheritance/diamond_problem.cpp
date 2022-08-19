#include <iostream>
#include <string>

using namespace std;
class Person{
    protected:
        int i,j;
    public:
        Person(int a,int b):i(a),j(b)
        {
         //   cout<<"Base1()"<<endl;
            cout<<"Person() i: "<<i<<" j: "<<j<<endl;
        }
        ~Person()
        {
            cout<<"~Person()"<<endl;
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
class Faculty: public Person{
    protected:
        int k,l;
    public:
        Faculty(int a,int b):Person(a,b)
        {
            //cout<<"Base2()"<<endl;
            cout<<"Faculty() k: "<<k<<" l: "<<l<<endl;
        }
        ~Faculty()
        {
            cout<<"~Faculty()"<<endl;
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
class Student:  public Person{
    int x;
    public:
    Student(int a,int b):Person(a,b)
    {
        cout<<"Student()"<<endl;
    }
    ~Student()
    {
        cout<<"~Student()"<<endl;
    }
};
class TA: public Student,public Faculty{
    protected:
        int m,n;
    public:
        TA(int a, int b,int c,int d):Faculty(c,d),Student(a,b)
        {
            
            cout<<"TA() m: "<<m<<" n: "<<n<<endl;
        }
        ~TA()
        {
            cout<<"~TA()"<<endl;
        }


};

int main()
{
    TA ta(10,20,30,40);
  //  Base3 b(10,20,30,40,50,60);
   // b.fun(5);
   // b.g(5);
  /* Base4 b(10,20);
    b.fun(3);

    b.Base1::fun(5);
    b.Base1::g();
    //b.Base2::fun(10);
    //b.Base2::g(2);*/
}