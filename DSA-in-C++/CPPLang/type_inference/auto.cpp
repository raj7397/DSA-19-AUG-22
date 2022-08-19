#include <iostream>
#include <string>

using namespace std;

int main()
{
    auto x = 4;
    auto d = 2.334;
    auto y = &x;
    auto &z = d;
    cout<<"x type: "<<typeid(x).name()<<endl;
    cout<<"d type: "<<typeid(d).name()<<endl;
    cout<<"y type: "<<typeid(y).name()<<endl;
    cout<<"z type: "<<typeid(z).name()<<endl;
    cout<<"x: "<<x<<endl;
}