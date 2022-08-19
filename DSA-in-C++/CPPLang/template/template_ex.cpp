#include <iostream>
#include <string>

using namespace std;
template<typename T> class myClass{
    private: 
        T x;
     public:
     myClass(T a)
     {
         this->x = a;
     }
     T getVal()
     {
         cout<<"In getVal"<<endl;
         return x;
     }
    
};
template<typename T> T myMax(T a, T b)
{
    if( a > b)
        return a;
    else
        return b;
}
template<typename T,int size> T maxArray(T x[size])
{
    T t = x[0];
    for(int i = 1; i < size;i++)
    {
        if(x[i] > t)
            t = x[i];
    }
    return t;
}
template<> char myMax<char>(char a, char b)
{
    cout<<"template spaecialization:"<<endl;
    return a;
}
template < class T> T myMin(T a, T b)
{
    if(a < b)
        return a;
    else
        return b;
}
int main(int argc, char ** argv)
{
    myClass<double> md(49.33);
    cout<<"res5: "<<md.getVal()<<endl;
    myClass<int>mc(30);
    cout<<"mc.getVal: "<<mc.getVal()<<endl;
    int arr[] = {1,2,3,4,5,6,7};
    cout<<"res4: "<<maxArray<int,7>(arr)<<endl;
    cout<<"res3: "<<myMax<char>('a','b')<<endl;
    int a = 20;
    int b = 30;
    int res = myMax<int>(a,b);
    int res2 = myMin<int>(a,b);
    double c = 30.44;
    double d = 43.33;
    cout<<"double: "<<myMin<double>(c,d)<<endl;
    cout<<"res: "<<res<<endl;   
}