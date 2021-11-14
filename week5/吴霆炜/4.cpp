#include <bits/stdc++.h>
using namespace std;
#define maxn 2010

int s[maxn][maxn];
int ans;
int n,m;
int walk[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

void dfs(int x,int y){
	s[x][y] = 0;
	for(int k = 0;k < 4;k++){
		int u = x + walk[k][0];
		int v = y + walk[k][1];
		if(u >= 1 && u <= n && v >= 1 && v <= m && s[u][v] == 1)
		dfs(u,v);
	}
}

int main(){
	cin>>n>>m;
	int i,j;
	for(i = 1;i <= n;i++)
		for(j = 1;j <= m;j++)
			cin>>s[i][j];
	for(i = 1;i <= n;i++){
		for(j = 1;j <= m;j++){
			if(s[i][j] == 1){
				dfs(i,j);
				ans++;
			}
		}
}
	cout<<ans;
	return 0;	
}