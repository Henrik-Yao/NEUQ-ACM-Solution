#include<bits/stdc++.h>
using namespace std;
#define inf 65535
int point[inf][2];//搜到的点 
int path[inf][2];//最短路径上的点 
int mp[1001][1001];
int ans[1001][1001];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int m,n,startx,starty,endx,endy,cnt,sum;//cnt记录当前搜到的点的数量，sum最短路径上的数量 
void dfs(int x,int y){
	if(x==endx&&y==endy){
		for(int i=0;i<cnt;i++){
			path[i][0]=point[i][0];
			path[i][1]=point[i][1];
			sum=cnt;
		}
			return;
	}
	for(int i=0;i<4;i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx<1||dy<1||dx>m||dy>n||mp[dx][dy]==-1||ans[dx][dy]<=ans[x][y]+mp[dx][dy]){
			continue;
		}
		point[cnt][0]=dx;
		point[cnt][1]=dy;
		ans[dx][dy]=ans[x][y]+mp[dx][dy];
		cnt++;
		dfs(dx,dy);
		cnt--;
	}
} 
int main(){
	cin>>m>>n;
	cin>>startx>>starty>>endx>>endy;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int data;
			cin>>data;
			mp[i][j]=data;
		}
	}
	for(int i=1;i<=m-2;i++)
		for(int j=1;j<=n-2;j++)
			ans[i][j]=inf;
			ans[startx][starty]=mp[startx][starty];
			point[cnt][0]=startx;
			point[cnt][1]=starty;
			cnt++;
			dfs(startx,starty);
			for(int i=sum-1;i>=0;i--){
				cout<<"("<<path[i][0]<<" "<<path[i][1]<<")";
			}
			cout<<endl;
}
