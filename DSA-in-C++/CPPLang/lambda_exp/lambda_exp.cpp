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
int main()
{

    int sum = 3;
    int mult = 3;
    auto multOf = [mySum = sum](int x){if(x % mySum == 0){
        mySum = 3303;
        return to_string(x)+" multiple of 3";
    }
    else{
        mySum = 2191;
        return to_string(x)+" not multiple of 3";
    }
    };
    cout<<"res: "<<multOf(9)<<endl;
    cout<<"sum: "<<sum<<endl;
    //cout<<"isOdd test: "<<isOdd(1010)<<endl;
    //myClass mc(5);
  
}