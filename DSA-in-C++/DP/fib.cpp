#include <iostream>
#include <vector>
using namespace std;

int fibr(int n);
int fibm(int n,vector<int>&);
int fibt(int n);
int main(int argc, char ** argv)
{
    int n;
    cin>>n;
   // int ans1 = fibr(n);
    //cout<<"ans1: "<<ans1<<endl;
    vector<int>dp(n + 1);
    //int ans2 = fibm(n, dp);
    //cout<<ans2<<endl;
    int ans3 = fibt(n);
    cout<<"ans3: "<<ans3<<endl;

}
int fibt(int n)
{
    vector<int>dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int fibr(int n)
{
    if(n == 0 || n == 1)
        return n;

    int fib1 = fibr(n - 1);
    int fib2 = fibr(n - 2);
    int fib = fib1 + fib2;
    return fib;
}
int fibm(int n,vector<int>&dp)
{
    if(n == 0 || n ==1)
    {
        dp[n] = n;
        return n;
    }

    if(dp[n] != 0)
        return dp[n];
    int fib1 = fibm(n-1,dp);
    int fib2 = fibm(n-2,dp);
    int fib = fib1 + fib2;
    dp[n] = fib;
    return fib;
}