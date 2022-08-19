#include <iostream>
#include <string>

using namespace std;
class ATest{
    public:
        ATest()
        {
            cout<<"ATest()"<<endl;
        }
};
class BTest{
    public:
        BTest()
        {
            cout<<"BTest()"<<endl;
        }
};

int main()
{
    ATest aTest;
    BTest bTest;

    BTest * bt = reinterpret_cast<BTest *>(&aTest);
 //   int a; 
   // int *ptr = &a;
    //int d= (int)ptr;
}