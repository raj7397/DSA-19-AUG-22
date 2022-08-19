#include <iostream>
#include <string>

using namespace std;
int fun1()
{
    return 1;
}
char fun2()
{
    return 'a';
}
auto fun3(int a, int b)->decltype(a)
{
    return a+b;
}
template<typename T1, typename T2> auto findMin(T1 a, T2 b)->decltype(a < b?a:b)
{
    return a< b?a:b;
}
int main()
{
    cout<<"findMin: "<<findMin(3.44,34)<<endl;
    int x1 = fun3(10,30);
    cout<<"x1: "<<x1<<endl;
    int x =20;
    decltype(x) j = x +30;
    cout<<"j: "<<j<<endl;
    decltype(fun1()) a;
    decltype(fun2()) b;
    cout<<"type: "<<typeid(a).name()<<endl;
    cout<<"type: "<<typeid(b).name()<<endl;
}