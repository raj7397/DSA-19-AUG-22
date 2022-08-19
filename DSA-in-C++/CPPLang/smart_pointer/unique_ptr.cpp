#include <iostream>
#include <memory>

using namespace std;
class myClass{
    public:
    void print()
    {
        cout<<"myClass print()"<<endl;
    }
};
int main()
{
    unique_ptr<myClass>p1(new myClass());
    p1->print();
    cout<<"add: "<<p1.get()<<endl;
    unique_ptr<myClass> p2 = move(p1);
    cout<<"p1 address: "<<p1.get()<<endl;
    cout<<"p2 address: "<<p2.get()<<endl;

}