#include <iostream>
#include <string>
#include <memory>

using namespace std;
class myClass{
    int *ptr;
    public:
    myClass()
    {
        ptr = new int(10);
        cout<<"myClass consrutor:"<<endl;
    }
    ~myClass()
    {
        cout<<"myClass destr"<<endl;
    }
    void release()
    {
        cout<<"Releasing resources"<<endl;
        delete ptr;
    }
    void print()
    {
        cout<<"val: "<<*ptr<<endl;
    }
};
void customDeleter(myClass *mp)
{
    cout<<"custom deletor"<<endl;
    

    if(mp != nullptr)
        mp->release();
}
class Del{
    public:

        void operator()(myClass *mp)
        {
            cout<<"functor custom deletor"<<endl;
            if(mp != nullptr)
                mp->release();
        }
};
int main(int argc, char ** argv)
{
    unique_ptr<myClass,std::function<void(myClass *) > >up1(new myClass(),[](myClass *ptr){
        cout<<"unique ptr custom deletor"<<endl;
        if(ptr != nullptr)
            ptr->release();
    });
    up1->print();
   /* int a = 10;
    int &b = a;
    cout<<"&a: "<<(&a)<<" &b: "<<(&b)<<endl;
    b = 30;
    cout<<"a: "<<a<<" b: "<<b<<endl;
    cout<<"&a: "<<(&a)<<" &b: "<<(&b)<<endl;

   // shared_ptr<myClass>sp1(new myClass(),&customDeleter);
   shared_ptr<myClass>sp1(new myClass(),[](myClass *mp){
        cout<<"custom deletor using lambda"<<endl;
        if(mp != NULL)
            mp->release();
    });
    shared_ptr<myClass>sp1(new myClass,Del());
    sp1->print();

    myClass *mp = new myClass();
    mp->print();
    mp->release();
    delete mp;*/

}