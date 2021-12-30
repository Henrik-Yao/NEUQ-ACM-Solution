#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,m;
int stx,sty,ex,ey;
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
int dis[1001][1001],vis[1001][1001],g[1001][1001];
struct Node{
	int x=-1,y=-1;
}pre[1001][1001];
vector<Node>res;
map<pii,pii>mp;
struct node{
	int x,y,value;
	bool operator <(const node&o)const {
		return value>o.value;
	}
};
void dij(){
	memset(dis,INF,sizeof dis);
	priority_queue<node>q;
	dis[stx][sty]=g[stx][sty];
	q.push((node){stx,sty,dis[stx][sty]});
	while (!q.empty()){
		node now=q.top();
		q.pop();
		int x=now.x;
		int y=now.y;
		if (x==ex&&y==ey) break;
		if (vis[x][y]) continue;
		vis[x][y]=1;
		for (int i=0;i<4;i++){
			int xx=x+dirx[i];
			int yy=y+diry[i];
			if (g[xx][yy]==-1||xx<0||xx>=n||yy<0||yy>=m) continue;
			if (dis[xx][yy]>dis[x][y]+g[xx][yy]){
				dis[xx][yy]=g[xx][yy]+dis[x][y];
				pre[xx][yy].x=x;
				pre[xx][yy].y=y;
				q.push((node){xx,yy,dis[xx][yy]});
			}
		}
	}
}
void dfs(int x,int y){
	int pre_x=pre[x][y].x;
	int pre_y=pre[x][y].y;
	if(pre_x!=-1&&pre_y!=-1) res.push_back({pre_x,pre_y}),dfs(pre_x,pre_y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>stx>>sty>>ex>>ey;
	memset(g,INF,sizeof g);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			cin>>g[i][j];
		}
	dij();
	dfs(ex,ey);
	cout<<"("<<ex<<" "<<ey<<")";
	for (auto s:res){
		cout<<"("<<s.x<<" "<<s.y<<")";
	}
	return 0;
} 
