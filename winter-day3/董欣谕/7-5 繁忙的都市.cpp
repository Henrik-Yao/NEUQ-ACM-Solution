#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct edge{
	int from;
	int to;
	int w;
}ed[200001];
int fa[10001];
int cnt=0,n,e,m;
void add(int u,int v,int w){
	ed[++cnt].from=u;
	ed[cnt].to=v;
	ed[cnt].w=w;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if (x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	fa[xx]=yy;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>e;
	memset(ed,0,sizeof ed);
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	sort(ed+1,ed+1+cnt,cmp);
	int c=0,maxn=-1;
	for (int i=1;i<=cnt;i++){
		if (find(ed[i].from)!=find(ed[i].to)){
			maxn=max(maxn,ed[i].w);
			merge(ed[i].from,ed[i].to);
			c++;
		}
		if (c==n-1) break;
	}
	cout<<c<<" "<<maxn<<endl;
	
	return 0;
} 
