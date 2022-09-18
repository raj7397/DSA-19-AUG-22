#include <iostream>
#include <vector>

using namespace std;
int climbStairsR(int n);
int climbStairsM(int,vector<int>&);
int climbStairsT(int n);
int main(int argc, char ** argv)
{

    int n;
    cin>>n;
    //int ans1 = climbStairsR(n);
    //cout<<"ans1: "<<ans1<<endl;
    vector<int>dp(n+1,-1);
    int ans2 = climbStairsM(n,dp);
    cout<<"ans2: "<<ans2<<endl;
    int ans3 = climbStairsT(n);
    cout<<"ans3: "<<ans3<<endl;
}
int climbStairsR(int n)
{
    if(n == 0 || n==1)
        return 1;
    if(n < 0)
        return 0;
    int ans = 0;
    ans+=climbStairsR(n-1);
    ans+=climbStairsR(n-2);
    ans+=climbStairsR(n-3);
    return ans;
}
int climbStairsM(int n,vector<int>&dp)
{
if(n == 0 || n==1)
    {
        dp[n] = 1;
        return dp[n];
    }
        //return ;
    if(n < 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    int ans = 0;
    ans+=climbStairsM(n-1,dp);
    ans+=climbStairsM(n-2,dp);
    ans+=climbStairsM(n-3,dp);
    dp[n] = ans;
    return dp[n];
}
int climbStairsT(int n)
{
    vector<int>dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <=n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}