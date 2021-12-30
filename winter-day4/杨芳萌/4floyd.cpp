#include<bits/stdc++.h>
using namespace std;
const int N = 233;
const int MIN = -0x7fffffff;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n,m,a,b,cnt,first[N],dist[N],r[N],path[N],d[N][N],ss,tt,maxn;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

struct edge{
	int end,nxt,len;
}bian[123456];

void addedge(int s,int e,int w){
	cnt++;
	bian[cnt].end = e;
	bian[cnt].len = w;
	bian[cnt].nxt = first[s];
	first[s] = cnt;
} 

priority_queue<pair<int,int> > heap;
void dijkstra(int s) {
	memset(dist,0x3f,sizeof(dist));
	dist[s] = 0;
	for(int i=1; i<=n; i++) heap.push(make_pair(-dist[i],i));
	for(int i=1; i<=n; i++) {
		while(r[heap.top().second]) heap.pop();
		int p = heap.top().second;
		r[p] = true;
		heap.pop();
		for(int x=first[p]; x!=0; x=bian[x].nxt){
			int end = bian[x].end;
			int len = bian[x].len;
			int newd = dist[p]+len;
			if(newd<dist[end]){
				dist[end] = newd;
				path[end] = p;
				heap.push(make_pair(-dist[end],end));
			}
		}
	}
}

void out(int s, int e) {
	if(s==0) return;
	out(path[s],e);
	if(s!=e) printf("%d->",s-1);
	else printf("%d",s-1);
}

void clear() {
	memset(r,0,sizeof(r));
	memset(dist,0,sizeof(dist));
	memset(path,0,sizeof(path));	
}

void solve() {
	read(a), read(b);
	a++, b++;
	dijkstra(a);
	if(dist[b]==INF) printf("%d->%d:-1\n",a-1,b-1);
	else {
		out(b,b);
		printf(":%d\n",dist[b]);
	}
	clear();
}

int main(){
	read(n),read(m);
	for(int i=1; i<=m; i++) {
		int s,e,w;
		read(s), read(e), read(w);
		s++, e++;
		addedge(s,e,w);
	}
	
	solve();
	solve();
	
	for(int i=1; i<=n; i++) {
		dijkstra(i);
		for(int j=1; j<=n; j++) {
			if(dist[j]==INF) continue;			
			if(dist[j]>maxn) {
				maxn = dist[j];
				ss = i;
				tt = j;
			}
		}
		clear();
	}
	
	dijkstra(ss);	
	out(tt,tt);
	printf(":%d\n",maxn);
    return 0;
}

