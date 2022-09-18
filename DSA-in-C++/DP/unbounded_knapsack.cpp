#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int unBoundedmaxProfit(vector<int>&values, vector<int>&weight,int total, int idx);
int unBoundedmaxProfitTabu(vector<int>&values,vector<int>&weight,int total);
int unBoundedMaxProfitOneDTabu(vector<int>&,vector<int>&,int total);
int main()
{
    int n;
    cin>>n;
    vector<int>values(n);
    vector<int>weight(n);
    for(int i = 0; i < n;i++)
    {
        cin>>values[i];
    }
    for(int i = 0; i < weight.size();i++)
    {
        cin>>weight[i];
    }
    int total;
    cin>>total;
    int ans = unBoundedmaxProfit(values,weight,total,0);
    cout<<" ans: "<<ans<<endl;
    int ans2= unBoundedmaxProfitTabu(values, weight , total);
    cout<<" ans2: "<<ans2<<endl;
    int ans3 = unBoundedMaxProfitOneDTabu(values,weight,total);
    cout<<" ans3: "<<ans3<<endl;
}
int unBoundedMaxProfitOneDTabu(vector<int>&values,vector<int>& weight,int total)
{
    vector<int>dp(total+1);
    dp[0] = 0;
    for(int i = 0; i < weight.size();i++)
    {
        for(int j = 1; j <= total; j++)
        {
            if(weight[i] <= j)
            {
                dp[j] = max(dp[j],values[i] + dp[j- weight[i]]);
            }
        }
    }
    return dp[total];
}
int unBoundedmaxProfitTabu(vector<int>&values,vector<int>&weight,int total)
{
    int n = values.size();
    vector<vector<int>>dp(n+1,vector<int>(total + 1));
    for(int i = 0; i < n+1;i++)
    {
        for(int j = 0; j < total + 1; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] == 0;
            }
            else if(weight[i - 1] <= j)
            {
                dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i][j - weight[i-1]]); 
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
          //  cout<<" i: "<<i<<" j: "<<j<<endl;
        }
        
    }

    return dp[n][total];
}
int unBoundedmaxProfit(vector<int>&values, vector<int>&weight,int total, int idx)
{
    if(total == 0)
        return 0;
    if(idx >= values.size())
        return 0;


    int incl = 0;
    if(weight[idx] <= total)
    {
        incl = values[idx] + unBoundedmaxProfit(values,weight,total - weight[idx], idx);
    }
    int excl = unBoundedmaxProfit(values,weight,total,idx+1);
    return max(incl, excl);
}