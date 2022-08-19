#include <iostream>
#include <string>

using namespace std;

class myClass{
    public:
      myClass()
      {
          cout<<"myClass()"<<endl;
      }
      int  operator()(int a)
      {
          return a;
      }
};
template<typename T>  void testIt(T fun)
{
    cout<<"ans: "<<fun(10)<<endl;
}
int main()
{
    auto mul = [](int x){return x*101;};
    testIt([](int x){return x*11;});

    //myClass mc(5);
    cout<<"rs2: "<<myClass()(900)<<endl;
    myClass mc1 = myClass();
    cout<<"res: "<<mc1(5)<<endl;
}