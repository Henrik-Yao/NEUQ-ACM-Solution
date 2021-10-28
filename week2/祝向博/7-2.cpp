#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

bool vis[maxn];
int N,M,K,Np,tot,Sum,v[maxn],in[maxn],lnk[maxn];
struct edge {
	int v,nxt;
} e[maxn<<1];

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

inline void add_edge(int x,int y) {
	e[++tot]={y,lnk[x]},lnk[x]=tot;
	e[++tot]={x,lnk[y]},lnk[y]=tot;
	in[x]++,in[y]++;
}

inline void Do(int x,int Add) {
	for (int k=lnk[x]; k; k=e[k].nxt) in[e[k].v]+=Add;
}


int main() {
	N=read(),M=read();
	for (int i=1; i<=M; ++i) add_edge(read(),read());
	for (int i=1; i<=N; ++i) vis[i]=0;
	K=read();
	for (int i=1; i<=K; ++i) {
		Np=read(),Sum=0;
		for (int j=1; j<=Np; ++j) vis[v[j]=read()]=1,Do(v[j],-1);
		for (int j=1; j<=N; ++j) if (vis[j]||in[j]==0) ++Sum;
		puts(Sum==N?"YES":"NO");
		for (int j=1; j<=Np; ++j) vis[v[j]]=0,Do(v[j],1);
	}
	return 0;
}
