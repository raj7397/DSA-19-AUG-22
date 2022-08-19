#include <iostream>
#include <string>

using namespace std;
class myClass{
    public:
       int a,b;
       myClass(int a, int b)
       {
           this->a = a;
           this->b = b;
           cout<<"constructor: "<<endl;
       }
       void doSomeWork()
       {
           cout<<"Doing some work"<<endl;
       }
       ~myClass()
       {
           cout<<"destructor: "<<endl;
       }
       void show()
       {
           cout<<" a: "<<this->a<<" b: "<<this->b<<endl;
       }
};
template<typename T>
class auto_ptr{
    T * ptr;
    public:
     auto_ptr( T *ptr)
     {
         cout<<"auto ptr construcotr: "<<endl;
         this->ptr = ptr;
     }
     T& operator * ()
     {
         return *ptr;
     }
     T * operator ->()
     {
         return ptr;
     }
     ~auto_ptr()
     {
         cout<<"auto ptr destructor: "<<endl;
         delete ptr;
     }
};
int main(int argc, char ** argv)
{
    auto_ptr<myClass>p(new myClass(30,40));
    p->doSomeWork();
    p->show();
    cout<<"after ->"<<endl;
    (*p).show();
    (*p).doSomeWork();
/*/
    myClass *ptr;
    try
    {
        ptr = new myClass(20,30);
        ptr->doSomeWork();
        ptr->show();
        throw 1;
       // throw;
        delete ptr;
    }
    catch(...)
    {
        cout<<"catch"<<endl;
        delete ptr;
    }*/
    cout<<"leaving main()"<<endl;
  
}