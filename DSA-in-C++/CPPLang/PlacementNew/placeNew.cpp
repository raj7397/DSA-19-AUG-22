#include <iostream>
#include <string>


using namespace std;
class myClass{
    int x;
    int y;
    public:
        myClass(int x,int y)
        {
            this->x = x;
            this->y = y;
            cout<<"myClass constructor: "<<endl;
        } 
        ~myClass()
        {
            cout<<"myClass destructor: "<<endl;
        }
        void display()
        {
            cout<<"Displaying: "<<endl;
            cout<<"x: "<<x<<" y: "<<y<<endl;
        }
};
int main()
{
    unsigned char buffer[20];s
    myClass *mc = new (buffer)myClass(30,40);
    mc->display();
    mc->~myClass();
}