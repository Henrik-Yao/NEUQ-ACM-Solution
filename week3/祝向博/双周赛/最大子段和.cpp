#include <bits/stdc++.h>
using namespace std;

int N,Ans,now,x;

inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

signed main() {
    N=read(),Ans=0,now=0;
    for (int i=1; i<=N; ++i) {
        x=read();
        now+=x;
        if (now>Ans) Ans=now;
        if (now<0) now=0;
    }
    printf("%d\n",Ans);
	return 0;
}
