#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct edge{
	int next,to;
}ed[20001];
int head[10001],cnt=0,dis[10001],vis[10001];
void add(int u,int v){
	ed[++cnt].to=v;
	ed[cnt].next=head[u];
	head[u]=cnt;
}
int dij(int s,int t){
	priority_queue<pii>q;
	memset(dis,INF,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({dis[s],s});
	while (!q.empty()){
		int u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		for (int i=head[u];i;i=ed[i].next){
			int v=ed[i].to;
			if (dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
	
	return dis[t];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		memset(ed,0,sizeof ed);
		memset(head,0,sizeof head);
		for (int i=1;i<=n;i++){
			int u,k;
			cin>>u>>k;
			for (int j=1;j<=k;j++){
				int v;
				cin>>v;
				add(u,v);
			}
		}
		for (int i=1;i<=m;i++){
			int a,b;
			cin>>a>>b;
			int temp=dij(a,b);
			if (temp!=INF) cout<<temp<<endl;
			else cout<<"connection impossible"<<endl;
		}
	}
	
	return 0;
} 
