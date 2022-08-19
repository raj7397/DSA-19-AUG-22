#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>graph[],int u,int parent,int count, int &res,vector<int>&arr,int c)
{
    cout<<"u: "<<u<<endl;
    cout<<(u - 1)<<endl;
    int x = u - 1;
    for(int i = 0; i < arr.size();i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    cout<<"x value: "<<arr[x]<<endl;
    if(arr[u - 1] == 1)
    {
        count++;
    }
    cout<<"arr-1"<<arr[u - 1]<<endl;
    if(count > c)
    {
        return ;
    }
    int child = 0;
    for(int i = 0; i < graph[u].size();i++)
    {
        int v = graph[u][i];
        if(v != parent)
        {
            helper(graph,v,u,count,res,arr,c);
            child++;
        }
            
    }
    if(child == 0)
    {
        if(count <= c)
            res++;
    }
}
int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    vector<int> graph[n + 1];
    
    for(int i = 0; i < B.size();i++)
    {
        int u = B[i][0];
        int v = B[i][1];
        cout<<" u"<<u<<" v: "<<v<<endl;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    int res = 0;
    cout<<"before call: "<<endl;
    for(int i = 0; i < A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    helper(graph,1,-1,count, res,A,C);
    return res;
}


int main(int argc, char **argv)
{
    int n;
    vector<int>A = {1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1};
    vector<vector<int>>B = { {10, 6} ,
  {3, 2 }
  ,{12, 7}
  ,{9, 5}
  ,{2, 1}
  ,{8, 3}
  ,{7, 1}
  ,{4, 2}
  ,{6, 3}
  ,{11, 4}
  ,{5, 3}
  ,{13, 11}};
  int C = 7;
  cout<<"solve: "<<solve(A,B,C)<<endl;

}