#include <iostream>
#include <vector>

using namespace std;

int coinChangePermRec(vector<int>&arr,int tar);
int coinChangePermTabu(vector<int>&arr,int tar);
//int coinChangePermMemo(vector<int>&arr,int tar,int n,vector<vector<int>>&dp);
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
    int ans = coinChangePermRec(arr,tar);
    cout<<"ans: "<<ans<<endl;
  /*  vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
    int ans2 = coinChangePermMemo(arr,tar,n,dp);
    cout<<" ans2: "<<ans2<<endl;*/
    int ans2 = coinChangePermTabu(arr,tar);
    cout<<"ans2: "<<ans2<<endl;
}

int coinChangePermTabu(vector<int>&arr,int tar)
{
    vector<int>dp(tar + 1);
    dp[0] = 1;
    for(int i = 0; i <= tar;i++)
    {
        for(int j = 0; j < arr.size();j++)
        {
            if(arr[j] <= i)
            {
                dp[i] += dp[i - arr[j]];
            }
        }
    }
    return dp[tar];
}
int coinChangePermRec(vector<int>&arr,int tar)
{
    if(tar == 0)
        return 1;
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= tar)
            ans += coinChangePermRec(arr,tar - arr[i]);
    }
    return ans;
}