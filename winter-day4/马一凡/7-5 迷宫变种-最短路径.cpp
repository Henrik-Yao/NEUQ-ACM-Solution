#include <bits/stdc++.h>
using namespace std;

int n,m,sx,sy,tx,ty;
int sum,sum2;
int mp[1005][1005],l[1000005][2],path[1000005][2],vs[1005][1005];
int vec[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool in(int x, int y){
	return (x>=1 && x<=n && y>=1 && y<=m);
}

void dfs(int x,int y){
	if(x == tx && y == ty){
		for (int i=1; i <= sum; i++){
			sum2 = sum;
			path[i][0] = l[i][0];
			path[i][1] = l[i][1];
		}
		return;
	}
	for (int i=0; i < 4; i++){
		int tx = x+vec[i][0];
		int ty = y+vec[i][1];
		if(!in(tx,ty) || mp[tx][ty] == -1 || vs[tx][ty] <= vs[x][y]+mp[tx][ty]) 
			continue;
		vs[tx][ty] = vs[x][y]+mp[tx][ty];
		l[++sum][0] = tx; 
		l[sum][1] = ty;
		dfs(tx,ty);
		sum--;
	}
	return;
}

int main(){
	cin >> m >> n;
	cin >> sx >> sy >> tx >> ty;
	for (int i=0; i < n; i++){
		for (int j=0; j < m; j++){
			cin >> mp[i][j];
		}
	}
	n = n-2; 
	m = m-2;
	for(int i=1; i <= n; i++){
		for (int j=1; j <= m; j++){
			vs[i][j] = 65535;
		}
	}
	vs[sx][sy] = mp[sx][sy];
	l[++sum][0] = sx; 
	l[sum][1] = sy;
	dfs(sx,sy);
	for(int i = sum2;i >= 1; i--){
		printf("(%d %d)",path[i][0],path[i][1]);
	}
	cout << endl;
	return 0;
}

//本题采用深度优先搜索，在搜的过程中要记录路径。注意题中输入的入口和出口坐标为除去四面墙后的矩阵的横纵坐标
