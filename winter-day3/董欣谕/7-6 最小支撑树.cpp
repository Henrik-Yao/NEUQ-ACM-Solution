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
}ed[3001];
int cnt=0,fa[1501];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
void add(int u,int v,int w){
	ed[++cnt].from=u;
	ed[cnt].to=v;
	ed[cnt].w=w;
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		cnt=0;
		memset(ed,0,sizeof ed);
		for (int i=1;i<=n;i++)
			fa[i]=i;
		for (int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			add(u,v,w);
		}
		sort(ed+1,ed+1+cnt,cmp);
		int num=0;
		ll mincost=0;
		for (int i=1;i<=cnt;i++){
			if (find(ed[i].from)!=find(ed[i].to)){
				merge(ed[i].from,ed[i].to);
				mincost+=ed[i].w;
				num++;
			}
			if(num==n-1) break;
		}
		if (num==n-1) cout<<mincost<<endl;
		else cout<<"There is no minimum spanning tree."<<endl;
	}
	return 0;
} 