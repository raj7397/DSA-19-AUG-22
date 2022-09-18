#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int revenue(int,vector<int>&,vector<int>&,int );
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>pos(n);
    vector<int>rev(n);
    for(int i = 0; i < n;i++)
    {
        cin>>pos[i];
    }
    for(int i = 0; i < n;i++)
    {
        cin>>rev[i];
    }
    int t;
    cin>>t;
    int ans = revenue(m,pos,rev,t);
    cout<<"ans: "<<ans<<endl;
}

int revenue(int m, vector<int>&pos, vector<int>&rev,int t)
{
    int n = pos.size();
    vector<int>dp(n);
    dp[0] = rev[0];
    int omax = rev[0];
    for(int i = 1; i < n;i++)
    {
        int max_val = 0;
        for(int j = 0; j < i; j++)
        {
            if(pos[i] - pos[j] > t)
            {
                max_val = max(dp[j],max_val);
            }
        }
        dp[i] = max_val + rev[i];
        omax = max(omax, dp[i]);
    }
    return omax;
}