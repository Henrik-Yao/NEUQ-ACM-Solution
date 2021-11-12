#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[2001][2001],vis[2001][2001];
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
int cnt=0;
void dfs(int x,int y){
	for (int i=0;i<4;i++){
		int xx=x+dirx[i];
		int yy=y+diry[i];
		if (xx<1||xx>n||yy<1||yy>m||vis[xx][yy]||g[xx][yy]!=g[x][y]) continue;
		vis[xx][yy]=cnt;
		dfs(xx,yy);
	}
	}
int main(){
	cin>>n>>m;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>g[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (!vis[i][j]) {
				cnt++;
				if (g[i][j]==1) ans++;
				dfs(i,j);
			}
		}
	cout<<ans;
	return 0;
}
