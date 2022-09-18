#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int noOfWaysRec(int n);
int noOfWaysMemo(int n, vector<int>&dp);
int noOfWaysT(int n);
int main()
{
    int n;
    cin>>n;
    int ans = noOfWaysRec(n);
    cout<<"ans: "<<ans<<endl;
    vector<int>dp(n+1, -1);
    int ans2 = noOfWaysMemo(n,dp);
    cout<<" ans2: "<<ans2<<endl;
    int ans3 = noOfWaysT(n);
    cout<<" ans3: "<<ans3<<endl;

}
int noOfWaysT(int n)
{
    vector<int>dp(n+1);
    for(int i = 1; i <= n;i++)
    {
        if(i == 1)
        {
            dp[i] = i;
        }
        else if(i == 2)
        {
            dp[i] = i;
        }
        else{
            dp[i] = dp[i-1] + dp[i-2];
        }
    }
    return dp[n];
}
int noOfWaysMemo(int n,vector<int>&dp)
{
    if(n <=2)
    {
        dp[n] = n;
        return dp[n];
    }

    if(dp[n] != -1)
        return dp[n];

    int ans1 = noOfWaysMemo(n-1, dp);
    int ans2 = noOfWaysMemo(n-2,dp);
    dp[n] = ans1+ ans2;
    return dp[n];
}
int noOfWaysRec(int n)
{
    if(n <= 2)
    {
        return n;
    }

    int ans1 = noOfWaysRec(n -1);
    int ans2 = noOfWaysRec(n - 2);
    return ans1 + ans2;
}