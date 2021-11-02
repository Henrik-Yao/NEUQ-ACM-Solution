#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,d;
struct node {
	int x;
	int y;
} now,start;
int dirx[4]= {1,0,-1,0},diry[4]= {0,1,0,-1};
int g[1010][1010],vis[1010][1010];
int ans[1010*1010];
string str[1010];
void dfs(node state){
	for (int i=0;i<4;i++){
		node next;
		next.x=state.x+dirx[i];
		next.y=state.y+diry[i];
		if (g[next.x][next.y]==-1) continue;
		if (g[next.x][next.y]==g[state.x][state.y]) continue;
		if (vis[next.x][next.y]!=0) continue;
		cnt++;
		vis[next.x][next.y]=d;
		dfs(next);
	}
}
int main() {
	int i,j;
	cin>>n>>m;
	memset(g,-1,sizeof g);
	memset(vis,0,sizeof vis);
	for (i=0; i<n; i++)
		cin>>str[i];
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			g[i+1][j+1]=str[i][j]-'0';
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (!vis[i][j]) {
				d++;
				vis[i][j]=d;
				cnt=1;
				start.x=i;
				start.y=j;
				dfs(start);
				ans[d]=cnt;
			}	
	int x,y;
	while(m--) {
		scanf("%d %d",&x,&y);
		printf("%d\n",ans[vis[x][y]]);
	}
	return 0;
}
