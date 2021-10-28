#include <bits/stdc++.h>
using namespace std;

const int maxn=500005;

bool vis[maxn],flg=1;
int N,M,A,B,tot,Ans[maxn],lnk[maxn];

struct {
	int nxt,v;
} e[maxn];

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

inline void add_edge(int x,int y) {
	e[++tot].nxt=lnk[x],e[tot].v=y,lnk[x]=tot;
}

int dfs(int x) {
	if (vis[x]) return Ans[x];
	vis[x]=1;
	for (int k=lnk[x]; k; k=e[k].nxt) {
		Ans[x]+=dfs(e[k].v);
	}
	if (Ans[x]==0) flg=0;
	return Ans[x];
}

int main() {
	N=read(),M=read();
	for (int i=1; i<=M; ++i) {
		int x=read(),y=read();
		add_edge(x,y);
	}
	A=read(),B=read();
	memset(vis,0,sizeof 0);
	vis[B]=1,Ans[B]=1;
	printf("%d ",dfs(A));
	puts(flg?"Yes":"No");
	return 0;
}
