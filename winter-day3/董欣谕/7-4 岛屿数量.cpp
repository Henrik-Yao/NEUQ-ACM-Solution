#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int g[101][101],vis[101][101];
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
int n,m;
void dfs(int x,int y){
	for (int i=0;i<4;i++){
		int xx=x+dirx[i];
		int yy=y+diry[i];
		if (xx<1||xx>n||yy<1||yy>m) continue;
		if (vis[xx][yy]||g[xx][yy]==0) continue;
		vis[xx][yy]=1;
		dfs(xx,yy);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>g[i][j];
	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if(!vis[i][j]&&g[i][j]==1) {
				cnt++;
				vis[i][j]=1;
				dfs(i,j);
			}
		}
	cout<<cnt;
	return 0;
} 
