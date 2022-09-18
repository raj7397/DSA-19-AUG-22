#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>


using namespace std;
class myComp{
    public:
        bool operator()(vector<int>a,vector<int>b)
        {
            if(a[0] != b[0])
            {
                if(a[0] < b[0])
                    return true;
                return false;
            }
            else{
                if(a[1]<= b[1])
                    return true;
                return false;
            }
        }
};
int main()
{
    vector<vector<int>>arr= {{8,1},{1,2},{4,3},{3,4},{5,5},{2,6},{6,7},{7,8}};
    sort(arr.begin(),arr.end(),myComp());
    int n = arr.size();
    vector<int>lis(n);
    lis[0] = 1;
    for(int i = 1; i < n;i++)
    {
        int max_lis = 0;
        for(int j= 0; j < i;j++)
        {
            if(arr[j][1] <= arr[i][1])
            {
                max_lis = max(max_lis, lis[j]);
            }
        }
        lis[i] = max_lis + 1;
    }
    int len = INT_MIN;
    for(int i = 0; i < n;i++)
    {
        len = max(len, lis[i]);
    }
    cout<<"len: "<<len<<endl;
   
}