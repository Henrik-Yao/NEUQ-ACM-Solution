#include <bits/stdc++.h>
using namespace std;
const int maxn=2010;
int a[maxn][maxn];int vis[maxn][maxn];int m,n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y){
	int tx,ty;
	if(a[x][y]==0||vis[x][y]) return;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		tx=x+dx[i];
		ty=y+dy[i];
		if(tx>=0&&ty>=0&&tx<m&&ty<n) dfs(tx,ty);
	}
	
} 
int main(){
cin>>m>>n;int cnt=0;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		cin>>a[i][j];
	}
}
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		if(vis[i][j]==0&&a[i][j]==1){
		cnt++;
		dfs(i,j);}
	}
}
cout<<cnt;
return 0;

}
