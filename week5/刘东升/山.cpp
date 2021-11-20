#include<bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};//定义上下移动的四种形式 
const int dy[4]={0,-1,0,1};
int m,n,ans=0,fx,fy;
void dfs(int x,int y); 
const int M=2001;
bool mou[M][M];//地图 
bool judge[M][M];//判断 
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mou[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mou[i][j]==0||judge[i][j]==1) continue;//如果是平地或者已经被标记则跳过 
			dfs(i,j);//开始遍历搜索大山 
			ans++;//山的答案加一 
		}
	}
	cout<<ans;
}
void dfs(int x,int y)
{
	judge[x][y]=1;//标记大山的地方 
	for(int i=0;i<4;i++)//寻找四种移动操作 
	{
		fx=dx[i]+x;//移动 
		fy=dy[i]+y;
		if(fx<1||fx>m||fy<1||fy>n) continue;//超过了边界则跳过 
		if(judge[fx][fy]==1||mou[fx][fy]==0) continue;//如果是空地或者已经被标记则跳过 
		dfs(fx,fy);//继续遍历 
	}
}
