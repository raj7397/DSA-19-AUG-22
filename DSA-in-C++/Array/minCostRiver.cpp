#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
using namespace std;

int minCost(vector<int>&arr)
{
    sort(arr.begin(),arr.end());
    if(arr.size() == 1)
    {
        return arr[0];
    }
    int ans = 0;
    for(int i = arr.size() - 1; i >=1 ;i = i-2)
    {
        if(i == 1)
        {
            ans+=max(arr[i],arr[i-1]);
        }
        else if(i ==2)
        {
            ans+=arr[i]+arr[i-1]+arr[i-2];
        }
        else{
            int f1 = arr[0] + arr[i] + arr[0] + arr[i-1];
            int f2 = arr[0] + arr[i] + arr[1] + arr[1];
            ans+=min(f1,f2);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n;i++)
    {
        cin>>arr[i];
    }
    cout<<"cost: "<<minCost(arr)<<endl;
}