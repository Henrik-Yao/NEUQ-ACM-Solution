#include <bits/stdc++.h>
using namespace std;
bool is[20005];
int n,e;
int tu[55][2];
void dfs(int x)
{
    if(is[x])
    return ;
    is[x]=1;
    cout<<x<<" ";

    int end=n;
    for(int i=0;i<e;i++)
    {
        if(tu[i][0]==x&&!is[tu[i][1]])
        end=min(tu[i][1],end);
    }
    if(end!=n)
    dfs(end);
}
int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++)
        for(int j=0;j<2;j++)
            cin>>tu[i][j];
    dfs(0);
    for(int i=1;i<n;i++)
    if(!is[i])dfs(i);
    return 0;
}
