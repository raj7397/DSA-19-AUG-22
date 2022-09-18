#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int countBst(int n);
int main()
{
    int n;
    cin>>n;
    int ans = countBst(n);
    cout<<" ans: "<<ans;
}

int countBst(int n)
{
    vector<long>dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    int MOD = 1000000007;
    for(int i =2; i <=n ;i++)
    {
        for(int left = 0; left <= i-1;left++)
        {
            int right = i - left -1;
            long val = (dp[left] * dp[right]) %MOD;
            dp[i] = (dp[i] + val)%MOD;
        }
    }
    return (int)dp[n];
}