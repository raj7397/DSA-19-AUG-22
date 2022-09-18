#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int noOfPath(int n);
int main()
{
    int n;
    cin>>n;
    int ans = noOfPath(n);
    cout<<"ans: "<<ans<<endl;
}

int noOfPath(int n)
{
    vector<int>dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n;i++)
    {
        int left = 0;
        int right = i-1;
        while(left <= i-1)
        {
            dp[i] += dp[left]*dp[right];
            left++;
            right--;
        }
    }
    return dp[n];
}