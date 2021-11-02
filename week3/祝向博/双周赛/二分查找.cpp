#include <bits/stdc++.h>
using namespace std;

int N,F,Ans,a[10000005];

inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

signed main() {
    N=read(),F=read();
    for (int i=1; i<=N; ++i) a[i]=read();
    if (a[N]<F) {printf("%d\n",N+1);return 0;}
    for (int L=1,R=N,mid; L<=R; ) {
        mid=L+(R-L>>1);
        if (a[mid]>=F) Ans=mid,R=mid-1;
        else L=mid+1;
    }
    printf("%d\n",Ans);
	return 0;
}
