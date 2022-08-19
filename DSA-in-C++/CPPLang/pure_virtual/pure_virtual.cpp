#include <iostream>
#include <string>

using namespace std;

class Test{
    public:
    virtual void fun() = 0;

};
class TestChild: public Test{
 
    public:
         void fun()
         {
             Test::fun();
             cout<<"Child fun()"<<endl;
         }
};
class TestChild2: public TestChild{
    public:
        void fun()
        {
            Test::fun();
            cout<<"TestChild2 fun()"<<endl;
        }
};
void Test::fun()
{
    cout<<"Test fun()"<<endl;
}
int main(int argc, char **argv)
{
   // Test t;
    TestChild tc;
    TestChild2 tc2;
    Test *tc3 = new TestChild();
    tc3->fun();

}