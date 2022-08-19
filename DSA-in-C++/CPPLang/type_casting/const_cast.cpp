#include <iostream>
#include <string>

using namespace std;
void print(char *name)
{
    cout<<"name: "<<name<<endl;
}
class myClass{
    int a,b;
    public:
    myClass(int a, int b)
    {
        this->a=a;
        this->b=b;
    }
    void setMem(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void print() const
    {
        cout<<"a: "<<this->a<<" b: "<<this->b<<endl;
    }
};
class type{
    
    public:
    void setI(int a) const
    {
        const_cast<type*>(this)->i = a;
       // this->i = a;
    }
    int i;
};
int main()
{
    const int a = 10;
    int *pa = const_cast<int*>(&a);
    *pa = 40;
    cout<<"a: "<<a<<" *pa "<<(*pa)<<endl;

    /*
    type t;
    t.setI(5);
    cout<<"(type::i): -> "<<(t.i)<<endl;
    const myClass mc(10,30);
    mc.print();
   // mc.setMem(30,40);
    const_cast<myClass&>(mc).setMem(333,444);
    mc.setMem(400,4999);
    mc.print();
    cout<<"After change: "<<endl;
    mc.print();
    const char * name ="Rajkalash Rajbhar";
    char * name2 = const_cast<char*>(name);
    print(const_cast<char*>(name));
    print(name2);*/
    
}