#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1000005;
int N,M,K,S,T,fa[maxn],x[maxn],y[maxn];
bool Safe[maxn];

inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

inline int getfa(int x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}

signed main() {
    M=read(),N=read(),K=read();
    for (int i=1; i<=M; ++i) Safe[i]=0,fa[i]=i;
    for (int i=1; i<=N; ++i) Safe[read()]=1;
    for (int i=1; i<=K; ++i) {
        x[i]=read(),y[i]=read();
    }
    S=read(),T=read();
    Safe[S]=1;
    for (int i=1; i<=K; ++i) {
        if (Safe[x[i]]&&Safe[y[i]]) fa[getfa(x[i])]=getfa(y[i]);
    }
    if (getfa(S)==getfa(T)) printf("The city %d can arrive safely!",T);
    else if (!Safe[T]) printf("The city %d is not safe!",T);
    else printf("The city %d can not arrive safely!",T);
	return 0;
}
