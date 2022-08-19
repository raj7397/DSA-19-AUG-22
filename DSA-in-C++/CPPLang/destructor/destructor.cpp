#include <iostream>
#include <string>

using namespace std;

class Test{
    int a;
    public:
        Test( int a)
        {
            this->a = a;
            cout<<"Test() "<<endl;
        }
       virtual ~Test()
        {
            cout<<"~Test()"<<endl;
        }
};
class TestChild: public Test{
    int b;
    public:
    TestChild(int x, int y):Test(x),b(y)
    {
        cout<<"TestChild()"<<endl;
    }
    ~TestChild()
    {
        cout<<"~TestChild()"<<endl;
    }

};
int main(int argc, char **argv)
{
    Test *t = new TestChild(3,4);
    delete t;
//    Test *t = new Test();
  //  delete t;

}