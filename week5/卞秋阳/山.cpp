#include<bits/stdc++.h>
using namespace std;
int m,n,s=0,fx,fy;
bool a[2010][2010];
bool wyj[2010][2010];
void dfs(int x,int y);
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int main(){
	memset(a,0,sizeof(a));
	memset(wyj,0,sizeof(wyj));
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0||wyj[i][j]==1) continue;
			dfs(i,j);
			s++;
		}
	}
	cout<<s;
	return 0;
}


void dfs(int x,int y)
{
	wyj[x][y]=1;
	for(int i=0;i<4;i++)
	{
		fx=dx[i]+x;
		fy=dy[i]+y;
		if(fx<1||fx>m||fy<1||fy>n) continue;
		if(wyj[fx][fy]==1||a[fx][fy]==0) continue;
		dfs(fx,fy);
	}
}
