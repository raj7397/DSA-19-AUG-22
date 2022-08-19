#include <iostream>
#include <memory>

using namespace std;
class myClass{
    public:
    myClass()
    {
        cout<<"constructor:"<<endl;
    }
    void print()
    {
        cout<<"myClass print()"<<endl;
    }
    ~myClass()
    {
        cout<<"myClass destructor: "<<endl;
    }
};
int main(int argc, char ** argv)
{
    shared_ptr<myClass>p1(new myClass());
    shared_ptr<myClass>p2 = p1;
    shared_ptr<myClass>p3(p2);
    cout<<"p1 add: "<<p1.get()<<endl;
    cout<<"p2 add: "<<p2.get()<<endl;
    cout<<"p3 add: "<<p3.get()<<endl;
    cout<<"rc: "<<p1.use_count()<<endl;
    p1.reset();
    cout<<"after p1 reset"<<endl;
    cout<<"p1 add: "<<p1.get()<<endl;
    cout<<"p2 add: "<<p2.get()<<endl;
    cout<<"p3 add: "<<p3.get()<<endl;
    cout<<"rc: "<<p2.use_count()<<endl;
    p2.reset();
    cout<<"after p2 reset"<<endl;
    cout<<"p1 add: "<<p1.get()<<endl;
    cout<<"p2 add: "<<p2.get()<<endl;
    cout<<"p3 add: "<<p3.get()<<endl;
    cout<<"rc: "<<p3.use_count()<<endl;
   p3.reset();
   cout<<"after p3 reset"<<endl;
    cout<<"p1 add: "<<p1.get()<<endl;
    cout<<"p2 add: "<<p2.get()<<endl;
    cout<<"p3 add: "<<p3.get()<<endl;
    cout<<"rc: "<<p1.use_count()<<endl;
    cout<<"Before main()"<<endl;
}