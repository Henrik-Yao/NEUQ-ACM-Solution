#include <bits/stdc++.h>
using namespace std;

long long f[100],N;

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

int main() {
	f[1]=1,f[2]=1;
	for (int i=3; i<=50; ++i) {
		f[i]=f[i-1]+f[i-2];
	}
    f[1]=0;//荒谬，实在是荒谬，我不能理解
	N=read();
	for (int i=1; i<=N; ++i) {
		int x=read();
		printf("%lld\n",f[x]);
	}
	return 0;
}
