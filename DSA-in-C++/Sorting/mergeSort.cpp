#include <iostream>
#include <string>
#include <vector>
using namespace std;
void merge(vector<int>&arr,int low,int mid,int high,int &ans)
{
 
    int n1= mid - low + 1;
    int n2 = high - mid;
    vector<int>left(n1);
    vector<int>right(n2);
    for(int i = 0; i < n1;i++)
    {
        left[i] = arr[low + i];
    }
    for(int i = 0; i < n2;i++)
    {
        right[i] = arr[i+mid+1];
    }

    int i = 0,j =0,k =0;
    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k+low] = left[i];
            k++;
            i++;
        }
        else{
            arr[k+low] = right[j];
            ans+=(n1-i);
            k++;
            j++;
        }
    }
    while(i < n1)
    {
        arr[k+low] = left[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        arr[k+low] = right[j];
        k++;
        j++;
    }

}
void mergeSort(vector<int>&arr,int low, int high,int &ans)
{

    if(low < high)
    {
        int mid = (low + high)/2;
        mergeSort(arr,low , mid,ans);
        mergeSort(arr,mid+1,high,ans);
        merge(arr,low,mid, high,ans);
    }
}
int main(int argc , char ** argv)
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n;i++)
    {
        cin>>arr[i];
    }
    int ans = 0;
    mergeSort(arr,0,n-1,ans);
    cout<<"After mergesort: "<<endl;
    for(int i = 0; i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"inversion: "<<ans<<endl;

}