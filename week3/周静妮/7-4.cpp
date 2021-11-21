#include<bits/stdc++.h> 
using namespace std;
#define g 1005
#define h 1000005
int a[g][g];
int visited[1005][1005];
int ans;
int dr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int n;
int temp[h][2];
void dfs(int x,int y) 
{
    ans++;
    temp[ans][0]=x;
    temp[ans][1]=y;
    visited[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nowx=x+dr[i][0];
		int nowy=y+dr[i][1];
		if(((a[nowx][nowy])^(a[x][y]))&visited[nowx][nowy]==0&&nowx>=1&&nowx<=n&&nowy>=1&&nowy<=n)
		{
			dfs(nowx,nowy);
		}
	}
}

int main()
{
    memset(visited,0,sizeof(visited));
	int m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		scanf("%1d",&a[i][j]);
	for(k=0;k<m;k++)
	{
		ans=0;
		int x,y;
		scanf("%d%d",&x,&y);
        if(visited[x][y] > 0)
		{
            cout<<visited[x][y]<<endl;
            continue;
        }
		dfs(x,y);
		for(j = 1;j <= ans;j++)
		{
            visited[temp[j][0]][temp[j][1]] = ans;
        }
		printf("%d\n",ans);
	}
	return 0;
}
