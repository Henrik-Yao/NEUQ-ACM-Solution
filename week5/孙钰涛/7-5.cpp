#include<iostream>
#include<cstring>
using namespace std;
int n,start,m[50001],mark[50001],flag=0;

void dfs(int i)
{
    if(i<0 || i>=n || mark[i]==1) return ;
    if(m[i]==0)
    {
        flag=1;
        return ;
    }
    mark[i]=1;
    dfs(i+m[i]);
    dfs(i-m[i]);
}

int main()
{
    cin>>n;
    memset(m,-1,sizeof(m));
    for(int i=0;i<n;i++)
        cin>>m[i];
    cin>>start;
    dfs(start);
    if(flag==1) cout<<"True";
    else cout<<"False";
    return 0;
}