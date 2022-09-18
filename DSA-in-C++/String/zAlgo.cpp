#include <iostream>
#include <string>
#include <vector>
using namespace std;

int zAlgo(string patt,string text)
{
//    cout<<"patt: "<<patt<<" text: "<<text<<endl;
    string str = patt + "$"+text;
    int n = str.size();
    vector<int>z(n,0);

    z[0] =0;
    int l = 0;
    int r = 0;
    for(int i = 1; i < str.size();i++)
    {
        if(i > r)
        {
            l = r = i;
            while(r < n && str[r] == str[r-l])
            {
                r++;
            }
                //r++;
            r--;
            z[i] = r-l+1;
        }
        else{
            int k = i -l;
            if(z[k] < r-i+1)
            {
                z[i] = z[k];
            }
            else{
                l =i;
                while(r < n && str[r] == str[r-l])
                {
                    r++;
                }
                    //r++;
                r--;
                z[i] = r-l+1;
            }
        }
    }
    cout<<"string: "<<str<<endl;
    for(int i = 0; i < n;i++)
    {
        cout<<z[i]<<" ";
    }
    cout<<endl;
    int count = 0;
    for(int i = 0; i < str.size();i++)
    {
        if(z[i] == patt.size())
            count++;
    }
    return count;
}

int main(int argc, char **argv)
{
    string patt,text;
    cin>>patt>>text;
    int count = zAlgo(patt,text);
    cout<<"count: "<<count<<endl;
}