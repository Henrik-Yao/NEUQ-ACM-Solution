#include<iostream>
using namespace std;
bool map[2001][2001],mark[2001][2001];
int flag=1;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void search(int i,int j)
{
    mark[i][j]=flag;
    for(int p=0;p<4;p++)
    {
        int x=i+dx[p];
        int y=j+dy[p];
        if(map[x][y]==1 && mark[x][y]==0) search(x,y);
    }
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>map[i][j];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(map[i][j]==1 && mark[i][j]==0)
            {
                search(i,j);
                flag++;
            }
        }
    }
    cout<<flag-1;
    return 0;
}