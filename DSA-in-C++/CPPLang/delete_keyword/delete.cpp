#include <iostream>
#include <string>

using namespace std;

class Test{
    int a;
    public:
    Test(int a)
    {
        cout<<"Test()"<<endl;
    }
   // Test() = delete;
    //Test(int a)
    void show()
    {
        cout<<"This is show(): "<<endl;
    }
    ~Test(){

    }
    void fun() = delete;

    void fun(int a)
    {
        cout<<"fun(int)"<<endl;
    }
};
int main(int argc, char ** argv)
{
    Test(5);
    Test t(5);
    cout<<"sizeof: "<<sizeof(t)<<endl;
    //t.fun();
    t.fun(3);
}