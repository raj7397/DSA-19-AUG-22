#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int noOfWays(int,int);
int main()
{
    int n,k;
    cin>>n>>k;
    int ans = noOfWays(n,k);
    cout<<"ans: "<<ans<<endl;
}
int noOfWays(int n,int k)
{
    if(n == 1)
        return k;
    int ii = k * 1;
    int ij = k * (k - 1);
    int tot = ii + ij;
    for(int i = 3; i <= n;i++)
    {
        ii = ij;
        ij = tot * (k - 1);
        tot = ii + ij;
    }
    return tot;
}