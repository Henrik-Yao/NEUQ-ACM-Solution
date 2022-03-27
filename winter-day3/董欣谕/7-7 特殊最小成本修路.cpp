#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct edge{
	int to;
	int from;
	int w;
}ed[101];
int cnt=0,num=0;
int vis[101],n,m,e,fa[101];
void add(int u,int v,int w){
	ed[++cnt].to=v;
	ed[cnt].w=w;
	ed[cnt].from=u;
}
int find(int x){
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	fa[xx]=yy;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	while (cin>>n>>m>>e){
		memset(ed,0,sizeof ed);
		for (int i=0;i<n;i++)
			fa[i]=i;
		for (int i=1;i<=e;i++){
			int u,v,w;
			cin>>u>>v>>w;
			add(u,v,w);
		}
		sort(ed+1,ed+1+cnt,cmp);
		int mincost=0,c=0,num=0;
		for (int i=1;i<=cnt;i++){	
			int u=ed[i].from;
			int v=ed[i].to;
			if (u==m||v==m) {
				if (num>=2) continue;
				merge(u,v);
				mincost+=ed[i].w;
				num++;
				c++;
			}
			if (find(u)!=find(v)){
				merge(u,v);
				mincost+=ed[i].w;
				c++;
			}
			if (c==n-1) break;
		}
		if (c!=n-1) {
			cout<<-1<<endl;
			continue;
		}
		cout<<mincost<<endl;
	}
	return 0;
} 
