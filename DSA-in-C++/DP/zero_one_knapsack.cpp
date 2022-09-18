#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int maxProfit(vector<int>&values, vector<int>&weight,int total, int idx);
int maxProfitTabu(vector<int>&values,vector<int>&weight,int total);
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
    int ans = maxProfit(values,weight,total,0);
    cout<<" ans: "<<ans<<endl;
    int ans2= maxProfitTabu(values, weight , total);
    cout<<" ans2: "<<ans2<<endl;
}

int maxProfitTabu(vector<int>&values,vector<int>&weight,int total)
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
                dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j - weight[i-1]]); 
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
          //  cout<<" i: "<<i<<" j: "<<j<<endl;
        }
        
    }

    return dp[n][total];
}
int maxProfit(vector<int>&values, vector<int>&weight,int total, int idx)
{
    if(total == 0)
        return 0;
    if(idx >= values.size())
        return 0;


    int incl = 0;
    if(weight[idx] <= total)
    {
        incl = values[idx] + maxProfit(values,weight,total - weight[idx], idx +1);
    }
    int excl = maxProfit(values,weight,total,idx+1);
    return max(incl, excl);
}