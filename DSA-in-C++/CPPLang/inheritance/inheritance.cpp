#include <iostream>
#include <string>

using namespace std;
class BTest{
    private:
        int x;
        void printX()
        {
            cout<<"x: "<<x<<endl;
        }
    protected:
        int y;
        void printY()
        {
            cout<<" IN printy: "<<y<<endl;
        }
    public:
        int z;
        void printZ()
        {
            cout<<"in print z: "<<z<<endl;
        }
        BTest(int x,int y,int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        void show()
        {
            cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
        }
};
class Test{
    int data;
    public:
        Test(int data)
        {
            this->data = data;
            cout<<"Base constr 1 param"<<endl;

        }
        Test()
        {
            cout<<"Base constr 0 param"<<endl;
        }
        Test(int a,int b)
        {
            cout<<"Base constr 2 param"<<endl;
        }
       friend ostream & operator <<(ostream &out , Test &t)
       {
           out<<t.data<<endl;
           return out;
       }
};
class TestChild: public Test{
    int info;
    public:
        TestChild(int data,int info):Test(30,40)
        {
            this->info = info;
        }
};

class DTest: public BTest{
    int a;
    protected:
        int b;
    public:
        int c;
        DTest(int d,int e,int f,int g,int h,int i):BTest(d,e,f)
        {
          //  BTest::BTest(d,e,f);
            a = g;
            b = h;
            c = i;
        }
        void display()
        {
            printY();
           // show();
           // cout<<"x: "<<x<<endl;
            cout<<"y: "<<y<<endl;
            cout<<"z: "<<z<<endl;
         //   cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
        }
        //printX();
        //printY();
        //printZ();
};
class B{
    public:
    B()
    {
        cout<<"B constructor: "<<endl;
    }
    ~B()
    {
        cout<<"B Desstructor: "<<endl;
    }
};
class C{
    public:
    C()
    {
        cout<<"C constructor: "<<endl;
    }
    ~C()
    {
        cout<<"C Desstructor: "<<endl;
    }

};
class D: public B{
    private:
        C cObj;
    public:
    D()
    {
        cout<<"D constructor: "<<endl;
    }
    ~D()
    {
        cout<<"D Desstructor: "<<endl;
    }

};
class Test2{
    protected:
        void show()
        {
            cout<<"Test2 protected: "<<endl;
        }
    public:
        void showPub()
        {
            cout<<"Test2 public showPub"<<endl;
        }
};
class Test3:private Test2{
    public:
    void showTest3()
    {
        show();
        showPub();
    }

};
int main()
{
    Test3 t3;
    t3.showTest3();
  //  D d;
   /* Test t(10);
    cout<<t;
    TestChild tc(100,300);
    cout<<tc;
    DTest dt(10,20,30,40,50,60);
    dt.z = 300;
    dt.show();
    dt.display();
   // dt.printY();
    BTest b(300,400,500);
    b.printY();*/
}