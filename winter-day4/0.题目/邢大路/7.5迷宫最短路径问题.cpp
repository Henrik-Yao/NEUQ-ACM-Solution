#include <bits/stdc++.h>
using namespace std;
const int maxn=1000010;
const int inf=65535;
int point[maxn][2];
int pass[maxn][2];
int ditu[1001][1001];
int cost[1001][1001];
int walk[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int m,n,sx,sy,ex,ey,cnt,cnt_ans;
void dfs(int u,int v){
	if(u==ex&&v==ey){
		for(int i = 0;i < cnt;i++){
			pass[i][0]=point[i][0];
			pass[i][1]=point[i][1];
			cnt_ans=cnt;
		}
		return;
	}
	for(int k=0;k<4;k++){
		int xx=u+walk[k][0];
		int yy=v+walk[k][1];
		if(xx<1||xx>m||yy<1||yy>n||ditu[xx][yy]==-1||cost[xx][yy]<=cost[u][v]+ditu[xx][yy])continue;
		point[cnt][0]=xx,point[cnt][1]=yy;
		cost[xx][yy]=cost[u][v]+ditu[xx][yy];
		cnt++;
		dfs(xx,yy);
		cnt--;
	}
}
int main(){
	cin>>m>>n>>sx>>sy>>ex>>ey;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>ditu[i][j];
	}
	}
	for(int i=1;i<=m-2;i++)
		for(int j=1;j<=n-2;j++)
			cost[i][j]=inf;
	cost[sx][sy]=ditu[sx][sy];
	point[cnt][0]=sx,point[cnt][1]=sy;
	cnt++;
	dfs(sx,sy);
	for(int i=cnt_ans-1;i>=0;i--){
		printf("(%d %d)",pass[i][0],pass[i][1]);
	}
	return 0;
}
