#include<bits/stdc++.h>
using namespace std;
int a[200][200];
int b[200][200];
int cou=0;
int n,m;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y){
	if(x<0||y<0||x>=n||y>=m) return;
	for(int i=0;i<4;i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(a[dx][dy]&&!(dx<0||dy<0||dx>=n||dy>=m)){
			a[dx][dy]=0;
			dfs(dx,dy);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		if(a[i][j]){
		a[i][j]=0;
		cou++;
		dfs(i,j);
	}
		}
	}
	cout<<cou;
}
