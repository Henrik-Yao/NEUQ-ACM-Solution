#include <iostream>
using namespace std;
int a[2001][2001],b[2001][2001],sum=0;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m;
void dfs(int x,int y)
{
    int i;
    for(i=0;i<4;i++)
    {
        int X=x+dx[i],Y=y+dy[i];
        if(X>=0&&Y>=0&&X<=n&&Y<=m&&a[X][Y]==1&&b[X][Y]==0)
        {
            b[X][Y]=1;
            dfs(X,Y);
        }
    }
}
int main()
{
    int i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(a[i][j]==1&&b[i][j]==0)
            {
                dfs(i,j);
                sum++;
            }
            cout<<sum;
}
