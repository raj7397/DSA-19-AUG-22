#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>


using namespace std;

void printCatalon(int n);
int main()
{
    int n;
    cin>>n;
    printCatalon(n);
}
void printCatalon(int n)
{
    vector<int>dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <=n ;i++)
    {
        int left = 0;
        int right = i -1;
        while(left <= i-1)
        {
            dp[i] += dp[left]*dp[right];
            left++;
            right--;
        }
    }
    for(int i = 0; i <= n; i++)
        cout<<dp[i]<<" ";
    cout<<endl;
}