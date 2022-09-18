#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int noOfOpn(vector<int>&arr);
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n;i++)
    {
        cin>>arr[i];
    }
    int ans = noOfOpn(arr);
    cout<<"ans: "<<ans<<endl;
}
int noOfOpn(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>>dp(n-1,vector<int>(n-1));
    for(int gap = 0; gap < dp.size();gap++)
    {
        for(int i = 0, j= gap; j < dp[0].size();i++,j++)
        {
            if(gap == 0)
            {
                dp[i][j] = 0;
            }
            else if(gap == 1)
            {
                dp[i][j] = arr[i] * arr[j] * arr[j+1];
            }
            else{
                int minVal = INT_MAX;
                for(int k1 = 1 , k2 = gap; k1 <= gap; k1++,k2--)
                {
                    int left =  dp[i][j-k2];// dimension of this matrix arr[i] * arr[j-k2 +1]
                    int right = dp[i+k1][j];//dimnesion of this matrix arr[i+k1] * arr[j+1];
                    //here arr[j-k2+1] and arr[i+k1] is same i,e. common dimension in matrix multiplication.
                    int mult = arr[i] * arr[j+1] * arr[i+k1];
                    minVal = min(minVal, left + right + mult);
                }
                dp[i][j] = minVal;
            }
        }
    }
    return dp[0][dp[0].size()-1];
}