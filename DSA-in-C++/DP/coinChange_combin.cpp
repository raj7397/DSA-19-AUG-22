#include <iostream>
#include <vector>

using namespace std;

int coinChangeRec(vector<int>&arr,int tar,int n);
int coinChangeMemo(vector<int>&arr,int tar,int n,vector<vector<int>>&dp);
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n;i++)
    {
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    int ans = coinChangeRec(arr,tar,n);
    cout<<"ans: "<<ans<<endl;
    vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
    int ans2 = coinChangeMemo(arr,tar,n,dp);
    cout<<" ans2: "<<ans2<<endl;
}
int coinChangeMemo(vector<int>&arr,int tar,int n,vector<vector<int>>&dp)
{
    if(tar == 0)
    {
        dp[n][tar] = 1;
        return dp[n][tar];
    }
       // return 1;
    if(n <= 0)
    {
        dp[n][tar] = 0;
        return dp[n][tar];
    }
    if(dp[n][tar] != -1)
        return dp[n][tar];
        //return 0;

    int ans = 0;
    if(arr[n-1] <= tar)
    {
        ans += coinChangeMemo(arr,tar - arr[n-1],n,dp);
        
    }
    ans += coinChangeMemo(arr,tar,n-1,dp);
    dp[n][tar] = ans;
    return dp[n][tar];
   // return ans;
}
int coinChangeRec(vector<int>&arr,int tar,int n)
{
    if(tar == 0)
        return 1;
    if(n <= 0)
        return 0;

    int ans = 0;
    if(arr[n-1] <= tar)
    {
        ans += coinChangeRec(arr,tar - arr[n-1],n);
    }
    ans += coinChangeRec(arr,tar,n-1);
    return ans;
}