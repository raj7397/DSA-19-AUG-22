#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;


int paint(int A, int B, vector<int> &C) {
    int mod = 10000003;
    
    int low = INT_MIN;
    int  high  = 0;
    for(int i = 0; i < C.size();i++)
    {
        int temp = (((long)C[i] % mod) *((long)B % mod))%mod;
        cout<<"temp: "<<temp<<endl;
        //long long temp = (long long )C[i] *(long long) B;
        //long temp = (C[i] * B) %mod;
        low = max(low, temp);
        high = (high +temp) %mod;
    }
    cout<<"low: "<<low<<endl;
    cout<<"high: "<<high<<endl;
   // low = (low*B)%mod;
    //high = (high*B)%mod;
    while(low < high)
    {
        int  mid = low + (high - low)/2;
        cout<<"low: "<<low<<" mid: "<<mid<<" high: "<<high<<endl;
        int noOfPart = 1;
        int  currSum = 0;
        for(int i = 0; i < C.size();i++)
        {
            int temp = (currSum % mod + (((long)C[i] % mod)*((long)B %mod))%mod)%mod;
           // long long temp = currSum + (long long)C[i]*(long long)B;
            if(temp <= mid)
            {
                currSum = temp;
                //mid = currSum+C[i]
            }
            else{
                currSum = ((long)C[i]%mod * (long)B%mod)%mod;
                noOfPart++;
            }
        }
        cout<<"currSum: "<<currSum<<endl;
        if(noOfPart > A)
            low = mid+1;
        else{
            high = mid;
        }
    }
    int ans = low %mod;
    cout<<"ans: "<<ans<<endl;
    return (int)ans;
}
int main(int argc, char ** argv)
{
    cout<<"size of long: "<<sizeof(long)<<" long long "<<sizeof(long long)<<endl;
    int A;
    int B;
    cin>>A>>B;
    int n;
    cin>>n;
    vector<int>C(n);
    for(int i = 0; i < n;i++)
    {
        cin>>C[i];
    }
    cout<<"paint: "<<paint(A,B,C)<<endl;

}
