#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int max_profit_n3(vector<int>&prices,int k);
int max_profit_n2(vector<int>&prices,int k);

int main()
{
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i = 0; i < n;i++)
    {
        cin>>prices[i];
    }
    int k;
    cin>>k;
    int ans = max_profit_n3(prices,k);
    cout<<" ans: "<<ans<<endl;
    int ans2 = max_profit_n2(prices,k);
    cout<<" ans2: "<<ans2<<endl;
}
int max_profit_n2(vector<int>&prices,int k)
{
    int n = prices.size();
    if(n == 0 || k == 0)
        return 0;
    vector<vector<int>>dp(k+1,vector<int>(n));
    for(int i = 1; i <= k; i++)
    {
        int maxp = INT_MIN;
        for(int j = 1; j < n;j++)
        {
            maxp = max(maxp, dp[i-1][j-1] - prices[j-1]);
            dp[i][j] = max(dp[i][j-1],maxp + prices[j]);

        }
    }
   /* for(int i = 0; i <=k ; i++)
    {
        for(int j = 0; j < n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    return dp[k][n-1];

}
int max_profit_n3(vector<int>&prices,int k)
{
    int n = prices.size();
    if(n == 0 || k == 0)
        return 0;
    vector<vector<int>>dp(k+1,vector<int>(n));
    for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j < n;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else{
                int maxp = 0;
                for(int jj = 0; jj < j;jj++)
               {
                    maxp = max(maxp,dp[i-1][jj]+prices[j]-prices[jj]);
                }
                dp[i][j] = max(maxp, dp[i][j-1]);
            }

        }
    }
   /* for(int i = 0; i <=k ; i++)
    {
        for(int j = 0; j < n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    return dp[k][n-1];

}