#include <bits/stdc++.h>
using namespace std;

const int maxn=1000005;
int N,M,a[maxn],b[maxn],c[maxn];

inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

signed main() {
    for (int T=read(); T--; ) {
        M=read();
        for (int i=1; i<=M; ++i) {
            a[i]=read();
        }
        N=read();
        for (int i=1; i<=N; ++i) {
            b[i]=read();
        }
        for (int i=1,j=1; i<=M||j<=N; ) {
            if (j>N||i<=M&&a[i]<=b[j]) printf("%d",a[i]),++i;
            else printf("%d",b[j]),++j;
            if (!(i>M&&j>N)) putchar(' ');
        }
        puts("");
    }
	return 0;
}
