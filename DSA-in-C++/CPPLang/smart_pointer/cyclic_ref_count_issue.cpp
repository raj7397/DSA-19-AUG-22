#include <iostream>
#include <string>
#include <memory>
using namespace std;

class myClass{
    public:
        int a,b;
        myClass(int a,int b)
        {
            this->a = a;
            this->b = b;
            cout<<"myClass constructor: "<<endl;
        }
        ~myClass()
        {
            cout<<"myClass destructor: "<<endl;
        }
        void print()
        {
            cout<<"a: "<<this-a<<" b: "<<this->b<<endl;
        }
        weak_ptr<myClass>adj;
        void setAdjcenet(shared_ptr<myClass> ptr)
        {
            adj = ptr;
            cout<<"after copy : "<<endl;
          //  cout<<"adj addr: "<<adj.get()<<endl;
            //cout<<"ptr add: "<<ptr.get()<<endl;
            //adj->print();
        }
};
int main()
{
    shared_ptr<myClass>sp1(new myClass(100,200));
    shared_ptr<myClass>sp2(new myClass(300,400));
    weak_ptr<myClass>wp1 = sp1;
    wp1.lock()->print();
    cout<<"sp1 addre: "<<sp1.get()<<endl;
    cout<<"sp2 addr: "<<sp2.get()<<endl;
    sp1->print();
    sp2->print();
    sp1->setAdjcenet(sp2);
    sp2->setAdjcenet(sp1);
    cout<<"rc: "<<sp1.use_count()<<endl;
    cout<<"rc sp2: "<<sp2.use_count()<<endl;
}