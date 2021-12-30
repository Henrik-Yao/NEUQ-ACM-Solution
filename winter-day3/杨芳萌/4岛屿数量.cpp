#include<bits/stdc++.h>
using namespace std;
const int N = 2333;
int n,m,cnt,sum,mapp[N][N],vis[N][N];
int dx[4]= {1,0,-1,0};
int	dy[4]= {0,1,0,-1};
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

void dfs(int x, int y) {
	if(x<=0||x>n||y<=0||y>m||vis[x][y]==1) return;
	vis[x][y] = 1;
	for(int i=0; i<4; i++) {
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(mapp[xx][yy]==1) dfs(xx,yy);
	} 
}

int main() {
	read(n), read(m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			read(mapp[i][j]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			if(mapp[i][j]==1&&vis[i][j]==0) {
				cnt++;
				dfs(i,j);
			}
		}
	printf("%d\n",cnt);
	return 0;
}
