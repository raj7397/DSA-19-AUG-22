#include <iostream>
#include <string>

enum class Color{
    Red,
    Green,
    Blue
};
enum class People{
    good,
    bad
};
enum class Color2{
    Green,
    Red,
    Blue
};
using namespace std;

int main()
{
    int Red = 10;
   // Color c2 = 100;
    Color cl = Color::Blue;
    if(cl == Color::Red)
    {
        cout<<"Red color"<<endl;
    }
    else{
        cout<<"Not red"<<endl;
    }
    People p;
    cout<<"p : "<<sizeof(p)<<endl;
    cout<<"size: "<<sizeof(cl)<<endl;
    //cout<<cl<<endl;
}