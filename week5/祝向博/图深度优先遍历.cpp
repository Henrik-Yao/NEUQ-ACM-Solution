#include <bits/stdc++.h>
using namespace std;

const int maxn=20005;
bool vis[maxn];
int N,E,lnk[maxn],tot=0;

struct EDGE {int x,y;} input[maxn];
struct edge {int v,nxt;} e[maxn];
inline bool operator <(EDGE a,EDGE b) {
	return a.x<b.x||a.x==b.x&&a.y>b.y; 
}

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

inline void add_edge(int x,int y) {
	e[++tot]={y,lnk[x]},lnk[x]=tot;
//         printf("%d--->%d\n",x,y);
}

void dfs(int x) {
    vis[x]=1;
	printf("%d ",x);
	for (int k=lnk[x]; k; k=e[k].nxt) {
		if (!vis[e[k].v]) dfs(e[k].v);
	}
}

int main() {
	N=read(),E=read();
	for (int i=1; i<=E; ++i) input[i]={read(),read()};
	sort(input+1,input+1+E);
	for (int i=1; i<=E; ++i) {
		add_edge(input[i].x,input[i].y);
	}
	for (int i=0; i<N; ++i) if (!vis[i]) dfs(i);
	return 0;
}
