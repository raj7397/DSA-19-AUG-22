#include <iostream>
#include <vector>
#include <climits>

using namespace std;
bool isTargetSumRec(vector<int>&arr,int ,int );
bool isTargetSumMemo(vector<int>&arr,int sum,int n,vector<vector<bool>>&dp);
bool isTargetSumTabu(vector<int>&arr,int sum);
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n;i++)
    {
        cin>>arr[i];
    }
    int sum ;
    cin>>sum;
    cout<<"Array is : "<<endl;
    for(int i = 0; i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"sum: "<<sum<<endl;
    bool ans = isTargetSumRec(arr,sum,n);
    cout<<"ans: "<<ans<<endl;
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    bool ans1 = isTargetSumMemo(arr,sum,n,dp);
    cout<<" ans memo:  "<<ans1<<endl;
    bool ans2 = isTargetSumTabu(arr,sum);
    cout<<"ans2: "<<ans2<<endl;
}
bool isTargetSumTabu(vector<int>&arr,int sum)
{
    int n = arr.size();
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i = 0; i < n+1;i++)
    {
        for(int j = 0; j < sum + 1;j++)
        {
            if(i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if(i == 0)
            {
                dp[i][j] = false;
            }
            else if(j == 0)
            {
                dp[i][j] = true;
            }
            else{
                if(dp[i-1][j] == true)
                {
                    dp[i][j] = true;
                }
                else{
                    int curr = arr[i-1];
                    if(j >= curr)
                    {
                        if(dp[i-1][j - curr] == true)
                        {
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j] = false;
                        }
                    }
                }
            }
        }
    }
    return dp[n][sum];

}
bool isTargetSumMemo(vector<int>&arr,int sum,int n,vector<vector<bool>>&dp)
{
    cout<<" sum: "<<sum<<" n: "<<n<<endl;
    if(sum == 0)
    {
        dp[n][sum] = true;
        return dp[n][sum];
    }
    if(n == 0)
    {
        dp[n][sum] = false;
        return false;
    }
    if(dp[n][sum] == true)
        return true;
    if(arr[n-1] <= sum)
    {
        bool ra = isTargetSumMemo(arr,sum - arr[n-1],n-1,dp);
        if(ra == true)
        {
            dp[n][sum] = true;
            return dp[n][sum];
        }
    }
    bool ra=  isTargetSumMemo(arr, sum, n-1,dp);
    dp[n][sum] = ra;
    return dp[n][sum];
}
bool isTargetSumRec(vector<int>&arr,int sum,int n)
{
    cout<<" sum: "<<sum<<" n: "<<n<<endl;
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(arr[n-1] <= sum)
    {
        bool ra = isTargetSumRec(arr,sum - arr[n-1],n-1);
        if(ra == true)
            return true;
    }
    return isTargetSumRec(arr, sum, n-1);
}