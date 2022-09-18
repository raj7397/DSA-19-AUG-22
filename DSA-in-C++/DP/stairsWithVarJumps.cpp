#include <iostream>
#include <vector>
#include <climits>

using namespace std;
//int stairsWithMoves(vector<int>&arr,int idx,int n);
int stairsWithVarJumps(vector<int>&,int);
int stairsWithVarJumpsT(vector<int>&arr);
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
    int ans = stairsWithVarJumps(arr,0);
    int ans2 = stairsWithVarJumpsT(arr);
    cout<<"ans2: "<<ans2<<endl;
    cout<<ans<<endl;
}
int stairsWithVarJumpsT(vector<int>&arr)
{
    vector<int>dp(arr.size() + 1);
    dp[dp.size() -1] = 1;
    for(int idx = dp.size() - 2; idx >= 0; idx--)
    {
        for(int jump = 1; jump <= arr[idx]; jump++)
        {
            if(jump + idx <= dp.size())
                dp[idx] += dp[idx + jump];
        }
    }
    return dp[0];
}
int stairsWithVarJumps(vector<int>&arr,int idx)
{
    if(idx == arr.size())
        return 1;

    int ans = 0;
    for(int jump = 1; jump <= arr[idx];jump++)
    {
        if(jump + idx <= arr.size())
        {
            ans += stairsWithVarJumps(arr,jump + idx);
        }
    }
    return ans;
}