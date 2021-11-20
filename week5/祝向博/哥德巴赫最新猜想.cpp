#include <bits/stdc++.h>
using namespace std;

const int maxn=10000005;

bool np[maxn];
int p[maxn],cnt=0;

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

bool check(int x) {
    for (int i=1; i<=cnt&&p[i]*p[i]<=x; ++i) {
        if (x%p[i]==0) return 0;
    }
    return 1;
}

int main() {
	np[1]=1;
	for (int i=2; i<=maxn; ++i) {
		if (!np[i]) p[++cnt]=i;
		for (int j=1; j<=cnt&&i*p[j]<=maxn; ++j) {
			np[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
    for (int T=read(); T--; ) {
        int N=read();
        bool flg=check(N);
        if (flg) puts("1");
        else if (N%2==0||check(N-2)) puts("2");
        else puts("3");
    }
	return 0;
}

