#include <iostream>
#include <string>

using namespace std;
namespace myNameSpace{
    int myData;
    void myFun(int data)
    {
        cout<<"Inside mySpace: "<<endl;
        cout<<"data: "<<data<<endl;
    }
    class myClass{
        int x;
        int y;
        public:
            myClass(int x,int y)
            {
                this->x = x;
                this->y = y;
            }
            void display()
            {
                cout<<"x: "<<(this->x)<<" y: "<<(this->y)<<endl;
            }
    };
}
using namespace myNameSpace;
int main()
{
    myNameSpace::myClass mc(2,3);
    mc.display();
    myNameSpace::myData = 100;
    myNameSpace::myFun(myNameSpace::myData); 
    myClass mc2(33,44);
    myData = 20;
    myFun(myData);  
}