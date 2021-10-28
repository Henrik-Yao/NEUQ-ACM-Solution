#include <bits/stdc++.h>
using namespace std;
int g[25][25],user[25][25];
int dirx[8]= {-1,-1,-1,0,0,1,1,1};
int diry[8]= {-1,0,1,-1,1,-1,0,1};
int n,m,k,l;
int check(int x,int y) {
	int cnt=0;
	for (int i=0;i<8;i++){
		int xx=x+dirx[i];
		int yy=y+diry[i];
		if (xx<0||xx>=n||yy<0||yy>=m) continue;
		if (g[xx][yy]==1) cnt++;
	}
	return cnt;
}
void dfs(int x,int y) {
	if (check(x,y)) return;
	for (int i=0; i<8; i++) {
		int xx=x+dirx[i];
		int yy=y+diry[i];
		if (xx<0||xx>=n||yy<0||yy>=m) continue;
		if (user[xx][yy]==-1&&g[xx][yy]!=1) {
			user[xx][yy]=check(xx,yy);
			dfs(xx,yy);
		}
	}
}
int main() {
	cin>>n>>m>>k>>l;
	int x,y;
	memset(g,0,sizeof g);
	memset(user,-1,sizeof user);
	for (int i=1; i<=k; i++) {
		cin>>x>>y;
		g[x][y]=1;
	}
	while (l--) {
		cin>>x>>y;
		if (user[x][y]!=-1) continue;
		if (g[x][y]==1) {
			cout<<"You lose"<<endl;
			return 0;
		}
		if (!check(x,y)) {
			user[x][y]=0;
			dfs(x,y);
		}
		else user[x][y]=check(x,y);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				cout<<user[i][j]<<" ";
			cout<<endl;
		}		
		int cnt=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (user[i][j]==-1) cnt++;
		if (cnt==k){
			cout<<"You win"<<endl;
			return 0;
		}
		cout<<endl;
	}
	return 0;
}
