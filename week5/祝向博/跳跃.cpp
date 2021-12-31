#include <bits/stdc++.h>
using namespace std;

const int maxn=500005;
bool vis[maxn];
int N,st,m[maxn],tot=0;

queue <int> Q;

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

int main() {
	N=read();
	memset(vis,0,sizeof vis);
	for (int i=1; i<=N; ++i) m[i]=read();
	st=read()+1;
	Q.push(st);
	vis[st]=1;
	while (!Q.empty()) {
		int tp=Q.front();Q.pop();
		if (m[tp]==0) {
			puts("True");
			return 0;
		}
		if (tp-m[tp]>0) {
			if (!vis[tp-m[tp]])
				vis[tp-m[tp]]=1,Q.push(tp-m[tp]);
		}
		if (tp+m[tp]<=N) {
			if (!vis[tp+m[tp]])
				vis[tp+m[tp]]=1,Q.push(tp+m[tp]);
		}
	}
	puts("False");
	return 0;
}
