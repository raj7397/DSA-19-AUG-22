#include <iostream>
#include <vector>
#include <climits>

using namespace std;
//int stairsWithMoves(vector<int>&arr,int idx,int n);
int stairsWithMovesM(vector<int>&arr,int idx,vector<int>&dp);
int stairsWithMoves(vector<int>&,int);
int stairsWithMinMovesT(vector<int>&arr);
int main(int argc, char ** argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i< n;i++)
    {
        cin>>arr[i];
        //cin>>t;
       // arr[i] = t;
    }
    //int ans = stairsWithMoves(arr,0,n);
    //cout<<"ans: "<<ans<<endl;
    int ans = stairsWithMoves(arr, 0);
    cout<<"ans: "<<ans<<endl;
    vector<int>dp(n+1,-1);
    int ans1 = stairsWithMovesM(arr,0,dp);
    cout<<"ans1: "<<ans1<<endl;
    int ans2 = stairsWithMinMovesT(arr);
    cout<<"ans2: "<<ans2<<endl;
}
int stairsWithMinMovesT(vector<int>&arr)
{
    vector<int>dp(arr.size() + 1);
    dp[dp.size() -1] = 0;
    for(int idx = dp.size() - 2; idx >= 0;idx--)
    {
        dp[idx] = INT_MAX;
        for(int jump = 1; jump <= arr[idx];jump++)
        {
            if(idx + jump <= dp.size() && dp[idx + jump] != INT_MAX)
                dp[idx] = min(1+ dp[idx + jump], dp[idx]);
        }
    }
    for(int i= 0; i < dp.size();i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    return dp[0];
}
int stairsWithMovesM(vector<int>&arr,int idx,vector<int>&dp)
{
    if(idx == arr.size())
    {
        dp[idx] = 0;
        return 0;
    }
       // return 0;


    if(dp[idx] != -1)
    {
        return dp[idx];
    }
    int ans = INT_MAX;
    for(int jump = 1; jump <= arr[idx];jump++)
    {
        if(idx + jump <= arr.size())
        {
            int recAns = stairsWithMovesM(arr,jump + idx, dp);
            if(recAns != INT_MAX)
            {
                ans = min(ans,recAns + 1);
            }
        }
    }
    dp[idx] = ans;
    return dp[idx];
    //return ans;
}
int stairsWithMoves(vector<int>&arr,int idx)
{
    if(idx == arr.size())
        return 0;


    int ans = INT_MAX;
    for(int jump = 1; jump <= arr[idx];jump++)
    {
        if(idx + jump <= arr.size())
        {
            int recAns = stairsWithMoves(arr,jump + idx);
            if(recAns != INT_MAX)
            {
                ans = min(ans,recAns + 1);
            }
        }
    }
    return ans;
}
/*
int stairsWithMoves(vector<int>&arr,int idx, int n)
{
    if(idx == n)
        return 0;

    int ans = INT_MAX;
    for(int jump = 1; jump <= arr[idx] && jump + idx <= n;jump++)
    {
        int recAns = stairsWithMoves(arr, jump + idx ,n);
        if(recAns != INT_MAX)
            ans = min(ans,recAns + 1);
    }
    return ans;
}*/