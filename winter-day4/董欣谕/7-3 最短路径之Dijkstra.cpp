#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct edge{
	int to,next,w;
}ed[200001];
int head[100001],cnt=0;
struct priority{
	int dis;
	int id;
	bool operator <(const priority &o) const{
		return dis>o.dis;
	}
};
priority_queue<priority>q;
int dis[100001],vis[100001],ans[100001];
void add(int u,int v,int w){
	ed[++cnt].to=v;
	ed[cnt].next=head[u];
	ed[cnt].w=w;
	head[u]=cnt;
}
void dfs(int x){
	if (ans[x]!=-1){
		dfs(ans[x]);
	}
	else return;
	cout<<ans[x]<<"-->";
}
void dij(int s,int t){
	memset(dis,INF,sizeof dis);
	memset(ans,-1,sizeof ans);
	dis[s]=0;
	q.push((priority){dis[s],s});
	while (!q.empty()){
		priority now=q.top();
		q.pop();
		int u=now.id;
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=head[u];i;i=ed[i].next){
			int v=ed[i].to;
			if (dis[v]>dis[u]+ed[i].w){
				dis[v]=dis[u]+ed[i].w;
				q.push((priority){dis[v],v});
				ans[v]=u;
			}
		}
	}
	dfs(t);
	cout<<t;
	cout<<":"<<dis[t];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m/2;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	int s,t;
	cin>>s>>t;
    if (s==t){
        cout<<s<<"-->"<<t<<":"<<0;
    	return 0;
    }
	dij(s,t);
	return 0;
} 
