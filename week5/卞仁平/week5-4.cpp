#include <bits/stdc++.h>
using namespace std;
int tu[2002][2002];
bool dfs(int x,int y)
{
    if(tu[x][y]==0)return 0;
    if(tu[x][y])
    {
        tu[x][y]=0;
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
        return 1;
    }
}                         
int main()
{
    int n,m;
    cin>>m>>n;
    memset(tu,0,sizeof(tu));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>tu[i][j];
        }
    }
    int s=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            s+=dfs(i,j);
        }
    }
    cout<<s;
    return 0;

}