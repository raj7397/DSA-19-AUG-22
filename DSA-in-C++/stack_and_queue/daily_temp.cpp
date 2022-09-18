#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void showDailyTemp(vector<int> &temperatures);
int main()
{
    int n;
    cin>>n;
    vector<int>temperatures(n);
    for(int i = 0; i < n;i++)
    {
        cin>>temperatures[i];
    }
    showDailyTemp(temperatures);
}
void showDailyTemp(vector<int> &temperatures)
{
       int n = temperatures.size();
        vector<int>ans(n);
        ans[n-1] = 0;
        stack<int>st;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--)
        {
            while(st.size() > 0 && temperatures[i] > temperatures[st.top()])
            {
                st.pop();
            }
            cout<<" ans: "<<endl;
            ans[i] = st.size() == 0 ? 0 : st.top() - i;
            st.push(i);
        }
        for(int i =0; i < ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
     //   return ans;
        
}

