#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int solve(int n,int k);

int main()
{
    int n,k;
    cin>>n>>k;
    int ans = solve(n,k);
    cout<<ans<<endl;
}
int solve(int n,int k)
{
    if(n == 0 || k == 0 || n < k)
        return 0;
    vector<vector<long>>dp(n+1,vector<long>(k+1));
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1;j <=k;j++)
        {
            if(j == 1)
            {
                dp[i][j] = 1;
            }
            else if(i < j)
            {
                dp[i][j] = 0;
            }
            else if(i == j)
            {
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j-1] + j * dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}