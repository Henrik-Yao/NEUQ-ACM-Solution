#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5; 

int N,C,w[maxn],v[maxn],f[maxn];

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

int main() {
    while (~scanf("%d%d",&N,&C)) {
        memset(f,0,sizeof f);
        for (int i=1; i<=N; ++i) scanf("%d",&w[i]);
        for (int i=1; i<=N; ++i) scanf("%d",&v[i]);
        for (int i=1; i<=N; ++i) {
            for (int j=C; j>=w[i]; --j)
                f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
        printf("%d\n",f[C]);
    }
	return 0;
}
