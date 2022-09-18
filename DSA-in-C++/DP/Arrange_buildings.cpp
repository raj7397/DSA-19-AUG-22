#include <iostream>
#include <string>

#include <vector>

using namespace std;
int arrange_building(int n);
int main()
{
    int n;
    cin>>n;
    int ans = arrange_building(n);
    cout<<"ans: "<<ans<<endl;
}
int arrange_building(int n)
{
    int b = 1;
    int sp = 1;
    for(int i = 2;i <= n;i++)
    {
        int new_b = sp;
        int new_sp = b + sp;
        sp = new_sp;
        b = new_b;
    }
    int ans= b + sp;
    return ans * ans;
}
