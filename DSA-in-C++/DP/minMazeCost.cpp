#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main(int argc, char ** argv)
{
    vector<vector<int>>prices= {
        {0, 1, 4, 2, 8, 2},
        {4, 3, 6, 5, 0, 4},
        {1, 2, 4, 1, 4, 6},
        {2, 0, 7, 3, 2, 2},
        {3, 1, 5, 9, 2, 4},
        {2, 7, 0, 8, 5, 1}
        };

    int n= prices.size();
    int m = prices[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
    for(int i = n-1; i >= 0 ;i-- )
    {
        for(int j = m-1; j >= 0; j--)
        {
            if(i == n-1 && j == m-1)
            {
                dp[i][j] = prices[i][j];
            }
            else if(i == n-1)
            {
                dp[i][j] = dp[i][j+1] + prices[i][j];
            }
            else if(j == m-1)
            {
                dp[i][j] = dp[i+1][j] + prices[i][j];
            }
            else{
                dp[i][j] = min(dp[i][j+1],dp[i+1][j]) + prices[i][j];
            }
        }
       
    }
     cout<<dp[0][0]<<endl;
}