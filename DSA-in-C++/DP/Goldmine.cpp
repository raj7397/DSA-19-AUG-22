#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int goldMine(vector<vector<int>>&arr,int sr,int sc ,int dr,int dc)
{


    if(sc == dc)
        return arr[sr][sc];

    int ans = INT_MIN;
    if(sr -1 >= 0 && sc + 1 <= dc)
    {
        int ra = goldMine(arr,sr-1,sc+1,dr,dc);
        if(ra != INT_MIN)
            ans = max(ans,ra + arr[sr][sc]);
    }
    if(sc + 1 <= dc)
    {
        int ra = goldMine(arr,sr,sc+1,dr,dc);
        if(ra != INT_MIN)
            ans = max(ans,ra + arr[sr][sc]);
    }
    if(sr +1 <= dr && sc + 1 <= dc)
    {
        int ra = goldMine(arr,sr+1,sc+1,dr,dc);
        if(ra != INT_MIN)
            ans = max(ans,ra + arr[sr][sc]);
    }
    return ans;
}
int goldMineHelper(vector<vector<int>>&arr)
{
    int ans = INT_MIN;
    for(int i =0; i < arr.size();i++)
    {
        int ra = goldMine(arr,i,0,arr.size() - 1, arr[0].size() -1);
        ans = max(ans,ra);
    }
    return ans;
}
int goldMineT(vector<vector<int>>&arr)
{
    int ans = INT_MIN;
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>>dp(n,vector<int>(m));
    for(int j = m-1; j >= 0;j--)
    {
        for(int i = 0; i < n;i++)
        {
            if(j == m-1)
            {
                dp[i][j] = arr[i][j];
            }
            else if(i == 0)
            {
                dp[i][j] = max(dp[i][j+1],dp[i+1][j+1])+arr[i][j];
            }
            else if(i == n-1)
            {
                dp[i][j] = max(dp[i-1][j+1],dp[i][j+1])+arr[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]))+arr[i][j];
            }
        }
    }

    
    for(int i = 0; i < n;i++)
    {
        ans = max(ans,dp[i][0]);
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < m;j++)
        {
            cin>>arr[i][j];
        }
    }
    //int ans = goldMineHelper(arr);
    int ans = goldMineT(arr);
    cout<<ans<<endl;
}