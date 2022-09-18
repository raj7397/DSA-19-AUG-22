#include <iostream>
#include <string>
#include <vector>


using namespace std;

int ceilIndex(vector<int>&tail,int low ,int high, int val)
{
    while(high > low)
    {
        int mid = low + (high - low)/2;
        if(tail[mid] == val && mid == tail.size() -1)
            return mid;
        if(tail[mid] == val && mid +1 != tail.size() && tail[mid+1] != val)
            return mid +1;
        if(tail[mid] >val)
        {
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}

int lis_nlogn(vector<int>&arr)
{
    int n = arr.size();
    vector<int>tail(n);
    int len = 1;
    tail[0] = arr[0];
    for(int i = 1; i < n;i++)
    {
        if(arr[i] > tail[len -1])
        {
            len++;
            tail[len -1] = arr[i];
        }
        else{
            int idx = ceilIndex(tail,0,len -1,arr[i]);
            tail[idx] = arr[i];
        }
    }
    return len;
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
    int val;
    cin>>val;
    int c = ceilIndex(arr,0,n-1,val);
    cout<<"c: "<<c<<endl;
 //   int ans = lis_nlogn(arr);
   // cout<<"ans: "<<ans<<endl;
}