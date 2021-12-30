#include<bits/stdc++.h>
using namespace std;
const int MIN = -0x7fffffff;
int n,m,a,b,cnt,first[2333],dist[2333],r[2333],path[2333];
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
	if(s!=e) printf("%d-->",s-1);
	else printf("%d",s-1);
}

int main(){
	read(n),read(m);
	m /= 2;
	for(int i=1; i<=m; i++) {
		int s,e,w;
		read(s), read(e), read(w);
		s++, e++;
		addedge(s,e,w);
		addedge(e,s,w);
	}
	read(a), read(b);
	if(a==b) {
		printf("%d-->%d:0\n",a,b);
		return 0;
	}
	a++, b++;
	dijkstra(a);
	out(b,b);
	printf(":%d\n",dist[b]);
    return 0;
}

