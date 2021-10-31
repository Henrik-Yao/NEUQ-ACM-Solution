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
	Ans[1]=1;
	Ans[2]=3;
	Ans[3]=5;
	Ans[4]=9;
	Ans[5]=13;
	for (int i=6; i<=64; ++i) {
		for (int j=1; j<=i-1; ++j) {
			Ans[i]=min(Ans[i],Ans[j]*2+(1ll<<i-j)-1);
		}
	}
    int x;
    while (~scanf("%d",&x)) {printf("%lld\n",Ans[x]);}
	return 0;
}
