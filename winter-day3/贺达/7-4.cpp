#include <bits/stdc++.h>
using namespace std;
#define M 110
int n,m;
int a[M][M];
int cnt=0;

void dfs(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||a[i][j]==0)
    {
        return ;
    }
    a[i][j] = 0;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1)
           {
              dfs(i,j);
              cnt++;
            }
        }
    }
    cout<<cnt;

    return 0;
}

