#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct edge{
	int to,next,w;
}ed[201];
int n,e;
int head[101],cnt=0,dis[101],vis[101];
void add(int u,int v,int w){
	ed[++cnt].to=v;
	ed[cnt].next=head[u];
	ed[cnt].w=w;
	head[u]=cnt;
}
int dij(int s){
	memset(dis,INF,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	priority_queue<pii>q;
	q.push({dis[s],s});
	while (!q.empty()){
		int u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=head[u];i;i=ed[i].next){
			int v=ed[i].to;
			if (dis[v]>dis[u]+ed[i].w){
				dis[v]=dis[u]+ed[i].w;
				q.push({dis[v],v});
			} 
		}
	}
	int sum=0;
	for (int i=0;i<n;i++)
		sum+=dis[i];
	return sum;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	while (cin>>n>>e){
		memset(ed,0,sizeof ed);
		memset(head,0,sizeof head);
		cnt=0;
		for (int i=1;i<=e;i++){
			int u,v,w;
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,w);
		}
		int ans,minn=INF;
		for (int i=0;i<n;i++){
			int temp=dij(i);
			if (temp<minn){
				minn=temp;
				ans=i;
			}
			//cout<<temp<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
