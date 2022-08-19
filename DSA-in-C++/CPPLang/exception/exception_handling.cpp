#include <iostream>
#include <string>

using namespace std;
void fun_h(int a,int b)
{
    try{
        cout<<" a: "<<a<<" b: "<<b<<endl;
        int d = a/b;
    //if(b == 0)

       // throw 1;
    }
    catch(int)
    {
        cout<<"Caught in fun_h"<<endl;
    }
    catch(...)
    {
        cout<<"divide by 0"<<endl;
    }

    
}
void fun(int a,int b)
{
    try{
        fun_h(a,b);
        cout<<" after fun_h"<<endl;
    }
    catch(int )
    {
        cout<<"Caught in fun()"<<endl;
    }
    catch(...)
    {
        cout<<"divide by 0"<<endl;
    }

      //  fun_h(a,b);
}
int main()
{
    int a;
    int b;
    cin>>a>>b;
    int d;
    try{
        fun(a,b);
    }
    catch(int x)
    {
        cout<<" Caught in main() Divison by Zero error: "<<endl;
    }
    catch(...)
    {
        cout<<"divide by 0"<<endl;
    }
    cout<<"d: "<<d<<endl;
    for(int i = 0; i < 10;i++)
    {
        cout<<"Hello divide"<<endl;
    }
}