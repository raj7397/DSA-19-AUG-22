#include <iostream>
#include <string>

using namespace std;
int noOfBinStr(int);
int main()
{
    int n;
    cin>>n;
    int ans = noOfBinStr(n);
    cout<<"ans: "<<ans<<endl;
}

int noOfBinStr(int n)
{
    int zero = 1;
    int ones = 1;
    for(int i = 2;i <=n;i++)
    {
        int new_ones = zero;
        int new_zeros = zero + ones;
        ones = new_ones;
        zero = new_zeros;
    }
    return ones + zero;
}