#include <bits/stdc++.h>
using namespace std;


inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

signed main() {
	unsigned long long Ans[100];
	memset(Ans,0x3f,sizeof Ans);
	Ans[1]=2;
	for (int i=2; i<=35; ++i) {
        Ans[i]=3*Ans[i-1]+2;
	}
    int x;
    while (~scanf("%lld",&x)) {printf("%lld\n",Ans[x]);}
	return 0;
}
