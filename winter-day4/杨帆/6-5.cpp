#include <bits/stdc++.h>
using namespace std;
int n,m,sx,sy,tx,ty,cnt,cnt2;
int mt[1005][1005],l[1000005][2],path[1000005][2],ans[1005][1005];
int dx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y);
bool is(int x,int y);

int main()
{
	cin >> m >> n;
	cin >> sx >> sy >> tx >> ty;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mt[i][j];
		}
	}
	n -= 2; m -= 2;
	for (int i = 1;i <= n; i++){
		for (int j = 1;j <= m; j++)
		{
			ans[i][j] = 65535;
		}
	}
	ans[sx][sy] = mt[sx][sy];
	l[++cnt][0] = sx; l[cnt][1] = sy;
	dfs(sx,sy);
	for(int i=cnt2; i>=1; i--){
		printf("(%d %d)",path[i][0],path[i][1]);
	}
	printf("\n");
	return 0;
}

void dfs(int x,int y){
	if (x == tx && y == ty){
		for (int i=1; i<=cnt; i++){
			cnt2 = cnt;
			path[i][0] = l[i][0];
			path[i][1] = l[i][1];
		}
		return;
	}
	for (int i=0; i<4; i++){
		int tx = x + dx[i][0];
		int ty = y + dx[i][1];
		if (!is(tx,ty) || mt[tx][ty] == -1 || ans[tx][ty] <= ans[x][y] + mt[tx][ty]) continue;
		ans[tx][ty] = ans[x][y] + mt[tx][ty];
		l[++cnt][0] = tx; l[cnt][1] = ty;
		dfs(tx,ty);
		cnt--;
	}
	return;
}

bool is(int x,int y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
