#include <iostream>
using namespace std;

int d1[4]={1,0,-1,0};
int d2[4]={0,1,0,-1};
int a[2010][2010];
int res=0,n,m;


void dfs(int x , int y)
{
    a[x][y]=0;//艹，写了两个=，浪费半小时
        for(int i=0;i<=3;i++)
        {
            int lx=x+d1[i];
            int ly=y+d2[i];
            if( lx > n || ly > m || ly < 1 || lx < 1 ) continue;
            if(a[lx][ly]==0) continue;
            dfs(lx,ly);
        }
}

int main ()
{
   
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0) continue;   
            dfs(i,j);
            res++;
        }
    }

    cout<<res;

    return 0;
}